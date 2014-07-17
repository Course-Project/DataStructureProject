//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"
#include <ctime>

using namespace NO_8;
using namespace std;

string getInputWithMessages(const string &messages) {
    string input;
    char buf[80];
    
    time_t nowtime = time(NULL);
    strftime(buf, 80, "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
    
    cout << "{" << buf << "}root$ " << messages;
    cin >> input;
    
    return input;
}

void printMessages(const string &messages) {
    char buf[80];
    
    time_t nowtime = time(NULL);
    strftime(buf, 80, "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
    
    cout << "{" << buf << "}root$ " << messages;
}

/**
 *  输出欢迎信息
 */
void Cli::printWelcomeMessage() {
    cout << "=============================================" << endl;
    cout << "                电网造价模拟系统" << endl;
    cout << "=============================================" << endl;
    cout << "              A --- 创建电网顶点" << endl;
    cout << "              B --- 添加电网的边" << endl;
    cout << "              C --- 构造最小生成树" << endl;
    cout << "              D --- 显示结果" << endl;
    cout << "              E --- 退出" << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

/**
 *  开始运行
 *  获取用户输入，执行不同的模块
 */
void Cli::start() {
    string command = getInputWithMessages("请选择步骤：");
    
    if (command == "A") {
        // 输入点
        this->inputVertexs();
    } else if (command == "B") {
        // 输入边
        this->inputEdges();
    } else if (command == "C") {
        // 选择算法并执行
        this->run();
    } else if (command == "D") {
        // 显示结果
        this->printResult();
    } else if (command == "E") {
        this->isRunning = false;
    }
}

/**
 *  输入点
 */
void Cli::inputVertexs() {
    printMessages("请输入顶点名称，一行一个，输入0结束输入");
    cout << endl;
    while (true) {
        string vertexName = getInputWithMessages("顶点名称：");
        if (vertexName == "0") {
            break;
        }
        this->mst.addVertex(vertexName);
    }
}

/**
 *  输入边
 */
void Cli::inputEdges() {
    printMessages("请输入边的信息，包括两个端点名称以及边的长度(正整数)，例a b 8，每行一条边，输入0 0 0结束输入");
    cout << endl;
    while (true) {
        string vertex1, vertex2;
        size_t length;
        printMessages("边信息：");
        cin >> vertex1 >> vertex2 >> length;
        
        // 清空输入缓冲区，避免错误输入停留
        cin.clear();
        cin.sync();
        
        // 判断是否结束
        if (vertex1 == "0" && vertex2 == "0" && length == 0) {
            break;
        }
        
        // 检测是否存在该点
        if (!(this->mst.hasVertex(vertex1) && this->mst.hasVertex(vertex2))) {
            // 至少有一个点不存在
            printMessages("所输入的点不存在，请重新输入");
            cout << endl;
            continue;
        }
        
        // 判断长度是否正确
        if (length == 0) {
            // 输入了负数或是0
            printMessages("长度必须是正整数，请重新输入");
            cout << endl;
            continue;
        }
        
        // 添加边
        this->mst.addEdge((Edge){vertex1, vertex2, length});
    }
}

/**
 *  选择算法(Prim / Kruskal)
 *  并运行
 */
void Cli::run() {
    while (true) {
        printMessages("输入相应数字选择算法：1. Prim, 2. Kruskal");
        string which = getInputWithMessages("请选择算法：");
        if (which == "1") {
            this->inputStartVertex();
            break;
        } else if (which == "2") {
            this->mst.kruskal();
            break;
        }
    }
}

/**
 *  为Prim算法设置起始点
 */
void Cli::inputStartVertex() {
    while (true) {
        string startVertex = getInputWithMessages("请输入Prim算法起始点名称：");
        
        // 检测是否存在该点
        if (!(this->mst.hasVertex(startVertex))) {
            // 至少有一个点不存在
            printMessages("所输入的点不存在，请重新输入");
            cout << endl;
            continue;
        }
        
        // 设置起始点
        this->mst.setStartVertex(startVertex);
        
        // Prim
        this->mst.prim();
        
        break;
    }
}

/**
 *  显示最小生成树
 */
void Cli::printResult() {
    this->mst.printResult();
}

/**
 *  构造函数
 */
Cli::Cli() {
    // 初始化
    this->isRunning = true;
    
    // 输出欢迎信息
    this->printWelcomeMessage();
    
    // 开始运行
    while (this->isRunning) {
        this->start();
    }
}