//
//  Cli.h
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__Cli__
#define __DataStructure__Cli__

#include <iostream>
#include "MST.h"

namespace NO_8 {
    /**
     *  Command Line Interface
     */
    class Cli {
    private:
        MST mst;
        bool isRunning;
        
        /**
         *  输出欢迎信息
         */
        void printWelcomeMessage();
        
        /**
         *  开始运行
         *  获取用户输入，执行不同的模块
         */
        void start();
        
        /**
         *  输入点
         */
        void inputVertexs();
        
        /**
         *  输入边
         */
        void inputEdges();
        
        /**
         *  选择算法(Prim / Kruskal)
         *  并运行
         */
        void run();
        
        /**
         *  为Prim算法设置起始点
         */
        void inputStartVertex();
        
    public:
        /**
         *  构造函数
         */
        Cli();
    };
}

#endif /* defined(__DataStructure__Cli__) */
