/**
 * \file MachineDrawable.cpp
 *
 * \author Shrey Jindal
 */
#include "pch.h"
#include "MachineDrawable.h"
#include "MachineDlg.h"
#include "MachineFactory.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
 * \param name The drawable name 
 * \param machine The ptr to the machine to be adapted*/
CMachineDrawable::CMachineDrawable(const std::wstring& name, shared_ptr<CMachine>machine) : CDrawable(name)
{
	mMachine = machine;
	CallMachineDlg();
}

/**Destructor*/
CMachineDrawable::~CMachineDrawable()
{
}

/** Constructor
 * \param name The drawable name*/
CMachineDrawable::CMachineDrawable(const std::wstring& name) : CDrawable(name)
{
	CMachineFactory mfactory;
	auto machineptr = mfactory.CreateMachine();
	mMachine = machineptr;
	CallMachineDlg();
}

/**
 * Draw the machine drawable
 * \param graphics Graphics context to draw on
 */
void CMachineDrawable::Draw(Gdiplus::Graphics* graphics)
{
	float scale = 0.6f;

    auto save = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X,
                                    (float)mPlacedPosition.Y);
    graphics->ScaleTransform(scale, scale);
    mMachine->DrawMachine(graphics);
    graphics->Restore(save);
}

/**
 * Hit tests the machine
 * \param pos the point to be tested
 * \returns false due to lack of use
 */
bool CMachineDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}

/**
* Sets Location of Machine
* \param x coordinate
* \param y coordinate
*/
void CMachineDrawable::SetLocation(int x, int y)
{
	mMachine->SetLocation(x, y);
}

/**
* Calls Machine Dialog Box */
void CMachineDrawable::CallMachineDlg()
{
	CMachineDlg dlg(mMachine);
	if (dlg.DoModal() == IDOK)
	{

	}
}

