# RTOS Abstraction Layer (C++ | FreeRTOS | RTX | Windows)

A portable C++ abstraction layer for RTOS systems providing a unified API for threads and synchronization mechanisms across multiple platforms.

---

## Project Overview

This project implements a **multi-platform RTOS abstraction layer**, allowing developers to write embedded applications independent of the underlying operating system.

Supported platforms:

- FreeRTOS
- CMSIS-RTOS2 (RTX)
- Windows (simulation / testing)

The goal is to separate:

- application logic
- OS-specific implementation

---

## Key Concepts

- RTOS abstraction layer
- object-oriented design (OOP)
- interface-based architecture
- portability across platforms
- embedded + desktop compatibility

---

## Architecture

### Interfaces (OS-independent)

- `ThreadInterface`
- `MutexInterface`

Define a common API for all operating systems.

---

### Implementations

#### FreeRTOS

- threads → `xTaskCreate`
- mutex → `xSemaphoreCreateMutex`
- tick → `xTaskGetTickCount`

---

#### RTX (CMSIS-RTOS2)

- threads → `osThreadNew`
- mutex → `osMutexAcquire`
- tick → `osKernelGetTickCount`

---

#### Windows (Simulation Layer)

- threads → `CreateThread`
- mutex → `CreateMutex`
- synchronization → `WaitForSingleObject`
- system time → `GetTickCount`

---

## OS Selection

```cpp
#define OSAPI_USE_FREERTOS
// or
#define OSAPI_USE_RTX
// or
#define _WIN32
```

The correct backend is selected at compile time.

---

## Thread Abstraction

Provides a unified thread interface:

- create / run thread
- suspend / resume
- joinable threads
- priority control
- stack usage monitoring

Example:

```cpp
class MyTask : public osapi::Thread {
    void job() override {
        while(true) {
            // task logic
        }
    }
};
```

---

## Mutex Abstraction

### Standard Mutex

- blocking lock with timeout
- implemented differently per OS

### Recursive Mutex

- allows multiple locks by same thread
- implemented for all platforms

---

## Mortal Thread

Advanced thread type supporting controlled termination.

Lifecycle:

- `begin()`
- `loop()`
- `end()`

Supports safe thread shutdown.

---

## System Time

Unified API:

```cpp
osapi::getSystemTime();
```

Mapped internally to:

- FreeRTOS → tick count
- RTX → kernel tick
- Windows → system time

---

## Technologies

- C++
- FreeRTOS
- CMSIS-RTOS2 (RTX)
- Windows API
- Embedded systems

---

## Features

- multi-RTOS support
- portable API
- object-oriented design
- thread and mutex abstraction
- desktop simulation capability
- scalable architecture

---

## Desktop Simulation (Windows)

The Windows backend allows:

- testing RTOS-like behavior on PC
- debugging without hardware
- faster development cycle

---

## Academic Context

Project created for:

**Operating Systems for Embedded Systems**

at AGH University of Science and Technology.

Topics covered:

- RTOS task management
- synchronization
- abstraction layers
- multi-platform design

---

## Possible Improvements

- support for Zephyr / ThreadX
- unit testing framework
- performance benchmarks
- memory optimization
- documentation generator

---

## 👨‍💻 Author

Hubert Jabłoński

