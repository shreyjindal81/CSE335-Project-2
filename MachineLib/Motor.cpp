#include "pch.h"
#include "Motor.h"
#include "Const.h"
#include "Polygon.h"
using namespace std; using namespace Gdiplus;



CMotor::CMotor(float r)
{
	mRotation = r;

	CPolygon b;


	b.CenteredSquare(100);
	b.SetImage(L"images/motor2.png");

	mBackdrop = b;

	CenteredSquare(20);

	SetImage(L"images/shaft.png");
}

void CMotor::Draw(Gdiplus::Graphics* graphics)
{


	int a, b, c, d;
	GetLocation(a, b);
	GetMachineLocation(c, d);

	mBackdrop.DrawPolygon(graphics, a + c, b + d);
	CComponent::Draw(graphics);
}

void CMotor::Rotate(int x)
{
	SetRotation(x*mRotation / 30);
}

