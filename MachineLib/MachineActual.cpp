#include "pch.h"
#include "MachineActual.h"

CMachineActual::CMachineActual()
{
}

void CMachineActual::Draw(Gdiplus::Graphics* graphics)
{
	for (auto c : mComponents) {
		
		c->Draw(graphics);
	}
}

void CMachineActual::SetLocation(int x, int y)
{
	mX = x; mY = y;
	for (auto c : mComponents)
	{
		c->SetMachineLocation(x, y);
	}
}
