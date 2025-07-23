#ifndef OSAPI_MORTAL_THREAD_H
#define OSAPI_MORTAL_THREAD_H
#include "cmsis_os2.h"

namespace osapi {

class MortalThread
{
    public:
				
				osThreadId_t jobID{NULL};
				osThreadAttr_t workAttributes{0};
			
        MortalThread(int priority, unsigned int stackSize) 
				{ 					
					workAttributes.priority = static_cast<osPriority_t>(osPriorityLow + priority);
					workAttributes.stack_size = stackSize; 
				}
				
        virtual ~MortalThread() { ; }
				
				void kill() 
				{
					killSignal = 1;
					end();
					killSignal = 0;
				}    
				
				static void threadFunction(void* argument) 
				{
					MortalThread* osapiThreadObject = reinterpret_cast<MortalThread*>(argument);
					if (osapiThreadObject) 
					{
						osapiThreadObject->begin();
						while(!osapiThreadObject->killSignal) osapiThreadObject->loop();
					}
				}  
				
				bool run() 
				{
					jobID = osThreadNew(threadFunction, this, &workAttributes);
					if(NULL != jobID){return true;}
					return false;
				}
				
				bool join(unsigned int timeout) 
				{
					osThreadJoin(jobID);
					return true;
				}
				void sleep(unsigned int time) {osDelay(time);}
				
		private:
			sig_atomic_t killSignal{0};
				
    protected:
			virtual void begin(void) = 0;
			virtual void loop(void) = 0;
			virtual void end(void) = 0;
};

} // namespace osapi
 
#endif // OSAPI_MORTAL_THREAD_H