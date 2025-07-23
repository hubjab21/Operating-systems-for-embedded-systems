#ifndef OSAPI_THREAD_FREERTOS_H
#define OSAPI_THREAD_FREERTOS_H

#include "osapi_thread_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

namespace osapi 
{

/** Thread interface implementation for FreeRTOS. */
class Thread : public ThreadInterface
{
    public:

		const char* workerName;  

		bool isExecuting{false};            
		ThreadState jobState;      

		int workPriority{0};                
		unsigned int stackDepth{0};         

		Joinable joinableState; 

		TaskHandle_t jobHandle{NULL};       
		SemaphoreHandle_t jobSemaphore{NULL};
	
		static void runThreaded(void* argument) 
		{
			Thread* threadInstance = reinterpret_cast<Thread*>(argument);
			if (threadInstance) 
			{
				xSemaphoreTake(threadInstance->jobSemaphore, 0);
				threadInstance->job();
				xSemaphoreGive(threadInstance->jobSemaphore);
				
			}
			threadInstance->jobState = INACTIVE;
			vTaskDelete(NULL); // this is required in FreeRTOS to make sure that the thread does not just simply return
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

					jobSemaphore = xSemaphoreCreateBinary();
					isExecuting = false;							
        }

        /** Virtual destructor required to properly destroy derived class objects. */
        virtual ~Thread() 
				{ 
						vSemaphoreDelete(jobSemaphore);
				}

        /** Runs the thread.
        *  @retval true if the thread was started successfully, 
        *  @retval false if the thread was not started successfully, or the thread was already running
        */
        virtual bool run() 
				{
					if(!isExecuting)
					{
						BaseType_t taskReturn = xTaskCreate(runThreaded, this->getName(), this->getTotalStackSize(), this, this->getPriority(), &jobHandle);
						
						if(pdPASS == taskReturn)
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
					if(isExecuting){
						return true;
					}
					else return false;
        }

        /** Waits for the thread to finish executing, with a given timeout.
         *  @param timeout[in] number of milliseconds to wait for the thread to finish executing
         *  @retval true if the thread was successfully joined in the given time
         *  @retval false if the thread was not joined within the given time or the thread is not joinable at all
         */
        virtual bool join(unsigned int timeout) {
					if(JOINABLE == joinableState){
						xSemaphoreTake(this->jobSemaphore, timeout);
						xSemaphoreGive(this->jobSemaphore);
						isExecuting = false;
						
						return true;
					}
					else return false;
        }

        /** Checks, if the thread is joinable.
         *  @retval true if the thread is joinable
         *  @retval false if the thread is not joinFable
         */
        virtual bool isJoinable() { 
					if(JOINABLE == joinableState){
						return true;
					}
					else return false;
        }

        /** Suspends thread execution.
         *  @retval true if the thread was suspended successfully
         *  @retval false if the thread was not suspended for some reason
         */
        virtual bool suspend() {
						if(NULL != jobHandle){
							vTaskSuspend(jobHandle);
							if(SUSPENDED == this->getState()){
								return true;
							}
							else return false;
						}
						else return false;
        }

        /** Resumes thread execution.
         *  @retval true if the thread was resumed successfully
         *  @retval false if the thread was not resumed for some reason
         */
        virtual bool resume() {
						if(NULL != jobHandle){
							vTaskResume(jobHandle);
							if(SUSPENDED != this->getState()){
								return true;
							}
							else return false;
						}
						else return false;
        }

        /** Sets thread priority
         *  @param[in] priority new thread priority
         *  @retval true if the priority for the thread was set successfully
         *  @retval false if the priority for the thread was not set successfully for some reason
         */
        virtual bool setPriority(int priority) {
            vTaskPrioritySet(jobHandle, priority);
						workPriority = priority;
						if(workPriority == uxTaskPriorityGet(jobHandle)){
							return true;
						}
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

    eTaskState taskState = eTaskGetState(jobHandle);

    if (taskState == eRunning) {
        jobState = RUNNING;
    } else if (taskState == eReady) {
        jobState = READY;
    } else if (taskState == eBlocked) {
        jobState = BLOCKED;
    } else if (taskState == eSuspended) {
        jobState = SUSPENDED;
    } else {
        jobState = UNKNOWN;
    }

    return jobState;
}               

        /** Gets the total size of the stack assigned for this thread
         *  @return total stack size in number of bytes
         */
        virtual unsigned int getTotalStackSize() {
            return stackDepth;
        }

        /** Gets the size of the used stack for this thread
         *  @return number of bytes used on the stack
         */
        virtual unsigned int getUsedStackSize() {
						if(!isExecuting) return 0;
						return ((stackDepth * sizeof(StackType_t)) - (uxTaskGetStackHighWaterMark(jobHandle) * sizeof(StackType_t)));
        }

    protected:

        /** Delays thread execution for a given time.
         *  @param time[in] number of milliseconds to delay thread execution
         */
        virtual void sleep(unsigned int time) {
						vTaskDelay(time / portTICK_PERIOD_MS);
        }

};

} // namespace osapi

#endif // OSAPI_THREAD_FREERTOS_H
