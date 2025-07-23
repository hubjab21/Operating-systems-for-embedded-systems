#include <cstdio>
#include <cstdio>
#include "CUnit.h"
#include "FreeRTOS.h"
#include "task.h"
#include "test_osapi.h"
#include "osapi.h"
		
void threadHelloWorld(void* arg) {
    while (1) {
        std::printf("Hello world from %s\n", (char*)arg);
        vTaskDelay(1000);
    }
}

/*
int main(void) {
    std::printf("Hello world\n");
    xTaskCreate(threadHelloWorld, "HELLO1", configMINIMAL_STACK_SIZE, (void*)"thread 1", 3, NULL);
    xTaskCreate(threadHelloWorld, "HELLO2", configMINIMAL_STACK_SIZE, (void*)"thread 2", 3, NULL);
    xTaskCreate(threadHelloWorld, "HELLO3", configMINIMAL_STACK_SIZE, (void*)"thread 3", 3, NULL);
    vTaskStartScheduler();
}
*/
int main(void) {
    std::printf("Running tests\n");
    xTaskCreate(taskOSAPI_TEST, "test", configMINIMAL_STACK_SIZE + 512, NULL, 3, NULL);
    vTaskStartScheduler();
}
        
extern "C" void exit(int status) {
    while(1) { ; }
}

// This function will be called when FreeRTOS detects stack overflow
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName ) {
    std::printf("Stack overflow in task: %s\n", pcTaskName);
    while(1) {
        ;
    }    
}
