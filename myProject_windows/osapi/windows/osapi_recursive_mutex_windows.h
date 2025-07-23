#ifndef OSAPI_RECURSIVE_MUTEX_WINDOWS_H
#define OSAPI_RECURSIVE_MUTEX_WINDOWS_H

namespace osapi {
	
	class RecursiveMutex : public MutexInterface{

	 private:
		CRITICAL_SECTION criticalSection;

	 public:
	 
		~RecursiveMutex() {DeleteCriticalSection(&criticalSection); }

		RecursiveMutex() {InitializeCriticalSection(&criticalSection);}

		virtual bool lock(unsigned int timeout){
        DWORD startTime = GetTickCount();
			while (true) 
			{
				if (TryEnterCriticalSection(&criticalSection)) {return true;}
				if (timeout != INFINITE) 
				{
					DWORD elapsed = GetTickCount() - startTime;
					if (elapsed >= timeout) {return false;}
				}
				Sleep(1);
			}
		}

		virtual void unlock() {LeaveCriticalSection(&criticalSection);}
	};
} // namespace osapi

#endif // OSAPI_RECURSIVE_MUTEX_WINDOWS_H
