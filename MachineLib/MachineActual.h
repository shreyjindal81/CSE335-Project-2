/**
 * \file Gear.h
 *
 * \author Shrey Jindal
 *
 * Class that represents the Actual Machine
 */
#pragma once
#include "Component.h"

class CMachineOwner;

/// the actual machine class
class CMachineActual
{
public:

	CMachineActual() ;

	/**
	Destructor
	*/
	virtual ~CMachineActual() {};

	/// Copy constructor/disabled
	CMachineActual(const CMachineActual&) = delete;

	/// Assignment operator/disabled
	void operator=(const CMachineActual&) = delete;

	/**
	* draws the machine
	* \param graphics that are needed*/
	void Draw(Gdiplus::Graphics* graphics);

	///add component to the list of components
	/// \param c the component pointer
	void AddComponent(std::shared_ptr<CComponent>c) { mComponents.push_back(c); c->SetMachine(this); };

	///sets the frame number
	/// \param frame the frame to be set
	void SetFrameNumber(int frame) {mframe = frame; for (auto c : mComponents)  c->Update(frame); };
	
	///sets the location of the machine
	/// \param x coordinate
	/// \param y coordinate
	virtual void SetLocation(int x, int y);

	/// sets the owner 
	/// \param o the owner
	virtual void SetOwner(CMachineOwner* o) { mOwner = o; };

	/// sets the start frame
	/// \param x the start frame
	virtual void SetStartFrame(int x) { for (auto c : mComponents)  c->SetStartFrame(x); }
private:
	std::vector<std::shared_ptr<CComponent>> mComponents;///<list of components
	int mframe = 0;///<the frame
	int mX = 0; ///<x coord of the location
	int mY = 0; ///<y coord of the location
	CMachineOwner* mOwner;///<the owner pointer
};

