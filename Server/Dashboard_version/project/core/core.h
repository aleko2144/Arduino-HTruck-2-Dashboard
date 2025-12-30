#ifndef CORE_H
#define CORE_H

#include <windows.h>
#include <iostream>
#include "../objects/Vehicle.h"
#include "../objects/Port.h"
//#include "config_utils.h"
#include "../input/input.h"
//#include <string>

namespace Core
{
    void Prepare(HANDLE hProcess);
    void Update(HANDLE hProcess);
}

#endif
