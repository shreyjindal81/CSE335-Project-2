/**
 * \file Motor.h
 *
 * \author Shrey Jindal
 *
 * Class that represents all gears
 */

#pragma once
 /**
  * \file Gear.h
  *
  * \author Shrey Jindal
  *
  * Class that represents the motor
  */
#include <memory>
#include "Component.h"
#include "Polygon.h"

/// the motor class
class CMotor :
    public CComponent
{
public:
    /**
    *constructor
    * \param r rotation speed
    */
    CMotor(float r);

    ///destructor
    virtual ~CMotor() {};

    /// Copy constructor/disabled
    CMotor(const CMotor&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMotor&) = delete;

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

    /// Start the machine
    virtual void Start() { mEnabled = true; };
private:
    float mRotation = 0; ///<rotation speed
    CPolygon mBackdrop; ///<backdrop
    bool mEnabled = false;///<enabled flag
};

