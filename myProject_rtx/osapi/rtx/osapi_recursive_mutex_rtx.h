#ifndef OSAPI_RECURSIVE_MUTEX_RTX_H
#define OSAPI_RECURSIVE_MUTEX_RTX_H

#include "osapi_mutex_interface.h"
#include "cmsis_os2.h"

namespace osapi {
	
class RecursiveMutex : public MutexInterface
{
public:
		const osMutexAttr_t Thread_Mutex_attr = {"osapiRecursiveMutex", osMutexRecursive,NULL, 0U};
		osMutexId_t recursiveMutex;
	
RecursiveMutex() {}
	
virtual ~RecursiveMutex() {}
	
virtual bool lock(unsigned int timeout) 
{
		if(NULL == recursiveMutex){recursiveMutex = osMutexNew(&Thread_Mutex_attr);}
				if(NULL != recursiveMutex)
				{
					if(osOK == osMutexAcquire(recursiveMutex, timeout)){ return true;}
					else { return false;}
				}
				else {return false;}
}

virtual void unlock() {
		if(NULL == recursiveMutex){recursiveMutex = osMutexNew(&Thread_Mutex_attr);}
		if(NULL != recursiveMutex){osMutexRelease(recursiveMutex);}
}
};

} // namespace osapi

#endif // OSAPI_RECURSIVE_MUTEX_RTX_H
