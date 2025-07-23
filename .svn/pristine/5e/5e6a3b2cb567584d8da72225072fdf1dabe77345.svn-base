#include <iostream>
#include <cstdint>
#include <cmath>
#include <windows.h>
#include <map>
#include <chrono>
using namespace std::chrono_literals;

/// The range of numbers to search
const uint64_t numberLimit = 1*1000*1000;

/// Definition of a range of numbers
struct Range {
    uint64_t lower; // lower number range boundary
    uint64_t upper; // upper number range boundary
};

/**
 * Checks if the given number n is prime.
 * @param[in] n number to check
 * @retval true if the number is prime
 * @retval false if the number is NOT prime
*/
bool isPrime(uint64_t n) {
    if (n == 1) return false;

    for (uint64_t div = 2; div <= sqrt(n); div++) {
        if (n % div == 0) {
            return false;
        }
    }

    return true;
}

HANDLE mutex;

uint64_t top = 1;


Range getRange() {

    Range r;

    WaitForSingleObject(mutex, INFINITE);
    r.lower = top;
    top+=1000;
    if(top > numberLimit){
        top = numberLimit;
    }
    r.upper = top;
    ReleaseMutex(mutex);
    return r;
}

/**
 * Definition of a worker thread
 */
DWORD WINAPI primeTestThread(void* args) {
    DWORD count = 0;    // number of primes found by this thread

    Range range;
    do {
        range = getRange();
        for(uint64_t n = range.lower; n < range.upper; n++){
            if(isPrime(n)){
                ++count;
            }
        }
    }while (range.upper < numberLimit);
    {
        /* code */
    }
    
    return count;
}

#define THREAD_COUNT 8
HANDLE threads[THREAD_COUNT];

int main() {

    mutex = CreateMutex(nullptr,false, nullptr);
    // save start time
    auto startTime = std::chrono::system_clock::now();
    // 1. run Thread_COUNT threads primeTestThread
    for(int t = 0; t < THREAD_COUNT; t++){
    threads[t] = CreateThread(nullptr, 0, primeTestThread, nullptr, 0 ,nullptr);   
    }


    // 2.  wait for all threads to finish
    WaitForMultipleObjects(THREAD_COUNT, threads, true, INFINITE);

    // get results
    uint64_t total = 0;
    for (int t = 0; t <THREAD_COUNT; t++){
        DWORD result;
        GetExitCodeThread(threads[t], &result);
        total += result;
    }


    // save end time
    auto endTime = std::chrono::system_clock::now();
    // print duration
    auto duration = endTime - startTime;
    std::cout << "total prime numbers: "<< total << std::endl;
    std::cout << "Duration: " << std::chrono::duration <double, std::milli>(duration).count() << "ms." << std::endl;
    return 0;
}