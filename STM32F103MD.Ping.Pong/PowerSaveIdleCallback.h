// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch. 
// SW guideline: Technote Coding Guidelines Ver. 1.4

#ifndef POWERSAVEIDLECALLBACK_H
#define POWERSAVEIDLECALLBACK_H

// Must be very first include
#include <Imt.Base.Core.Platform/Platform.h>

// Imt.Base includes
#include <Imt.Base.Dff.Runtime/IdleCallbackIfc.h>

namespace pingpong {

//@{
// Blinky specific IdleCallbackIfc implementation.
// Reduces the power consumption if onIdle is called and the runtime statistics collection process is not enabled.
// @author mguntli
//@}
class PowerSaveIdleCallback : public IdleCallbackIfc {

public:

    //@{
    // Constructor.
    //@}
    explicit PowerSaveIdleCallback();

    //@{
    // Destructor.
    //@}
    virtual ~PowerSaveIdleCallback();

    //@{
    // @see IdleCallbackIfc
    //@}
    virtual void onIdle(void);

private:

    //@{
    // Provide the private copy constructor so the compiler does not generate the default one.
    //@}
    PowerSaveIdleCallback(const PowerSaveIdleCallback& other);

    //@{
    // Provide the private assignment operator so the compiler does not generate the default one.
    //@}
    PowerSaveIdleCallback& operator=(const PowerSaveIdleCallback& other);
};

} // namespace pingpong
using pingpong::PowerSaveIdleCallback;
#endif // #ifndef POWERSAVEIDLECALLBACK_H

