//
//  AStarSearch.cpp
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#include "AStarSearch.h"
AStarSearch::AStarSearch(){
	this->openlist = new priority_queue<Node*>();
	this->openset = new set<Node*>();
	this->closedlist = new set<Node*>();
}

AStarSearch::~AStarSearch(){
	delete this->openlist;
	delete this->openset;
	delete this->closedlist;
}

void AStarSearch::addNodes(set<Node*, NodeComparator>* nodes){
	this->nodes = nodes;
	for (set<Node*, NodeComparator>::iterator node = nodes->begin(); node != nodes->end(); node++) {
		if ((*node)->hasAdjNodes()) {
			Edge minimalEdge = (*node)->getMinimalEdge();
			this->updateG(*node, minimalEdge.getCost());
		}else{
			this->updateG(*node, 0);
		}
	}
}

bool AStarSearch::search(int start, int end){
	Node *start_node = this->getNodeByValue(start);
	Node *end_node = this->getNodeByValue(end);
	start_node->setPriority(0);
	this->openset->insert(start_node);
	this->openlist->push(start_node);
	
	while(!this->openlist->empty()){
		Node *currentNode = this->openlist->top();
		this->openlist->pop();
		this->openset->erase(currentNode);
		
		if(currentNode == end_node){
			return true;
		}
		
		this->closedlist->insert(currentNode);
		this->expandNode(currentNode);
	}
	return false;
}

void AStarSearch::printBestPath(int start, int end){
	int val = end;
	vector<Edge>*final_path = new vector<Edge>();
	for (size_t i = this->edges.size(); i > 0; i--) {
		if(this->edges[i-1].getDstNode()->getValue() == val){
			final_path->push_back(this->edges[i-1]);
			val = this->edges[i-1].getOrgNode()->getValue();
		}
	}
	
	print_edges(*final_path);
	print_edges_word(*final_path);
}


void AStarSearch::expandNode(Node *currentNode){
	vector<Edge> successors = currentNode->getEdges();
	for(vector<Edge>::iterator successor = successors.begin(); successor != successors.end(); successor++){
		Node *successorNode = (*successor).getDstNode();
		if(this->closedlist->find(successorNode) != this->closedlist->end()){
			continue;
		}
		
		float tentative_g = this->g(currentNode) + (*successor).getCost();
		
		if (this->openset->find(successorNode) != this->openset->end()){
			if(tentative_g >= this->g(successorNode)){
				continue;
			}
		}
		
		successorNode->setPredecessor(currentNode);
		this->updateG(successorNode, tentative_g);
		float f = tentative_g + this->h((*successor).getDstNode());
		successorNode->setPriority(f);
		if (this->openset->find((*successor).getDstNode()) == this->openset->end()) {
			this->edges.push_back(*successor);
			this->openlist->push((*successor).getDstNode());
			this->openset->insert((*successor).getDstNode());
		}
	}
}

Node* AStarSearch::getNodeByValue(int val){
	set<Node*>::iterator it = this->nodes->find(new Node(val, 0));
	if(it != this->nodes->end()){
		return *it;
	}
	return NULL;
}


float AStarSearch::g(Node *currentNode){
	float val = this->weight[currentNode->getValue()];
	return val;
}
float AStarSearch::h(Node *currentNode){
	return 0;
}
void AStarSearch::updateG(Node *currentNode, float val){
	this->weight[currentNode->getValue()] = val;
}
float AStarSearch::costs(Node *a, Node *b){
	return 0;
}