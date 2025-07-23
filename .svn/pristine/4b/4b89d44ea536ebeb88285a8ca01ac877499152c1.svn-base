#ifndef OSAPI_MORTAL_THREAD_H
#define OSAPI_MORTAL_THREAD_H
 
namespace osapi {
	class MortalThread : public Thread
	{			
		public:
			
			MortalThread(int priority, unsigned int stackSize, const char* name = "unnamed") : Thread(priority, stackSize, JOINABLE, name) {}
	 
			virtual ~MortalThread() {}                   
													
			void kill() 
			{
				killSignal = 1;
				end();
			}
													
		private:
		
			sig_atomic_t killSignal{0};
		
			virtual void job(void) 
			{
				begin();
				while(!killSignal) loop();
			}           
			
		protected:
			
			virtual void begin(void) = 0;
			
			virtual void loop(void) = 0;
					
			virtual void end(void) = 0;
	};
} // namespace osapi

 
#endif // OSAPI_MORTAL_THREAD_H