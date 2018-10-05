// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from TokenEventProtocol.dff

// AUTO-GENERATED FILE. DO NOT MODIFY.

#ifndef TOKENEVENTPROTOCOL_H
#define TOKENEVENTPROTOCOL_H

// Imt.Base includes.
// Platform.h must be very first include.
#include <Imt.Base.Core.Platform/Platform.h>
#include <Imt.Base.Core.Serialization/Deserializer.h>
#include <Imt.Base.Core.Serialization/SerializableIfc.h>
#include <Imt.Base.Core.Serialization/Serializer.h>

// Project includes.
#include "ProtocolIdentifier.h"

namespace pingPongDff {
namespace protocols {

/**
 * Protocol for TokenEvent
 */
class TokenEventProtocol : public SerializableIfc {

public:

    /**
     * Protocol Identifier.
     */
    static const uint16_t IDENTIFIER = ProtocolIdentifier::TOKEN_EVENT;

    /**
     * Maximum serialized data bytes.
     */
    static const uint32_t MAX_SERIALIZED_SIZE_BYTES = 4U;

    /**
     * Default Constructor.
     */
    explicit TokenEventProtocol(void);

    /**
     * Custom Constructor.
     */
    explicit TokenEventProtocol(const uint32_t TokenCounter);

    /**
     * Copy constructor.
     */
    TokenEventProtocol(const TokenEventProtocol& other);

    /**
     * Constructor from deserializer.
     */
    explicit TokenEventProtocol(Deserializer& deserializer);

    /**
     * Destructor.
     */
    virtual ~TokenEventProtocol(void);

    /**
     * Assignment operator.
     */
    TokenEventProtocol& operator=(const TokenEventProtocol& other);

    /**
     * Equality operator.
     */
    bool operator==(const TokenEventProtocol& right) const;

    /**
     * Inequality operator.
     */
    bool operator!=(const TokenEventProtocol& right) const;

    /**
     * @see SerializableIfc
     */
    //lint -sem(pingPongDff::protocols::TokenEventProtocol::deserialize,initializer) // Members initialized in deserializer function
    virtual void deserialize(Deserializer& deserializer);

    /**
     * @see SerializableIfc
     */
    virtual void serialize(Serializer& serializer) const;

    // Setter for TokenCounter
    void setTokenCounter(const uint32_t TokenCounter);

    // Getter for TokenCounter
    uint32_t getTokenCounter(void) const;

private:

    // Instance members
    uint32_t m_TokenCounter;
};

} // namespace protocols
} // namespace pingPongDff
using pingPongDff::protocols::TokenEventProtocol;
#endif // #ifndef TOKENEVENTPROTOCOL_H
