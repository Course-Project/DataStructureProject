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
    
    cout << "{" << buf << "}root$ " << messages << endl;;
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
    
}

/**
 *  输入边
 */
void Cli::inputEdges() {
    
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
            this->mst.prim();
            break;
        } else if (which == "2") {
            this->mst.kruskal();
            break;
        }
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