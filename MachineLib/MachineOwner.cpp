/**
 * \file MachineOwner.cpp
 *
 * \author Shrey Jindal
 */
#include "pch.h"
#include "MachineOwner.h"
#include "Polygon.h"
#include "MachineFactory.h"
using namespace std; using namespace Gdiplus;

CMachineOwner::CMachineOwner() : CMachine()
{

}

void CMachineOwner::DrawMachine(Gdiplus::Graphics* graphics)
{
	mActualMachines[mMachineNumber - 1]->Draw(graphics);
}

void CMachineOwner::SetMachineFrame(int frame)
{
	for(auto mActualMachine : mActualMachines)
		mActualMachine->SetFrameNumber(frame);
}

void CMachineOwner::SetMachineNumber(int machine)
{
	mMachineNumber = machine;
}

int CMachineOwner::GetMachineNumber()
{
	return mMachineNumber;
}

void CMachineOwner::SetLocation(int x, int y)
{

	mActualMachines[mMachineNumber - 1]->SetLocation(x, y);
}



