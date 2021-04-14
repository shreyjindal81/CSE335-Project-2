#include "pch.h"
#include "Trap.h"

CTrap::CTrap()
{


	mTrapStand.CenteredSquare(300);
	mTrapFront.CenteredSquare(300);
	mTrapPin.CenteredSquare(300);

	mTrapStand.SetImage(L"images/trap-stand.png");
	mTrapFront.SetImage(L"images/trap-stand-front.png");
	mTrapPin.SetImage(L"images/trap-pin1.png");

	CenteredSquare(300);
	SetImage(L"images/trap-trap.png");
}

void CTrap::Draw(Gdiplus::Graphics* graphics)
{
	mTrapStand.Draw(graphics);
	mTrapPin.Draw(graphics);
	mTrapFront.Draw(graphics);
	CComponent::Draw(graphics);
}

void CTrap::Rotate(int x)
{
	int a, b;
	mTrapStand.GetLocation(a, b);

	int deltaPin = a + mPinSpeed * x / 30;
	if (x>((-18-a)*30/mPinSpeed))
	{
		int add = x - (-18 - a) * 30 / mPinSpeed;
		if (add <= 12)
			CComponent::SetLocation(a, b-100 + 8 * add);
	}
	else
	{
		CComponent::SetLocation(a, b - 100);
	}
	if (deltaPin >= -65)
	{
		mTrapPin.SetLocation(deltaPin, b);
		mWinch->SetEnabled(true);
	}
	else
		mWinch->SetEnabled(false);
}

void CTrap::SetLocation(int x, int y)
{
	CComponent::SetLocation(x, y-100);
	mTrapStand.SetLocation(x, y);
	mTrapFront.SetLocation(x, y);
	mTrapPin.SetLocation(x, y);
}

void CTrap::SetMachineLocation(int x, int y)
{
	CComponent::SetMachineLocation(x, y);
	mTrapStand.SetMachineLocation(x, y);
	mTrapFront.SetMachineLocation(x, y);
	mTrapPin.SetMachineLocation(x, y);
}
