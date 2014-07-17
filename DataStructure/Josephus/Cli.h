//
//  Cli.h
//  DataStructure
//
//  Created by Tom Hu on 7/16/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__Cli__
#define __DataStructure__Cli__

#include "CircleList.h"

namespace NO_2 {
    class Cli {
    private:
        CircleList *circleList;
        
        void start();
        
    public:
        Cli();
    };
}

#endif /* defined(__DataStructure__Cli__) */
