//
//  Edge.cpp
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#include "Edge.h"

Edge::Edge(Node *firstNode, Node *secNode, float inCost, std::string label)
{
	this->orgNode = firstNode;
	this->dstNode = secNode;
	this->cost = inCost;
	this->label = label;
}

Edge::Edge(Node *firstNode, Node *secNode, float inCost)
{
	this->orgNode = firstNode;
	this->dstNode = secNode;
	this->cost = inCost;
	this->label = "edge";
}


Edge::~Edge(){
	
}

string Edge::getLabel(){
	return this->label;
}

Node* Edge::getDstNode()
{
	return this->dstNode;
}

Node* Edge::getOrgNode()
{
	return this->orgNode;
}

float Edge::getCost()
{
	return this->cost;
}
