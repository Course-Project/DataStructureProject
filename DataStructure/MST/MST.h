//
//  MST.h
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__MST__
#define __DataStructure__MST__

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

/**
 *  结构体Edge
 *  记录边的信息
 */
struct Edge {
    string l, r;
    size_t length;
};


/**
 *  MST，最小生成树
 */
class MST {
private:
    set<Edge>           edges;              // 边集
    set<string>         vertexs;            // 点集
    
    string              startVertex;        // 仅针对Prim算法
    map<string, size_t> vertexMap;          // 仅针对Prim算法
    size_t              totalLength;        // 最小生成树总长度
    
    size_t **graph;
    void initGraph();
    
    bool containsVertex(const Edge &e, const size_t &v);
    
    set<Edge>           resultEdges;        // MST结果边集
    void addResultEdge(const Edge &e);
    void addResultEdge(const size_t &vertexIndex1, const size_t &vertexIndex2);
    
public:
    /**
     *  为图添加边
     *
     *  @param v 需要添加的点
     */
    void addVertex(const string &v);
    
    /**
     *  为图添加边
     *
     *  @param v1     边的一个点
     *  @param v2     边的另一个点
     *  @param length 边的长度
     */
    void addEdge(const Edge &edge);
    
    /**
     *  为Prim算法设置起始点
     *
     *  @param v Prim算法的起始点
     */
    void setStartVertex(const string &v);
    
    /**
     *  输出结果
     */
    void printResult() const;
    
    /**
     *  判断是否存在某点
     *
     *  @param v 顶点名称
     *
     *  @return 存在则返回true，否则返回false
     */
    bool hasVertex(const string &v) const;
    
    /**
     *  清空点集
     */
    void clearVertexSet();
    
    /**
     *  清空边集
     */
    void clearEdgeSet();
    
    /**
     *  判断点集是否为空
     *
     *  @return 空则返回true，否则返回false
     */
    bool isVertexSetEmpty() const;
    
    /**
     *  判断边集是否为空
     *
     *  @return 空则返回true，否则返回false
     */
    bool isEdgeSetEmpty() const;
    
    void prim();
    void kruskal();
};

#endif /* defined(__DataStructure__MST__) */
