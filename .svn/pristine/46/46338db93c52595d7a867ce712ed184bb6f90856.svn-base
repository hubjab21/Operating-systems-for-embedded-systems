#ifndef OSAPI_THREAD_RTX_H
#define OSAPI_THREAD_RTX_H

#include "osapi_thread_interface.h"
#include "cmsis_os2.h"
#include <stdlib.h>

namespace osapi { 

/** Thread interface implementation for FreeRTOS. */
class Thread : public ThreadInterface
{
    public:
		
		bool isExecuting{false};
		int workPriority{0};
		unsigned int stackDepth{0};
		Joinable joinableState;
		const char* workerName;	
		ThreadState jobState;
		osThreadId_t workID{NULL};
		osThreadAttr_t workAttributes{0};
		int jobSuspended{0};
		
		static void runThreaded(void* argument) 
		{
			Thread* osapiThreadObject = reinterpret_cast<Thread*>(argument);
			if (osapiThreadObject) 
			{
				osapiThreadObject->job();
			}
			osapiThreadObject->jobState = INACTIVE;
			osStatus_t status = osThreadTerminate(osapiThreadObject->workID);
		}
		
        /** Thread constructor.
         *  @param[in] priority thread priority
         *  @param[in] stackSize thread stack size in bytes
         *  @param[in] isJoinable decides if the thread supports join operation or not
         *  @param[in] name optional thread name
         */
        Thread(int priority, unsigned int stackSize, Joinable isJoinable, const char* name = "unnamed")
							 : workPriority(priority), stackDepth(stackSize), joinableState(isJoinable), workerName(name)
				{

					workAttributes.name = workerName;
					workAttributes.priority = static_cast<osPriority_t>(osPriorityLow + workPriority);
					workAttributes.stack_size = stackDepth;
					workAttributes.attr_bits = (isJoinable == JOINABLE ? osThreadJoinable : osThreadDetached);
				
					isExecuting = false;						
        }
        
        /** Virtual destructor required to properly destroy derived class objects. */
        virtual ~Thread() {}
        
        /** Runs the thread.
        *  @retval true if the thread was started successfully, 
        *  @retval false if the thread was not started successfully, or the thread was already running
        */
        virtual bool run() 
				{
					if(!isExecuting)
					{
						workID = osThreadNew(runThreaded, this, &workAttributes);
						
						if(NULL != workID)
						{
							isExecuting = true;
							return true;
						}
						else return false;
					}else return false;
        }

        /** Checks if the thread is running.
        *  @retval true if the thread is running
        *  @retval false if the thread is not running
        */
        virtual bool isRunning() 
				{
					if(isExecuting)
					{
						return true;
					}
					else return false;
        }
        
        /** Waits for the thread to finish executing, with a given timeout.
         *  @param timeout[in] number of milliseconds to wait for the thread to finish executing
         *  @retval true if the thread was successfully joined in the given time
         *  @retval false if the thread was not joined within the given time or the thread is not joinable at all
         */
        virtual bool join(unsigned int timeout) 
				{
					if(JOINABLE == joinableState){
							isExecuting = false;
							osThreadJoin(workID);
							return true;
					}
					else return false;
        }

        /** Checks, if the thread is joinable.
         *  @retval true if the thread is joinable
         *  @retval false if the thread is not joinable
         */
        virtual bool isJoinable() 
				{
			if(JOINABLE == joinableState)
			{
				return true;
			}
			else return false;
        }

        /** Suspends thread execution.
         *  @retval true if the thread was suspended successfully
         *  @retval false if the thread was not suspended for some reason
         */
        virtual bool suspend() 
				{
						if(NULL != workID)
						{
							osStatus_t status = osThreadSuspend(workID);
							if(osOK == status){jobSuspended = 1;}
							if(SUSPENDED == this->getState()){return true;}
							else return false;
						}
						else return false;
        }           

        /** Resumes thread execution.
         *  @retval true if the thread was resumed successfully
         *  @retval false if the thread was not resumed for some reason
         */
        virtual bool resume() {
					if(NULL != workID){
						osStatus_t status = osThreadResume(workID);
						if(osOK == status){jobSuspended = 0;}
						if(SUSPENDED != this->getState()){return true;}
						else return false;
					}
				else return false;
        }           

        /** Sets thread priority
         *  @param[in] priority new thread priority
         *  @retval true if the priority for the thread was set successfully
         *  @retval false if the priority for the thread was not set successfully for some reason
         */
        virtual bool setPriority(int priority) 
				{
					osThreadSetPriority(workID, static_cast<osPriority_t>(osPriorityLow + priority));
					workPriority = priority;
					if(static_cast<osPriority_t>(osPriorityLow + priority) == osThreadGetPriority(workID)){return true;}
          else return false;
        }

        /** Gets the thread priority
         *  @return current thread priority
         */
        virtual int getPriority() {
					return workPriority;
        }
        
        /** Gets thread name
         *  @return name of the thread
         */
        virtual const char* getName() {
					return workerName;
        }

        /** Gets the current state of the thread
         *  @return current state of the thread
         */
virtual ThreadState getState() {
    if (!isExecuting) {
        jobState = INACTIVE;
        return jobState;
    }
    
    if (jobSuspended) {
        jobState = SUSPENDED;
        return jobState;
    }
    
    osThreadState_t temp = osThreadGetState(workID);
    
    if (temp == osThreadRunning) {
        jobState = RUNNING;
    } else if (temp == osThreadReady) {
        jobState = READY;
    } else if (temp == osThreadBlocked) {
        jobState = BLOCKED;
    } else {
        jobState = UNKNOWN;
    }
    
    return jobState;
}


        /** Gets the total size of the stack assigned for this thread
         *  @return total stack size in number of bytes
         */
        virtual unsigned int getTotalStackSize() 
				{
					return stackDepth;
        }

        /** Gets the size of the used stack for this thread
         *  @return number of bytes used on the stack
         */
        virtual unsigned int getUsedStackSize() 
				{
					if(!isExecuting) return 0;
					return osThreadGetStackSize(workID) - osThreadGetStackSpace(workID);
        }

    protected:
        /** Delays thread execution for a given time.
         *  @param time[in] number of milliseconds to delay thread execution
         */
				virtual void sleep(unsigned int time) 
				{
					osDelay(time);
        }

};

} // namespace osapi

#endif // OSAPI_THREAD_RTX_H
