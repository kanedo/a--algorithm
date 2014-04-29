//
//  AStarSearch.h
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#ifndef __a_star_search__AStarSearch__
#define __a_star_search__AStarSearch__

#include <iostream>
#include <queue>          // std::priority_queue
#include <set>
#include <map>
#include "Node.h"
#include "Edge.h"

using namespace std;

class AStarSearch{
protected:
	priority_queue<Node*> *openlist;
	set<Node*> *openset;
	set<Node*> *closedlist;
	set<Node*, NodeComparator> *nodes;
	
	map<int, float>weight;
	
	void expandNode(Node *currentNode);
	
	Node *getNodeByValue(int val);
	
	float g(Node *currentNode);
	float h(Node *currentNode);
	void updateG(Node *currentNode, float val);
	float costs(Node *a, Node *b);
public:
	AStarSearch();
	~AStarSearch();
	void addNodes(set<Node*, NodeComparator> *nodes);
	bool search(int start, int end);
	
};

bool operator<(Node const &lhs, Node const &rhs);
bool operator>(Node const &lhs, Node const &rhs);
bool operator==(Node const &lhs, Node const &rhs);
#endif /* defined(__a_star_search__AStarSearch__) */
