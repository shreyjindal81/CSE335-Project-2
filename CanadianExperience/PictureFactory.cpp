/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"


using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(750, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();
                             
    sparty->SetPosition(Point(520, 500));
    picture->AddActor(sparty);

    //shared_ptr<CActor> machine = make_shared<CActor>(L"Machine");
    //CMachineFactory mfactory;
    //auto machineptr = mfactory.CreateMachine();
    //auto machineDrawable = make_shared<CMachineDrawable>(L"machine", machineptr);
    //machineDrawable->SetLocation(300, 300);
    //machine->SetRoot(machineDrawable);
    //machine->AddDrawable(machineDrawable);
    //picture->AddActor(machine);


    auto machineDrawable = make_shared<CMachineDrawable>(L"machine");
    machineDrawable->SetLocation(350,800);
    background->AddDrawable(machineDrawable);

    auto machineDrawable2 = make_shared<CMachineDrawable>(L"machine2");
    machineDrawable2->SetLocation(350, 300);
    background->AddDrawable(machineDrawable2);

    picture->AddMachineDrawable(machineDrawable);
    picture->AddMachineDrawable(machineDrawable2);

    return picture;
}
