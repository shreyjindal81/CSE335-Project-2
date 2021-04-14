/**
 * \file Gear.h
 *
 * \author Shrey Jindal
 *
 * Class that represents the mouse
 */
#pragma once
#include "Component.h"
#include "Motor.h"

///the mouse class
class CMouse :
    public CComponent
{
public:
    /**
    *constructor
    */
    CMouse();

    ///destructor
    virtual ~CMouse() {};

    /// Copy constructor/disabled
    CMouse(const CMouse&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMouse&) = delete;

    /// starts the motor
    virtual void StartMotor() { mMotor->Start(); }

    /// sets the initial position
    /// \param x coordinate
    /// \param y coordinate
    virtual void SetInitialPosition(int x, int y) { mStartX = x; mStartY = y; mX = x; mY = y; }

    /// sets the final position
    /// \param x coordinate
    /// \param y coordinate
    virtual void SetFinalPosition(int x, int y) { mEndX = x; mEndY = y;}

    ///makes the necessary updates based on frame
    /// \param x the frame
    virtual void Update(int x);

    /**
    * draws the component
    * \param graphics that are needed*/
    virtual void Draw( Gdiplus::Graphics* graphics);

    ///Sets the motor
    /// \param motor to be set
    virtual void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; };

    /// sets the speed of mouse
    /// \param x the speed to be set
    virtual void SetSpeed(int x) { speed = x; };

    /// gets the speed of mouse
    /// \returns speed
    virtual int GetSpeed() { return speed; };

private:

    int mStartX = 0;///<start position x coordinate
    int mStartY = 0;///<start position y coordinate
    int mEndX = 0;///<end position x coordinate
    int mEndY = 0;///<end position y coordinate
    int mX = 0;///<x coordinate
    int mY = 0;///<y corrdinate
    std::shared_ptr<CMotor> mMotor = nullptr;///<motor
    int speed = -90;///<speed of mouse
    int MouseSize = 76;///<size of mouse

};

