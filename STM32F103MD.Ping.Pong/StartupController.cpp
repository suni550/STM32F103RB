// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Ver. 1.4

// Main include
#include "StartupController.h"
//Imt.Base includes 
#include <Imt.Base.Dff.Runtime/RuntimeInterrupts.h> 

//Project includes
#include "SystemInitializationDriver.h"
#include "PowerSaveIdleCallback.h"
#include "PingPongApc.h"
//#include <Imt.Base.HAL.STM32F103MD/SystemPeripherals_GPIO.h>
#include "..\PingPongDff\out\src\App\PingPong\LedHeartbeat\LedHeartbeatAPHandler.h"
//C:\Users\bobbala\work\PingPongTask_Dff_V2\PingPongDff\out\src\App\PingPong\LedHeartbeat
int main(void)
{
// Processor, clock and pin config
    SystemInitializationDriver::initCpuClock();
    SystemInitializationDriver::initPeripheralClocks();
    SystemInitializationDriver::initPinConfig();
    
    //Initialize peripherals 
     SystemInitializationDriver::initTimer();
    //Initialize the external interrupts 
     SystemInitializationDriver::initInterrupts();
     
      // Initialize run time before the application gets initialized (so that ActiveParts can register themselves in initialize)
    PowerSaveIdleCallback idleCallback;
    SystemInitializationDriver::initRuntime(&idleCallback);
    
    
    //Initialize the application
    static PingPongAPC s_app; 
    s_app.initialize(); 
    s_app.start();

    SystemInitializationDriver::UART_TransmitData();

    // Enable the interrupts just before the scheduler starts
    RuntimeInterrupts::interruptEnable();
    SystemInitializationDriver::enableInterrupts();
 

    // Scheduler endless loop
    RuntimeCore::start();
    
  return 0;
}