#ifndef OSAPI_MUTEX_RTX_H
#define OSAPI_MUTEX_RTX_H

#include "osapi_mutex_interface.h"
#include "cmsis_os2.h"


namespace osapi {

class Mutex : public MutexInterface
{
public:
	
osMutexId_t  osMutex;

Mutex() {}
	
virtual ~Mutex() {}
		
virtual bool lock(unsigned int timeout) 
{
			 if(NULL == osMutex){osMutex = osMutexNew(NULL);}
			 if(NULL != osMutex)
			 {
					if(osOK == osMutexAcquire(osMutex, timeout)) return true;
					else{ return false;}
			 }
			 else{ return false;}
}
	
virtual void unlock() 
{
				if(NULL == osMutex){osMutex = osMutexNew(NULL);}
				if(NULL != osMutex){osMutexRelease(osMutex);}
}
};

} // namespace osapi

#endif // OSAPI_MUTEX_RTX_H
