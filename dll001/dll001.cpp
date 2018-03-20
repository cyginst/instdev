#include "dll001.h"


Dll001::Dll001()
{
}

extern "C"
DLL001SHARED_EXPORT int add2(int a, int b)
{
    return a + b;
}
