#ifdef build_platform_host

#define CATCH_CONFIG_MAIN
#include "build.h"
#include "test.h"

#else

#include "build.h"

void test()
{
    int k = 2;
}

int main()
{
    test();

    while(1);
}

#endif