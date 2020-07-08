//Matthew Schroder 
//3080-001
//Project 8
//Due: 4-22-2019
//Defines the functions addEdge and DijkstrasPath using the various 
//Structures that are avaiable

#include "graph.h"
#include <set>

using namespace std;

Graph::Graph(int vert)								// Contructor - Param(s): Number of vertices
{
	numVertices = vert;
	adjacent.resize(vert);
}


void Graph::addEdge(int from, int to, double weight, bool direct)	// Add edge to adjacency list (display as added) - Param(s): From vertex, To vertex, Weight, Directed edge?
{
	if(direct == true)
	{
		Edge oneEdge(from, to, weight);

		adjacent[from].push_front(oneEdge);

		cout << "Edge " << from <<", "<< to << ", " << weight << endl;
		//cout <<adjacent[from].front().v1  << " " << adjacent[from].front().v2 << " " << adjacent[from].front().weight << endl;
	}

	else if(direct == false)
	{
		Edge oneEdge(from, to, weight);
		Edge twoEdge(to, from, weight);
		adjacent[from].push_front(oneEdge);
		adjacent[to].push_front(twoEdge);

		cout << "Edge " << from <<", "<< to << ", " << weight << endl;
		cout << "Edge " << to <<", "<< from << ", " << weight << endl;
		//cout <<adjacent[from].front().v1  << " " << adjacent[from].front().v2 << " " << adjacent[from].front().weight << endl;
	}
}


void Graph::DijkstraPaths(int source)				// Computes/Outputs single source shortest paths - Param: source vertex
{
	set<pair<double, int>> openlist;
	vector <PathNode> pathnode;

	for(int i = 0; i < numVertices; i++)
	{
		PathNode newNode;
		newNode.cost  = numeric_limits<double>::infinity();
		newNode.prev = -1;
		pathnode.push_back(newNode);
	}

	pathnode[source].cost = 0;
	openlist.insert(make_pair(pathnode[source].cost,source));

	while(openlist.empty() == false)
	{
		pair<double,int> best = *(openlist.begin());

		openlist.erase(openlist.begin());

		//Goes through every node in the path node vector
		for(Edge edge: adjacent[best.second])
		{
			//Finds the edge in the list that going from the node being
			//processed and the table location were checking	
				if(pathnode[edge.v2].cost >  best.first + edge.weight)
				{
					double oldcost = pathnode[edge.v2].cost;
					int oldprev = pathnode[edge.v2].prev;
					pathnode[edge.v2].cost =  best.first + edge.weight;
					pathnode[edge.v2].prev =  best.second;

					if(openlist.find(make_pair(oldcost, oldprev)) == openlist.end())
					{
						//Inserts the newpathnode without updating since it was
						openlist.insert(make_pair(pathnode[edge.v2].cost, pathnode[edge.v2].prev));
					}
					else
					{
						openlist.erase(openlist.find(make_pair(oldcost, oldprev)));
						openlist.insert(make_pair(pathnode[edge.v2].cost, pathnode[edge.v2].prev));
					}
				}
		}

	}
	cout << "\nShortest Paths:" << endl;
	for(int i = 0; i < numVertices; i++)
	{
		//This is the output for every start node
		if(i != source)
		cout << i << " cost: " << pathnode[i].cost << "   prev: " << pathnode[i].prev << endl;
		else
		cout << i << " cost: 0     prev: -1" << endl;
	}

}



