// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch. 
// SW guideline: Technote Coding Guidelines Ver. 1.4

// Main include
#include "PowerSaveIdleCallback.h"

// Project includes

PowerSaveIdleCallback::PowerSaveIdleCallback()
{
}

PowerSaveIdleCallback::~PowerSaveIdleCallback() {
}

void PowerSaveIdleCallback::onIdle(void) {
    // Attention: We are woken up periodically by the SysTick interrupt (1ms)
    //            So it's hard to determine that the WFI instruction is working.
    //            -> Verify with oscilloscope and debug pins
#ifndef WIN32
    // in order to calculate the CPU load we need the busy idle
    #ifndef RUNTIME_STATISTICS
        // Data barrier
        asm volatile ("DSB"); // place a DSB to ensure that all data is synchronized before entering "wait for interrupt"
        asm volatile ("ISB"); // place a ISB to ensure that all instructions are synchronized before "wait for interrupt"
        asm volatile ("WFI"); // Enter sleep state and request wait for interrupts 
    #endif //RUNTIME_STATISTICS
#endif //WIN32
}

