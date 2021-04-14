#include "pch.h"
#include "Mouse.h"

CMouse::CMouse()
{
	CenteredSquare(MouseSize);
	SetImage(L"images/mouse.png");
}

void CMouse::Update(int x)
{
	CComponent::Update(x);
	mX = int(mStartX + speed * x / 30);
	if (mX <= mEndX)
	{
		mMotor->Start();
		return;
	}
	if (((mX - mStartX) / 20) % 2 == 0)
		SetRotation(.01);
	else
		SetRotation(.99);
	CComponent::SetLocation(mX, mY);
}

void CMouse::Draw(Gdiplus::Graphics* graphics)
{
	CComponent::Draw(graphics);
}
