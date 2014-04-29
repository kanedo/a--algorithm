//
//  main.cpp
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include "AStarSearch.h"
using namespace std;

int main(int argc, const char * argv[])
{

	std::set<Node*, NodeComparator> *nodes = new std::set<Node *, NodeComparator>();
	Node *a, *b, *c, *d;
	a = new Node(0, 0, " ");
	b = new Node(1, 0, "X");
	c = new Node(2, 0, "Y");
	d = new Node(3, 0, "Z");
	
	//b->addAdjNode(a, 1.4, "B");
	a->addAdjNode(b, 1.4, "B");
	//b->addAdjNode(a, 1.2, "C");
	a->addAdjNode(b, 1.2, "C");
	//c->addAdjNode(b, 1.2, "D");
	b->addAdjNode(c, 1.2, "D");
	//c->addAdjNode(b, 1.3, "E");
	b->addAdjNode(c, 1.3, "E");
	//c->addAdjNode(a, 1.5, "AA");
	a->addAdjNode(c, 1.5, "AA");
	//d->addAdjNode(c, 1.1, "F");
	c->addAdjNode(d, 1.1, "F");
	//d->addAdjNode(b, 1.5, "GG");
	b->addAdjNode(d, 1.5, "GG");
	nodes->insert(a);
	nodes->insert(b);
	nodes->insert(c);
	nodes->insert(d);
		
	AStarSearch*search = new AStarSearch();
	search->addNodes(nodes);
	
	bool res = search->search(0, 3);
	if(res){
		cout << "YAY ";
		d->print();
	}
	std::cout << "Hello, World!\n";
    return 0;
}

