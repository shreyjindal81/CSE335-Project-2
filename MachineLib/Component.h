/**
 * \file Component.h
 *
 * \author Shrey Jindal
 *
 * Class that represents all the components
 */

#pragma once
#include <memory>
#include <vector>
#include "Polygon.h"

class CMachineActual;
class CMachineOwner;

/**
* The Base class for all component */
class CComponent : public CPolygon
{
public:
	/**
	Constructor
	*/
	CComponent() {};

	/**
	Destructor
	*/
	virtual ~CComponent() 
	{
	};

	/// Copy constructor/disabled
	CComponent(const CComponent&) = delete;

	/// Assignment operator/disabled
	void operator=(const CComponent&) = delete;

	///Draw the component
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics) {DrawPolygon(graphics, mX + mMX, mY + mMY);};
	
	/**
	* sets the current frame in animation
	* \param x the frame*/
	virtual void Update(int x) { mCurrFrame = x; };

	/**
	* sets the machine location
	* \param x the coordiate
	* \param y the coordinate*/
	virtual void SetMachineLocation(int x, int y) { mMX = x, mMY = y;};
	
	/**
	* sets the component location
	* \param x the coordiate
	* \param y the coordinate*/
	virtual void SetLocation(int x, int y) { mX = x, mY = y;};


	/**
	* gets the component location
	* \param x the coordiate
	* \param y the coordinate*/
	virtual void GetLocation(int &x, int &y) { x = mX, y = mY; };

	/**
	* gets the machine location
	* \param x the coordiate
	* \param y the coordinate*/
	virtual void GetMachineLocation(int &x, int &y) { x = mMX, y = mMY; };

	/// Sets the machine
	/// \param machine pointer to be set
	virtual void SetMachine(CMachineActual* machine) { mMachine = machine;};

	/// Gets the frame number
	/// \returns current frame
	virtual int GetFrame() { return mCurrFrame; };

	/// Sets the frame number
	/// \param x the number to be set
	virtual void SetFrame(int x) { mCurrFrame = x; };

	/// Sets the Start frame
	/// \param x the number to be set
	virtual void SetStartFrame(int x) { mStartFrame = x;};

	/// Get the frame count
	/// \returns the count
	virtual int GetStartFrame() { return mStartFrame; };


private:
	int mMX = 0;///<x centre of machine
	int mMY = 0;///<y centre of machine
	int mX = 0;///<x centre of component relative to machine
	int mY = 0;///<y centre of component relative to machine
	int mCurrFrame = 0; ///<current frame that the animation is sitting on
	CMachineActual* mMachine; ///< the machine pointer
	int mStartFrame = 0;///<frame at which to start

	
};

