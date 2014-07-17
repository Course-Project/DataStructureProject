//
//  MST.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "MST.h"
#include <cstdlib>

#pragma mark Utils
size_t *lowcost;            // lowcost表示对应点到MST的距离
size_t *closest;            // closest表示离对应点最近的点
map<string, string> father; // 并查集

void initFather(const set<string> &vertexs) {
    father.clear(); // 清空并查集
    
    set<string>::iterator itr = vertexs.begin();
    for (; itr != vertexs.end(); itr++) {
        father[*itr] = *itr;
    }
}

string getFather(const string &vertex) {
    return father[vertex] = ((father[vertex] == vertex) ? vertex : getFather(father[vertex]));
}

bool MST::containsVertex(const Edge &edge, const size_t &vIndex) {
    return this->vertexMap[edge.l] == vIndex || this->vertexMap[edge.r] == vIndex;
}

void MST::addResultEdge(const Edge &e) {
    this->resultEdges.insert(e);
}

void MST::addResultEdge(const size_t &vertexIndex1, const size_t &vertexIndex2) {
    set<Edge>::iterator itr = this->edges.begin();
    for (; itr != this->edges.end(); itr++) {
        if (this->containsVertex(*itr, vertexIndex1) && this->containsVertex(*itr, vertexIndex2)) {
            this->resultEdges.insert(*itr);
        }
    }
}

void MST::initGraph() {
    size_t con = this->edges.size();
    
    graph = (size_t **)malloc(sizeof(size_t *) * con);
    for (int i = 0; i < con; i ++) {
        graph[i] = (size_t *)malloc(sizeof(size_t) * con);
    }
    
    set<Edge>::iterator itr = edges.begin();
    for (; itr != edges.end(); itr++) {
        graph[this->vertexMap[itr->l]][this->vertexMap[itr->r]] = itr->length;
        graph[this->vertexMap[itr->r]][this->vertexMap[itr->l]] = itr->length;
    }
}

#pragma mark - MST
/**
 *  为图添加边
 *
 *  @param v 需要添加的点
 */
void MST::addVertex(const string &v) {
    this->vertexMap[v] = this->vertexMap.size();
    this->vertexs.insert(v);
}

/**
 *  为图添加边
 *
 *  @param v1     边的一个点
 *  @param v2     边的另一个点
 *  @param length 边的长度
 */
void MST::addEdge(const Edge &edge) {
    this->edges.insert(edge);
}

/**
 *  为Prim算法设置起始点
 *
 *  @param v Prim算法的起始点
 */
void MST::setStartVertex(const string &v) {
    this->startVertex = v;
}

/**
 *  输出结果
 */
void MST::printResult() const {
    set<Edge>::iterator itr = this->resultEdges.begin();
    for (; itr != this->resultEdges.end(); itr++) {
        cout << itr->l << " --(" << itr->length << ")-- " << itr->r << endl;
    }
}

/**
 *  判断是否存在某点
 *
 *  @param v 顶点名称
 *
 *  @return 存在则返回true，否则返回false
 */
bool MST::hasVertex(const string &v) const {
    return this->vertexs.find(v) != this->vertexs.end();
}

/**
 *  清空点集
 */
void MST::clearVertexSet() {
    this->vertexs.clear();
}

/**
 *  清空边集
 */
void MST::clearEdgeSet() {
    this->edges.clear();
}

/**
 *  判断点集是否为空
 *
 *  @return 空则返回true，否则返回false
 */
bool MST::isVertexSetEmpty() const {
    return this->vertexs.empty();
}

/**
 *  判断边集是否为空
 *
 *  @return 空则返回true，否则返回false
 */
bool MST::isEdgeSetEmpty() const {
    return this->edges.empty();
}

#pragma mark - Solve
void MST::prim() {
    size_t n = this->edges.size();
    size_t minLength = 0xffffffff, minVertex = 0;
    
    // 初始化
    this->totalLength = 0; // 最小生成树初始长度为0
    this->resultEdges.clear(); // 清空结果集
    lowcost = (size_t *)malloc(sizeof(size_t) * n);
    closest = (size_t *)malloc(sizeof(size_t) * n);
    this->initGraph(); // 初始化图
    
    // 初始化各点到起始点的距离
    for (int i = 0; i < n; i++) {
        lowcost[i] = this->graph[this->vertexMap[this->startVertex]][i];
        closest[i] = this->vertexMap[this->startVertex];
    }
    
    for (int i = 0; i < n - 1; i++) {
        minLength = 0xffffffff;
        for (int j = 0; j < n; j++) {
            //
            // 首先确认对应点的lowcost是否存在
            // 当该点加入MST后，自然和MST的距离变为0，也就是此时lowcost不存在
            // 只有当存在的时候才去寻找最小值
            //
            if (lowcost[j] && minLength > lowcost[j]) {
                minLength = lowcost[j];
                minVertex = j;
            }
        }
        
        // 将所找到的离MST最近的点加入MST
        this->totalLength += lowcost[minVertex];
        lowcost[minVertex] = 0;
        // 找到的边：(minVertex, closest[minVertex])
        this->addResultEdge(minVertex, closest[minVertex]);
        
        // 更新其它点到MST的距离
        for (int j = 0; j < n; j++) {
            if (this->graph[minVertex][j] < lowcost[j]) {
                lowcost[j] = this->graph[j][minVertex];
                closest[j] = minVertex;
            }
        }
    }
}

void MST::kruskal() {
    // 初始化
    this->totalLength = 0;      // 最小生成树初始长度为0
    this->resultEdges.clear();  // 清空结果集
    initFather(this->vertexs);  // 初始化并查集
    
    set<Edge>::iterator itr = this->edges.begin();
    for (; itr != this->edges.end(); itr++) {
        string father1 = getFather(itr->l), father2 = getFather(itr->r);
        if (father1 != father2) {
            // 没有共同的老爹
            // 也就是说连起来不会成环
            this->totalLength += itr->length;
            
            // 将当前边加入结果集
            this->addResultEdge(*itr);
            
            // 并查集合并
            father[father1] = father2;
        }
    }
}

#pragma mark - Operator <
bool operator < (const Edge &lhs, const Edge &rhs) {
    return lhs.length < rhs.length;
}
