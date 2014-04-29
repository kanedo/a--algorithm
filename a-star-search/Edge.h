//
//  Edge.h
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#ifndef __a_star_search__Edge__
#define __a_star_search__Edge__
#include <iostream>
using namespace std;
class Node;

class Edge{
protected:
	Node* orgNode;//the originating vertex
	Node* dstNode;//the destination vertex
	float cost;
	std::string label;
public:
	Edge(Node *firstNode, Node *secNode, float inCost);
	Edge(Node *firstNode, Node *secNode, float inCost, std::string label);
	~Edge();
	Node* getDstNode();
	Node* getOrgNode();
	float getCost();
};
#endif /* defined(__a_star_search__Edge__) */
