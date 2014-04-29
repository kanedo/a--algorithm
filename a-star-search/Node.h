//
//  Node.h
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#ifndef __a_star_search__Node__
#define __a_star_search__Node__

#include <iostream>
#include <vector>
#include "Edge.h"


using namespace std;

class Node{
protected:
	Node* predecessor;
	int value;
	float priority;
	vector<Edge> adjNodeList;
	string label;
public:
	Node(int value,float priority, string label);
	Node(int value,float priority);
	int getValue() const;
	float getPriority() const;
	void setPriority(float prio);
	void setPredecessor(Node *pred);
	Node *getPredecessor();
	void addAdjNode(Node *adj, float cost);
	void addAdjNode(Node *adj, float cost, std::string label);
	vector<Node *> getAdjNodes();
	vector<Edge>getEdges();
	Edge getMinimalEdge();
	bool hasAdjNodes();
	void print();
};
bool operator<(Node const &lhs, Node const &rhs);
bool operator>(Node const &lhs, Node const &rhs);
bool operator==(Node const &lhs, Node const &rhs);

struct NodeComparator {
	bool operator() (const Node* lhs, const Node* rhs) const
	{return lhs->getValue()<rhs->getValue();}
};

#endif /* defined(__a_star_search__Node__) */
