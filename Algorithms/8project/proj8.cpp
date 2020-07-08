//Matthew Schroder 
//3080-001
//Project 8
//Due: 4-22-2019
//Reads in an edge record to creates the edges in the graph object then
//Uses that graph (in the form of various structures) to find the shortest path from a starting vertex

#include "graph.h"
#include <fstream>
using namespace std; 
int main()
{
	//Declars variables necessary for main and graph functions 
	ifstream myfile;
	int numVert, edgeRec, start, i;

	myfile.open("graph.txt");

	//Reads in the header line in the file 
	myfile >> numVert;
	myfile >> edgeRec;
	myfile >> start;

	//Instatiates the graph object with number of vertices
	Graph graph(numVert);

	//Runs through each edge entry and adds that edge to the graph object
	for(i = 0; i < edgeRec; i++)
	{	
 		int to, from;
		double weight;
		string s_direct;
		bool direct;

		myfile >> from; 
		myfile >> to;
		myfile >> weight;
		myfile >> s_direct;	
		if(s_direct == "false")
			direct = 0;
		if(s_direct == "true")
			direct = 1;

		graph.addEdge(from, to, weight, direct);
	}

	graph.DijkstraPaths(start);

	return 0;
}