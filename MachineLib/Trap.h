/**
 * \file Gear.h
 *
 * \author Shrey Jindal
 *
 * Class that represents the trap
 */
#pragma once
#include "Component.h"
#include "Winch.h"
///the trap class
class CTrap :
    public CComponent
{
public:
    /**
    *constructor
    */
    CTrap();

    ///destructor
    virtual ~CTrap() {};

    /// Copy constructor/disabled
    CTrap(const CTrap&) = delete;

    /// Assignment operator/disabled
    void operator=(const CTrap&) = delete;

    /**
    * draws the component
    * \param graphics that are needed*/
    virtual void Draw(Gdiplus::Graphics* graphics);

    ///makes the necessary updates based on frame
    /// \param x the frame
    virtual void Update(int x) 
    { 
        if (x > GetStartFrame())
            Rotate(x - GetStartFrame());
        else
            Rotate(0);
        SetFrame(x); 
    };

    /// Rotates the component based on frame
    /// \param x the frame number
    virtual void Rotate(int x);

    /// Sets the location of component
    /// \param x the x coordinate
    /// \param y the y coordinate
    virtual void SetLocation(int x, int y) override;

    /// Sets the machine location
    /// \param x coordinate
    /// \param y coordinate
    virtual void SetMachineLocation(int x, int y) override;

    /// Set the pin speed
    /// \param x the speed to be set
    virtual void SetPinSpeed(int x) { };
    
    /// Set the winch
    /// \param w the winch to be set
    virtual void SetWinch(std::shared_ptr<CWinch> w) { mWinch = w; };
    
private:
    CComponent mTrapStand;///<stand
    CComponent mTrapPin;///<pin
    CComponent mTrapFront;///<front part
    int mPinSpeed = -20;///<pin speed
    std::shared_ptr<CWinch> mWinch = nullptr;///<winch of the machine
};  