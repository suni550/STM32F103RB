// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from TokenEventProtocol.dff

// AUTO-GENERATED FILE. DO NOT MODIFY.

#include "TokenEventProtocol.h"

// Default Constructor.
TokenEventProtocol::TokenEventProtocol(void) :
    m_TokenCounter(0U)
{
    // Nothing to do.
}

// Custom Constructor.
TokenEventProtocol::TokenEventProtocol(const uint32_t TokenCounter) :
    m_TokenCounter(TokenCounter)
{
    // Nothing to do.
}

// Copy constructor.
TokenEventProtocol::TokenEventProtocol(const TokenEventProtocol& other) :
    m_TokenCounter(other.m_TokenCounter)
{
    // Nothing to do.
}

// Constructor from deserializer.
TokenEventProtocol::TokenEventProtocol(Deserializer& deserializer) :
    m_TokenCounter(0U)
{
    TokenEventProtocol::deserialize(deserializer);
}

// Destructor.
TokenEventProtocol::~TokenEventProtocol(void) {
    // Nothing to do.
}

// Assignment operator.
TokenEventProtocol& TokenEventProtocol::operator=(const TokenEventProtocol& other) {
    if (&other == this) {
        return *this;
    }
    m_TokenCounter = other.m_TokenCounter;
    return *this;
}

// Equality operator.
//lint -save
//lint -estring(1960, *side effects on right hand of logical operator*) // MISRA C++ 2008 Required Rule 5-14-1 // Justification: No side effects
bool TokenEventProtocol::operator==(const TokenEventProtocol& right) const {
    return (this->m_TokenCounter == right.m_TokenCounter);
}
//lint -restore

// Inequality operator.
bool TokenEventProtocol::operator!=(const TokenEventProtocol& right) const {
    return !(*this == right);
}

// @see SerializableIfc
void TokenEventProtocol::deserialize(Deserializer& deserializer) {
    deserializer >> m_TokenCounter;
}

// @see SerializableIfc
void TokenEventProtocol::serialize(Serializer& serializer) const {
    serializer << m_TokenCounter;
}

void TokenEventProtocol::setTokenCounter(const uint32_t TokenCounter) {
    m_TokenCounter = TokenCounter;
}

uint32_t TokenEventProtocol::getTokenCounter(void) const {
    return m_TokenCounter;
}
