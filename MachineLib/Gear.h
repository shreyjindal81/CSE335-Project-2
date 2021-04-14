/**
 * \file Gear.h
 *
 * \author Shrey Jindal
 *
 * Class that represents all gears
 */

#pragma once
#include <memory>
#include "Component.h"
#include "Polygon.h"

using namespace std;
/**
* the gear class
*/
class CGear :
    public CComponent
{
public:
    /**
    *constructor
    * \param r radius of gear
    * \param t number of teeth
    * \param rot the speed
    */
    CGear(int r, int t, float rot);  

    ///destructor
    virtual ~CGear() {};

    /// Copy constructor/disabled
    CGear(const CGear&) = delete;

    /// Assignment operator/disabled
    void operator=(const CGear&) = delete;

    /**
    * draws the component
    * \param graphics that are needed*/
    virtual void Draw(Gdiplus::Graphics* graphics);

    /// Rotates the component based on frame
    /// \param x the frame number
    virtual void Rotate(int x);

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

    /// Gets the rotation speed
    /// \returns mRotation the speed
    virtual float GetRotationSpeed() { return mRotation; };

    /// Set the rotation speed
    /// \param x the speed
    virtual void SetRotationSpeed(float x) { mRotation = x; };

    /// Sets a starting angle
    /// \param x the angle
    virtual void SetStartAngle(float x) { mStartAngle = x; SetRotation(mStartAngle);};

private:
    int mRadius = 0;///<radius
    int mTeeth = 0;///<teeth count
    float mRotation = 0;///<rotation speed
    float mStartAngle = 0; ///<starting anlge


};

