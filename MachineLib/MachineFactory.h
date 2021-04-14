/**
 * \file MachineFactory.h
 *
 * \author Charles Owen ; additions by Shrey Jindal
 *
 * Machine factory class. Creates Machine objects
 */

#pragma once

#include <memory>
#include "MachineActual.h"
class CMachine;


/**
 * Machine factory class. Creates Machine objects
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CMachineFactory
{
public:
    CMachineFactory();
    ~CMachineFactory();

    std::shared_ptr<CMachine> CreateMachine(float r);
    void AddPost(std::shared_ptr<CMachineActual> machine, int x, int height);

    /// creates a machine with r = 1
    /// \returns machine ptr
    std::shared_ptr<CMachine> CreateMachine() { return CreateMachine(1.0); };

};

