//
//  main.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#if defined __NO_10__
    #include "Sort/Cli.h"
    using namespace NO_10;
#elif defined __NO_8__
    #include "MST/Cli.h"
    using namespace NO_8;
#elif defined __NO_2__
    #include "Josephus/Cli.h"
    using namespace NO_2;
#else
    // 默认第二题
    #include "Josephus/Cli.h"
    using namespace NO_2;
#endif

using namespace std;

int main(int argc, const char * argv[])
{
    new Cli();
    
#ifdef _WIN32
    system("pause");
#endif
    
    return EXIT_SUCCESS;
}
