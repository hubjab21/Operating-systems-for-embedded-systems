#ifndef OSAPI_THREAD_WINDOWS_H
#define OSAPI_THREAD_WINDOWS_H

#include "windows.h"
#include <stdlib.h>
#include "windows_proc_info.h"
// #include "semphr.h"

namespace osapi
{

    /** Thread interface implementation for Windows. */
    class Thread : public ThreadInterface
    {
    public:
        bool isExecuting{false};
        int workPriority{0};
        unsigned int stackDepth{0};
        Joinable joinableState;
        const char *workerName;
        ThreadState jobState;
        HANDLE jobHandle{NULL};
        WindowsProcInfo procInfo;
        DWORD jobSuspendCount{1};
        SYSTEM_THREAD_INFORMATION taskInfo{0};
        BOOL jobSuspended{0};

        static void threadFunction(void *argument)
        {
            Thread *osapiThreadObject = reinterpret_cast<Thread *>(argument);
            if (osapiThreadObject){osapiThreadObject->job();}
            osapiThreadObject->jobState = INACTIVE;
        }

        Thread(int priority, unsigned int stackSize, Joinable isJoinable, const char *name = "unnamed")
            : workPriority(priority), stackDepth(stackSize), joinableState(isJoinable), workerName(name)
        {
            isExecuting = false;
        }

        /** Virtual destructor required to properly destroy derived class objects. */
        virtual ~Thread() {}

        virtual bool run()
        {
            if (!isExecuting)
            {
                jobHandle = CreateThread(NULL, stackDepth, (LPTHREAD_START_ROUTINE)threadFunction, this, 0, NULL);
                if (NULL != jobHandle)
                {
                    SetThreadPriority(jobHandle, workPriority);
                    isExecuting = true;
                    return true;
                }
                else {return false;}
            }
            else {return false;}
        }

        virtual bool isRunning()
        {
            if (isExecuting) {return true;}
            else {return false;}
        }

        virtual bool join(unsigned int timeout)
        {
            if (JOINABLE == joinableState && isExecuting)
            {
                if (WAIT_OBJECT_0 == WaitForSingleObject(jobHandle, timeout))
                {
                    isExecuting = false;
                    return true;
                }
            }
            return false;
        }

        virtual bool isJoinable()
        {
            if (JOINABLE == joinableState) {return true;}
            else {return false;}
        }

        virtual bool suspend()
        {
            if (NULL != jobHandle)
            {
                jobSuspendCount = SuspendThread(jobHandle);
                if (SUSPENDED == this->getState()) {return true;}
                else {return false;}
            }
            else {return false;}
        }

        virtual bool resume()
        {
            if (NULL != jobHandle)
            {
                jobSuspendCount = ResumeThread(jobHandle);
                if (SUSPENDED != this->getState()) {return true;}
                else {return false;}
            }
            else {return false;}
        }

        virtual bool setPriority(int priority)
        {
            workPriority = priority;
            SetThreadPriority(jobHandle, workPriority);
            if (workPriority == GetThreadPriority(jobHandle)) {return true;}
            else {return false;}
        }

        virtual int getPriority(){ return workPriority;}


        virtual const char *getName() {return workerName;}

        virtual ThreadState getState()
        {
            if (!isExecuting)
            {
                jobState = INACTIVE;
                return jobState;
            }

            procInfo.Capture();
            SYSTEM_PROCESS_INFORMATION *processInformation = procInfo.FindProcessByPid(GetCurrentProcessId());
            SYSTEM_THREAD_INFORMATION *threadInformation = procInfo.FindThreadByTid(processInformation,
                                                                                    GetThreadId(jobHandle));
            procInfo.IsThreadSuspended(&taskInfo, &jobSuspended);

            if (jobSuspended || !jobSuspendCount)
            {
                jobState = SUSPENDED;
            }
            else if (threadInformation->ThreadState == StateRunning)
            {
                jobState = RUNNING;
            }
            else if (threadInformation->ThreadState == StateReady)
            {
                jobState = READY;
            }
            else if (threadInformation->ThreadState == StateWait)
            {
                jobState = BLOCKED;
            }
            else
            {
                jobState = UNKNOWN;
            }

            return jobState;
        }

        virtual unsigned int getTotalStackSize()
        {
            static DWORD stackSize = 0;
            if (NULL != jobHandle)
            {
                procInfo.Capture();
                stackSize = procInfo.getTotalStackSize(jobHandle);
            }
            return (unsigned int)stackSize;
        }

        virtual unsigned int getUsedStackSize(){return this->getTotalStackSize();}

    protected:

        virtual void sleep(unsigned int time) {Sleep(time);}
    };

} // namespace osapi

#endif // OSAPI_THREAD_WINDOWS_H
