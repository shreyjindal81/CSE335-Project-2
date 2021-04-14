/**
 * \file MachineFactory.cpp
 *
 * \author Shrey Jindal
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "MachineOwner.h"
#include "Component.h"
#include "Gear.h"
#include"Motor.h"
#include "Winch.h"
#include "Trap.h"
#include "Mouse.h"
#include "MachineActual.h"
using namespace std;

/**
 * Constructor
 */
CMachineFactory::CMachineFactory()
{
}


/**
 * Destructor
 */
CMachineFactory::~CMachineFactory()
{
}



/**
 * Create a machine object
 * \param r the speed of motor
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachine> CMachineFactory::CreateMachine(float r)
{
    auto machineowner = make_shared<CMachineOwner>();
    auto machine = make_shared<CMachineActual>();

    // The base
    auto base = make_shared<CComponent>();
    int wid = 650;
    base->Rectangle(-wid / 2, 10, wid, 10);
    base->SetColor(Gdiplus::Color::DarkGray);
    machine->AddComponent(base);

    // Add post that hol the 2nd and 4th gears
// You can only just barely see the one 
// for the 4th gear behind the motor and gears
    AddPost(machine, -250, 229);
    AddPost(machine, -191, 105);
    AddPost(machine, -270, 165);

    auto mouse = make_shared<CMouse>();
    mouse->SetInitialPosition(300, -41);
    mouse->SetFinalPosition(30, -41);
    machine->AddComponent(mouse);

    auto cheese = make_shared<CComponent>();
    cheese->CenteredSquare(70);
    cheese->SetLocation(-40,-38);
    cheese->SetImage(L"images/cheese.png");
    machine->AddComponent(cheese);

    auto motor = make_shared<CMotor>(r);
    machine->AddComponent(motor);
    motor->SetLocation(-250, -45);
    mouse->SetMotor(motor);

    int gear1r = 30;
    int gear1t = 15;
    double gear1s = r;

    auto gear = make_shared<CGear>(gear1r,gear1t,gear1s);
    machine->AddComponent(gear);
    gear->SetImage(L"images/steel.png");
    gear->SetLocation(-250, -45);

    int gear2r = 60;
    int gear2t = 30;
    double gear2s = -float(gear1s * gear1r) / float(gear2r);

    auto gear2 = make_shared<CGear>(gear2r, gear2t, gear2s);
    machine->AddComponent(gear2);
    gear2->SetLocation(-191, -105);
    gear2->SetStartAngle(float(.01));
    gear2->SetImage(L"images/hammered-copper.png");

    int gear3r = 24;
    int gear3t = 12;
    double gear3s = gear2s;

    auto gear3 = make_shared<CGear>(gear3r, gear3t, gear3s);
    machine->AddComponent(gear3);
    gear3->SetLocation(-191, -105);
    gear3->SetStartAngle(float(.01));
    gear3->SetImage(L"images/iron.png");

    int gear4r = 80;
    int gear4t = 40;
    double gear4s = -float(gear3s * gear3r) / float(gear4r);

    auto gear4 = make_shared<CGear>(gear4r, gear4t, gear4s);
    machine->AddComponent(gear4);
    gear4->SetLocation(-270, -165);
    gear4->SetStartAngle(float(.01));
    gear4->SetImage(L"images/steel.png");

    int gear5r = 22;
    int gear5t = 11;
    double gear5s = gear4s;

    auto gear5 = make_shared<CGear>(gear5r, gear5t, gear5s);
    machine->AddComponent(gear5);
    gear5->SetLocation(-270, -165);
  // gear5->SetStartAngle(.01);
    gear5->SetImage(L"images/iron.png");

    int gear6r = 50;
    int gear6t = 25;
    double gear6s = -float(gear5s * gear5r) / float(gear6r);

    auto gear6 = make_shared<CGear>(gear6r, gear6t, gear6s);
    machine->AddComponent(gear6);
    gear6->SetLocation(-250, -229);
    gear6->SetStartAngle(float(.015));
    gear6->SetImage(L"images/hammered-copper.png");

    int winchr = 40;
    double winchs = gear6s;
    int winchl = 220;
    auto winch = make_shared<CWinch>(winchs,winchl);
    machine->AddComponent(winch);
    winch->SetLocation(-250,-229);

    auto trap = make_shared<CTrap>();
    trap->SetLocation(0,-149);
    trap->SetWinch(winch);
    machine->AddComponent(trap);

    machine->SetStartFrame(int(270 * 30 / 90 + 3));
    machineowner->AddMachine(machine);


    auto machine2 = make_shared<CMachineActual>();

    auto mouse2 = make_shared<CMouse>();
    mouse2->SetInitialPosition(400, -41);
    mouse2->SetFinalPosition(30, -41);
    machine2->AddComponent(mouse2);

    auto base2 = make_shared<CComponent>();
    base2->Rectangle(-wid / 2, 10, wid, 10);
    base2->SetColor(Gdiplus::Color::DarkGray);
    machine2->AddComponent(base2);

    auto cheese2 = make_shared<CComponent>();
    cheese2->CenteredSquare(70);
    cheese2->SetLocation(-40, -38);
    cheese2->SetImage(L"images/cheese.png");
    machine2->AddComponent(cheese2);

    auto motor2 = make_shared<CMotor>(r);
    machine2->AddComponent(motor2);
    motor2->SetLocation(-250, -45);
    mouse2->SetMotor(motor2);

    AddPost(machine2, -180, 229);

    int gear7r = 50;
    int gear7t = 25;
    double gear7s = r/11;

    auto gear7 = make_shared<CGear>(gear7r, gear7t, gear7s);
    machine2->AddComponent(gear7);
    gear7->SetImage(L"images/steel.png");
    gear7->SetLocation(-250, -45);

    int gear8r = 46;
    int gear8t = 23;
    double gear8s = -float(gear7s * gear7r) / float(gear8r);

    auto gear8 = make_shared<CGear>(gear8r, gear8t, gear8s);
    machine2->AddComponent(gear8);
    gear8->SetImage(L"images/rust.png");
    gear8->SetLocation(-180, -101);
    gear8->SetStartAngle(float(.015));

    int gear10r = 24;
    int gear10t = 12;
    double gear10s = -float(gear8s * gear8r) / float(gear10r);

    auto gear10 = make_shared<CGear>(gear10r, gear10t, gear10s);
    machine2->AddComponent(gear10);
    gear10->SetColor(Gdiplus::Color::Red);
    gear10->SetLocation(-180, -165);

    int gear11r = 46;
    int gear11t = 23;
    double gear11s = -float(gear10s * gear10r) / float(gear11r);

    auto gear11 = make_shared<CGear>(gear11r, gear11t, gear11s);
    machine2->AddComponent(gear11);
    gear11->SetColor(Gdiplus::Color::Blue);
    gear11->SetLocation(-180, -229);
    gear11->SetStartAngle(float(.025));

    double winch2s = gear11s;
    int winch2l = 180;
    auto winch2 = make_shared<CWinch>(winch2s, winch2l);
    machine2->AddComponent(winch2);
    winch2->SetLocation(-180, -229);

    auto trap2 = make_shared<CTrap>();
    trap2->SetLocation(0, -149);
    trap2->SetWinch(winch2);
    machine2->AddComponent(trap2);

    machine2->SetStartFrame(int(370 * 30 / 90 + 3));
    machineowner->AddMachine(machine2);
    return machineowner;
}

/**
 * Add a post.
 *
 * \param machine Machine we are adding the post to.
 * \param x X location for the post
 * \param height Height of the post
 */
void CMachineFactory::AddPost(std::shared_ptr<CMachineActual> machine, int x, int height)
{
    // The post itself
    auto post = make_shared<CComponent>();
    post->Rectangle(-5, 0, 10, height);
    post->SetLocation(x, 0);
    post->SetImage(L"images/post.png");
    machine->AddComponent(post);

    // The post base. It's a square image that
    // is 4 times as wide as the post image
    auto base = make_shared<CComponent>();
    base->Rectangle(-20, 0, 40, 40);
    base->SetLocation(x, 0);
    base->SetImage(L"images/post-base.png");
    machine->AddComponent(base);


}

