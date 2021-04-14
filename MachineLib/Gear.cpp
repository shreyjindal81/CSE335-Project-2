#include "pch.h"
#include "Gear.h"
#include "Const.h"
#include "Polygon.h"
using namespace std; using namespace Gdiplus;

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

CGear::CGear(int radius, int numTeeth, float rot) : CComponent()
{
    mRadius = radius; mTeeth = numTeeth; mRotation = rot;
    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = mRadius - ToothDepth;
    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * CConst::PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * CConst::PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * CConst::PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * CConst::PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * CConst::PI2;
        
        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
        SetImage(L"images/steel.png");
    }
}
void CGear::Draw(Gdiplus::Graphics* graphics)
{
    CComponent::Draw(graphics);
}

void CGear::Rotate(int x)
{
    SetRotation(mStartAngle + x * mRotation / 30);
}
