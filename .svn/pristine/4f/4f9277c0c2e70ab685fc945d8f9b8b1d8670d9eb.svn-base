#ifndef OSAPI_RECURSIVE_MUTEX_FREERTOS_H
#define OSAPI_RECURSIVE_MUTEX_FREERTOS_H

#include "osapi_mutex_interface.h"
#include "FreeRTOS.h"
#include <csignal>

namespace osapi {
	
	class RecursiveMutex : public MutexInterface{
		
	 public:

		SemaphoreHandle_t recursiveMutex;
	 
		/** Virtual destructor required to properly destroy derived class objects. */
		virtual ~RecursiveMutex() { }

		RecursiveMutex(){
			recursiveMutex = xSemaphoreCreateRecursiveMutex();
		}
		
		/** Locks the recursiveMutex. In case the recursiveMutex is already locked, it may cause the calling thread to block,
		 *  waiting for the recursiveMutex to become unlocked, for the maximum given timeout.
		 *  @param[in] timeout maximum number of milliseconds allowed to block the calling thread while waiting for recursiveMutex to become unlocked
		 *  @retval true if the recursiveMutex was successfully locked (calling thread owns now this lock)
		 *  @retval false if the recursiveMutex was not locked within the given time
		 */
		virtual bool lock(unsigned int timeout){
			 if(NULL != recursiveMutex){
					if(pdTRUE == xSemaphoreTakeRecursive(recursiveMutex, timeout)) return true;
					else return false;
			 }
			 else return false;
		}

		/** Unlocks the recursiveMutex */
		virtual void unlock(){
				if(NULL != recursiveMutex){
					xSemaphoreGiveRecursive(recursiveMutex);
				}
		}

	};
	
} // namespace osapi


#endif // OSAPI_RECURSIVE_MUTEX_FREERTOS_H