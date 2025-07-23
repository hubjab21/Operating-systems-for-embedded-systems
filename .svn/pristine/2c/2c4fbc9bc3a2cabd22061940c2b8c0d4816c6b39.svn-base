#ifndef OSAPI_MUTEX_WINDOWS_H
#define OSAPI_MUTEX_WINDOWS_H

namespace osapi {
	
	class Mutex : public MutexInterface{
		
	 public:

		HANDLE  mutex;
		DWORD owningThreadId{0};

		virtual ~Mutex() {if (NULL != mutex) {CloseHandle(mutex);}}

		Mutex(){
			mutex = CreateMutex(NULL, FALSE, NULL);
		}

		virtual bool lock(unsigned int timeout)
		{
			DWORD currentThreadId = GetCurrentThreadId();
			if (owningThreadId == currentThreadId) {return false;}
			if(NULL != mutex)
			{
				if(WAIT_OBJECT_0 == WaitForSingleObject(mutex, timeout))
				{
					owningThreadId = currentThreadId;
					return true;
				} 
				else {return false;}
			}
			else{ return false;}
		}

		/** Unlocks the mutex */
		virtual void unlock()
		{
				if(NULL != mutex)
				{
					if (owningThreadId == GetCurrentThreadId()) 
					{
						owningThreadId = 0;
						ReleaseMutex(mutex);
					}
				}
		}
	};
} // namespace osapi
#endif // OSAPI_MUTEX_WINDOWS_H
