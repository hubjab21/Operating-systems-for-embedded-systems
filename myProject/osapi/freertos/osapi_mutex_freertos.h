#ifndef OSAPI_MUTEX_FREERTOS_H
#define OSAPI_MUTEX_FREERTOS_H

#include "osapi_mutex_interface.h"
#include "FreeRTOS.h"

namespace osapi {
	
	class Mutex : public MutexInterface{
		
	 public:

		SemaphoreHandle_t mutex;
	 
		/** Virtual destructor required to properly destroy derived class objects. */
		virtual ~Mutex() { }

		Mutex(){
			mutex = xSemaphoreCreateMutex();
		}
		
		/** Locks the mutex. In case the mutex is already locked, it may cause the calling thread to block,
		 *  waiting for the mutex to become unlocked, for the maximum given timeout.
		 *  @param[in] timeout maximum number of milliseconds allowed to block the calling thread while waiting for mutex to become unlocked
		 *  @retval true if the mutex was successfully locked (calling thread owns now this lock)
		 *  @retval false if the mutex was not locked within the given time
		 */
		virtual bool lock(unsigned int timeout){
			 if(NULL != mutex){
					if(pdTRUE == xSemaphoreTake(mutex, timeout)) return true;
					else return false;
			 }
			 else return false;
		}

		/** Unlocks the mutex */
		virtual void unlock(){
				if(NULL != mutex){
					xSemaphoreGive(mutex);
				}
		}

	};
	
} // namespace osapi


#endif // OSAPI_MUTEX_FREERTOS_H