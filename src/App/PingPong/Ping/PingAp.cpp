// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from PingAP.dff

// AUTO-GENERATED FILE. DO NOT MODIFY.

#include "PingAP.h"

// Imt.Base includes.
#include <Imt.Base.Core.Diagnostics/Diagnostics.h>


// Default Constructor.
PingAP::PingAP(void) :
    ActivePartAbs(RuntimePriority::Prio_16, ExecutableConfiguration("PingAP")),
    PortOutToken(),
    m_handler(*this)
{
    // Nothing to do.
}

// Destructor.
PingAP::~PingAP(void) {
    // Nothing to do.
}

// Process a message, run to completion.
// @see ExecutableIfc::execute
//
// Supported protocols:
//     TokenEventProtocol
void PingAP::execute(const uint16_t protocolIdentifier, Deserializer& deserializer) {
    switch(protocolIdentifier) {
        case ProtocolIdentifier::TOKEN_EVENT: {
                TokenEventProtocol message(deserializer);
                m_handler.handleTokenEvent(message);
            }
            break;
        default:
            // Ignore all other protocols
            ASSERT_DEBUG1(false, "Unknown protocol in PingAP.");
            break;
    }
}

void PingAP::sendTokenEventToToken(const TokenEventProtocol& message) {
    PortOutToken.write(message.IDENTIFIER, &message);
}

// see ActivePartAbs.
void PingAP::onInitialize(void) {
    m_handler.onInitialize();
}

// See ActivePartAbs.
void PingAP::onStart(void) {
    m_handler.onStart();
}