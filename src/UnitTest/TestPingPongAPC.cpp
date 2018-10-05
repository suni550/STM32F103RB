// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from PingPongAPC.dff

// AUTO-GENERATED FILE. DO NOT MODIFY.

// Imt.Base includes.
// Platform.h must be very first include.
#include <Imt.Base.Core.Platform/Platform.h>
#include <Imt.Base.Dff.ActiveParts.Test/ChannelMockIn.h>
#include <Imt.Base.Dff.ActiveParts.Test/ChannelMockOut.h>
#include <Imt.Base.Dff.ActiveParts.Test/ChannelConnectionVerifier.h>

// Helper includes.
#include "Helpers/ActivePartHelper.h"
#include "Helpers/MockTestBase.h"

// Class under test.
#include "PingPong/PingPongAPC.h"

// Diagnostics.h must be last include.
#include <Imt.Base.Core.Diagnostics/Diagnostics.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace unitTestPingPongDff {

/**
 * Test of the SW UNIT PingPongAPC
 */
[TestClass]
public ref class TestPingPongAPC : MockTestBase {

public:

    [TestInitialize()]
    void setUp() {
        m_pTestObject = new PingPongAPC();
        m_pTestObject->initialize();
        m_pTestObject->start();
    }

    [TestCleanup()]
    void tearDown() {
        delete m_pTestObject;
        m_pTestObject = NULL;
    }

    [TestMethod]
    [TestCategory("Software Integration")]
    [Description("All components are initialized.")]
    void testPingPongAPC_IsInitialized() {
        // Check Activepart Container.
        Assert::IsTrue(m_pTestObject->isInitialized());
        // Check all included Activeparts.
        Assert::IsTrue(m_pTestObject->Ping.isInitialized());
        Assert::IsTrue(m_pTestObject->Pong.isInitialized());
        Assert::IsTrue(m_pTestObject->LedHeartbeat.isInitialized());
    }

    [TestMethod]
    [TestCategory("Software Integration")]
    [Description("All components are started.")]
    void testPingPongAPC_IsStarted() {
        // Check Activepart Container.
        Assert::IsTrue(m_pTestObject->isStarted());
        // Check all included Activeparts.
        Assert::IsTrue(m_pTestObject->Ping.isStarted());
        Assert::IsTrue(m_pTestObject->Pong.isStarted());
        Assert::IsTrue(m_pTestObject->LedHeartbeat.isStarted());
    }

    [TestMethod]
    [TestCategory("Software Integration")]
    [Description("Internal channels are correctly connected to the corresponding output and input ports.")]
    void testPingPongAPC_InternalConnections_Static() {
        // Channel OneToOne ChanButtonIrqHandlerButtonPressToLedHeartbeatPortIn
        Assert::IsTrue(ChannelConnectionVerifier::testChannelOneToOne(m_pTestObject->ButtonIrqHandler.PortOutButtonPress, m_pTestObject->LedHeartbeat.PortIn));
        // Channel OneToOne ChanPongTokenToPingPortIn
        Assert::IsTrue(ChannelConnectionVerifier::testChannelOneToOne(m_pTestObject->Pong.PortOutToken, m_pTestObject->Ping.PortIn));
        // Channel OneToOne ChanPingTokenToPongPortIn
        Assert::IsTrue(ChannelConnectionVerifier::testChannelOneToOne(m_pTestObject->Ping.PortOutToken, m_pTestObject->Pong.PortIn));
    }

    [TestMethod]
    [TestCategory("Software Integration")]
    [Description("External ports are correctly delegated to the corresponding internal ports.")]
    void testPingPongAPC_ExternalPorts_Static() {
        // Nothing to do.
    }

private:

    PingPongAPC* m_pTestObject;
};

} // namespace unitTestPingPongDff
