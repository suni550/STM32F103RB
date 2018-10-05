// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Version. 1.6
//
// Generated by DffGenerator (Version 1.00.0)
// Generated from ButtonIrqHandlerIRQAP.dff

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
#include "PingPong/ButtonIrqHandler/ButtonIrqHandlerIrqAP.h"

// Diagnostics.h must be last include.
#include <Imt.Base.Core.Diagnostics/Diagnostics.h>

// Forward declaration for extern weak definition
extern "C" void EXTI13(void);

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace unitTestPingPongDff {

/**
 * Tests the ButtonIrqHandlerIrqAP.
 */
[TestClass]
public ref class TestButtonIrqHandlerIrqAP : MockTestBase {

public:

    [TestInitialize()]
    void setUp() {
        m_pTestObject = &ExtButtonIrqIrqAP::Instance;
        // Initialize.
        m_pTestObject->initialize();
        // Start.
        m_pTestObject->start();
    }

    [TestCleanup()]
    void tearDown() {
        m_pTestObject = NULL;
    }

    [TestMethod]
    [TestCategory("Software UNIT")]
    [Description("Interrupt entry counter as verified.")]
    void testButtonIrqHandlerIrqAP_IrqHandler() {
        Assert::IsTrue(0 == RuntimeMock::getSingle().m_appIsrEntryCounter);
        Assert::IsTrue(0 == RuntimeMock::getSingle().m_appIsrEntryCounter);
        EXTI13();
        Assert::IsTrue(1 == RuntimeMock::getSingle().m_appIsrEntryCounter);
        Assert::IsTrue(1 == RuntimeMock::getSingle().m_appIsrEntryCounter);
    }

private:

    ButtonIrqHandlerIrqAP* m_pTestObject;
};

} // namespace unitTestPingPongDff