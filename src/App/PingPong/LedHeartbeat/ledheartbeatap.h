// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from LedHeartbeatAP.dff

// AUTO-GENERATED FILE. DO NOT MODIFY.

#ifndef LEDHEARTBEATAP_H
#define LEDHEARTBEATAP_H

// Imt.Base includes.
// Platform.h must be very first include.
#include <Imt.Base.Core.Platform/Platform.h>
#include <Imt.Base.Dff.ActiveParts/ActivePartAbs.h>
#include <Imt.Base.Dff.ActiveParts/PeriodicTimer.h>
#include <Imt.Base.Dff.ActiveParts/PortOutput.h>
#include <Imt.Base.Dff.Runtime/RuntimeProtocolIdentifiers.h>
#include <Imt.Base.Dff.Runtime/RuntimeTimerEvent.h>

// Project includes.
#include "LedHeartbeatAPHandler.h"
#include "LedHeartbeatAPIfc.h"
//#include "PingPongDff/ProtocolIdentifier.h"
#include "ProtocolIdentifier.h"
#include "protocols/ButtonPressEventProtocol.h"

namespace pingPongDff {
namespace pingPong {
namespace ledHeartbeat {

class LedHeartbeatAP : public ActivePartAbs, public LedHeartbeatAPIfc {

public:

    /**
     * Default Constructor.
     */
    LedHeartbeatAP(void);

    /**
     * Destructor.
     */
    virtual ~LedHeartbeatAP(void);

    /**
     * Process a message, run to completion.
     * @see ExecutableIfc::execute
     *
     * Supported protocols:
     *     ButtonPressEventProtocol
     */
    virtual void execute(const uint16_t protocolIdentifier, Deserializer& deserializer);
    virtual PeriodicTimer& getHeartBeatTimerTimer(void);

protected:

    /**
     * see ActivePartAbs.
     */
    virtual void onInitialize(void);

    /**
     * See ActivePartAbs.
     */
    virtual void onStart(void);

private:

    /**
     * Copy Constructor.
     */
    LedHeartbeatAP(const LedHeartbeatAP& other);

    /**
     * Assignment operator.
     */
    LedHeartbeatAP& operator=(const LedHeartbeatAP& other);

    /**
     * TimerSpec handler.
     */
    void handleTimer(const RuntimeTimerEvent& timerEvent);
    PeriodicTimer m_heartBeatTimerTimer;

    /**
     * ActivePart handler.
     */
    LedHeartbeatAPHandler m_handler;

    /**
     * Timer constant for PeriodicTimer m_heartBeatTimerTimer.
     */
    static const uint32_t HEART_BEAT_TIMER_TIMER_INTERVAL_MS = 500U;
};

} // namespace ledHeartbeat
} // namespace pingPong
} // namespace pingPongDff
using pingPongDff::pingPong::ledHeartbeat::LedHeartbeatAP;
#endif // #ifndef LEDHEARTBEATAP_H