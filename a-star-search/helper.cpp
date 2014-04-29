//
//  helper.cpp
//  a-star-search
//
//  Created by Gabriel Bretschner on 29.04.14.
//  Copyright (c) 2014 Gabriel Bretschner. All rights reserved.
//

#include "helper.h"


void print_edge(Edge edge){
	std::cout << "(";
	std::cout<< edge.getOrgNode()->getValue();
	std::cout << ",";
	std::cout << edge.getDstNode()->getValue();
	std::cout << ":";
	std::cout << edge.getCost();
	std::cout << ")" << std::endl;
}

void print_edge_word(Edge edge){
	std::cout << edge.getLabel();
}

void print_edges(std::vector<Edge> edges){
	for(std::vector<Edge>::reverse_iterator it = edges.rbegin(); it != edges.rend(); it++){
		print_edge(*it);
	}
}

void print_edges_word(std::vector<Edge> edges){
	for(std::vector<Edge>::reverse_iterator it = edges.rbegin(); it != edges.rend(); it++){
		print_edge_word(*it);
	}
}

