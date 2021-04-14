/**
 * \file MachineDrawable.h
 *
 * \author Shrey Jindal
 *
 * A drawable based on a machine
 * 
 * This is the adapter class between Canadian Experience and MachineLib
 */
#pragma once
#include <memory>
#include "Drawable.h"
#include "Machine.h"
using namespace std;
 /**
  * A drawable based a machine
  */
class CMachineDrawable :
    public CDrawable
{
public:
    CMachineDrawable(const std::wstring& name, shared_ptr<CMachine> machine);
    virtual ~CMachineDrawable();
    CMachineDrawable(const std::wstring& name);
    /** Default constructor disabled */
    CMachineDrawable() = delete;
    /** Copy constructor disabled */
    CMachineDrawable(const CMachineDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMachineDrawable&) = delete;
    virtual void Draw(Gdiplus::Graphics* graphics) override;
    virtual bool HitTest(Gdiplus::Point pos) override;
    virtual void SetLocation(int x, int y);



    /**
    * sets frame number for machine
    * \param x the value of frame */
    virtual void SetFrameNumber(int x) { mMachine->SetMachineFrame(x); };

    /**
    * \ override setkeyframe to do nothing for machine*/
    virtual void SetKeyframe() {};

    /**
    * Sets the Machine Number in CMAchine
    * \param n the number to be set*/
    virtual void SetMachineNumber(int n) { mMachine->SetMachineNumber(n); };

    virtual void CallMachineDlg();
private:
    ///the machine that needs to be adapted
    shared_ptr<CMachine> mMachine;
};
