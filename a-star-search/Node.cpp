//
//  Node.cpp
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#include "Node.h"
using namespace std;
Node::Node(int value, float priority){
	this->priority = priority;
	this->value = value;
	this->label = "";
}
Node::Node(int value, float priority, string label){
	this->priority = priority;
	this->value = value;
	this->label = label;
}

int Node::getValue() const{
	return this->value;
}

float Node::getPriority() const{
	return this->priority;
}

void Node::setPriority(float prio){
	this->priority = prio;
}

void Node::setPredecessor(Node *pred){
	this->predecessor = pred;
}
Node *Node::getPredecessor(){
	return this->predecessor;
}

void Node::addAdjNode(Node *adj, float cost, std::string label)
{
	Edge edge(this, adj, cost, label);
	adjNodeList.push_back(edge);
}

void Node::addAdjNode(Node *adj, float cost)
{
	this->addAdjNode(adj, cost, "edge");
}


vector<Node *> Node::getAdjNodes(){
	vector<Node *>nodes;
	for(vector<Edge>::iterator it; it != this->adjNodeList.end(); it++){
		nodes.push_back((*it).getDstNode());
	}
	return nodes;
}

vector<Edge>Node::getEdges(){
	return this->adjNodeList;
}

Edge Node::getMinimalEdge(){
	Edge min = *this->adjNodeList.begin();
	for(vector<Edge>::iterator i = this->adjNodeList.begin(); i != this->adjNodeList.end(); i++){
		if(min.getCost() > (*i).getCost()){
			min = *i;
		}
	}
	return min;
}

void Node::print(){
	cout << this->value << "->";
	if(this->predecessor != NULL){
		this->predecessor->print();
	}
}


bool Node::hasAdjNodes(){
	return this->adjNodeList.size() > 0;
}


bool operator<(Node const &lhs, Node const &rhs){
	return lhs.getPriority() < rhs.getPriority();
}

bool operator>(Node const &lhs, Node const &rhs){
	return lhs.getPriority() > rhs.getPriority();
}

bool operator==(Node const &lhs, Node const &rhs){
	return lhs.getValue() == rhs.getValue();
}
