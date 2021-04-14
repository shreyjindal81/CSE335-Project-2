/**
 * \file Component.h
 *
 * \author Shrey Jindal
 *
 * Class that represents the winch
 */
#pragma once
#include "Component.h"

///This class representsthe winch
class CWinch :
    public CComponent
{
public:
    /**
    *constructor
    * \param rot rotation speed
    * \param len length of cable
    */
    CWinch(float rot, int len);
    ///destructor
    virtual ~CWinch() {};

    /// Copy constructor/disabled
    CWinch(const CWinch&) = delete;

    /// Assignment operator/disabled
    void operator=(const CWinch&) = delete;

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

    /// changes the enable bool
    /// \param a the bool to be set
    virtual void SetEnabled(bool a) { mEnabled = a; };

private:
    ///rotation speed
    float mRotation;
    CComponent mRope;///<the rope to be drawn
    int mRadius;///<the radius of component
    int mLength = 100;///<the length of rope to be drawn
    bool mEnabled = true;///<enable flag
};
