/**
 * \file MachineOwner.h
 *
 * \author Shrey
 *
 * Class that represents the owner of an actual machine.
 */
#pragma once
#include <vector>
#include <memory>
#include "Machine.h"
#include "Component.h"
#include "MachineActual.h"
 /**
  * Class that represents the owner of a machine.
  *
  * This class works on the handling of the machines
  */
class CMachineOwner :
    public CMachine
{
public:
    /// Constructor
    CMachineOwner();

    /// Destructor
    virtual ~CMachineOwner() {}

    /// Copy constructor/disabled
    CMachineOwner(const CMachineOwner&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMachineOwner&) = delete;

    /**
* Draw the machine at the currently specified location
* \param graphics GDI+ Graphics object
*/
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;


    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame);

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine) override; ;

    /**
     * Get the current machine number   
     * \return Machine number integer
     */
    virtual int GetMachineNumber();


    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    void SetLocation(int x, int y);

    ///adds a machine to the list
    /// \param m the machine 
    virtual void AddMachine(std::shared_ptr<CMachineActual > m) { mActualMachines.push_back(m); m->SetOwner(this); }

private:
    int mCurrFrame = 0; ///< the current frame
    int mMachineNumber = 1; ///<machine number
    ///list of machines
    std::vector <std::shared_ptr<CMachineActual>> mActualMachines;
};

