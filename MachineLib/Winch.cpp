#include "pch.h"
#include "Winch.h"

CWinch::CWinch(float rot, int len)
{
	mRadius = 40;
	mRotation = rot;
	mLength = len;
	CenteredSquare(2 * mRadius);
	SetImage(L"images/drum.png");
	
	mRope.Rectangle(0, 0, mLength, 3);
}

void CWinch::Draw(Gdiplus::Graphics* graphics)
{
	mRope.Draw(graphics);
	CComponent::Draw(graphics);
}

void CWinch::Rotate(int x)
{
	if (!mEnabled)
		return;
	SetRotation(x * mRotation / 30);
	mRope.Clear();
	int l = int(mLength + (x * mRotation / 30) * 2 * 3.1417 * float(mRadius));
	if (l >= 1)
		mRope.Rectangle(0, 0, l, 3);
	else
		mRope.Rectangle(0, 0, 1, 1);
}

void CWinch::SetLocation(int x, int y)
{
	CComponent::SetLocation(x, y);
	mRope.SetLocation(x, y-mRadius+3);
}

void CWinch::SetMachineLocation(int x, int y)
{
	CComponent::SetMachineLocation(x, y);
	mRope.SetMachineLocation(x, y);
}
