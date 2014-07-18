//
//  Cli.h
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__Cli__
#define __DataStructure__Cli__

#include <vector>

namespace NO_10 {
    class Cli {
    private:
        bool isRunning;
        
        void start(const std::vector<int> &t);
        
    public:
        Cli();
    };
}



#endif /* defined(__DataStructure__Cli__) */
