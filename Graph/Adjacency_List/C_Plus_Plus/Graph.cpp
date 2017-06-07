// This is a inital Adjaceny List presentation 
// of a Graph
#include<iostream>
#include<map>
#include<list>
#include<iterator>
#include<algorithm>


using namespace std;

class Graph
{
private:
	map<int, list<int> > edges = {};

public:
	// Read the Intialized Graph and Create a Adjacency list out of it 
	// There could be cases where in the initialized graph <map> link issues are not maintained
	// for example node 2 to 1 link 
	// 2->1
	//there needs to be a link then since undirected Graph
	// 1->2
	Graph(map<int,list<int> > edges)
	{
		cout << "Graph is initialized"<<endl;
		//this->edges = edges;
		for (auto it : edges)
		{
			for (auto di = it.second.begin(); di != it.second.end(); di++)
			{
				addEdge(it.first, *di);
			}
		}

	}
	//Add a vertex to graph map
	//structure is
	// int => int list
	void addVertex(int vertex)
	{
		auto search = edges.find(vertex);
		if (search != edges.end()) {
			std::cout << "Already present  " << search->first <<endl;
		}
		else
		{
			list<int> A;
			edges[vertex] = A;
		}
	
	}

	//Add Edge from both vertex to each other
	// Make sure the nodes are present 
	void addEdge(int vertex1, int vertex2)
	{
		addVertex(vertex1);
		addVertex(vertex2);
		if (find(edges[vertex1].begin(), edges[vertex1].end(), vertex2) == edges[vertex1].end())
		{
			edges[vertex1].push_back(vertex2);
		}
		if (find(edges[vertex2].begin(), edges[vertex2].end(), vertex1) == edges[vertex2].end())
		{
			edges[vertex2].push_back(vertex1);
		}
	
	}

	//Display the graph with vertex and edges 
	void display()
	{
		for (auto it:edges)
		{
			cout << it.first << "::";
			for (auto di = it.second.begin(); di != it.second.end(); di++)
			{
				cout << "=>" << *di;
			}
			cout << endl;
		}
	}

};

int main()
{
	//A initalized Graph (not in form of adjaceny list
	map<int, list<int> > graph{ { 3, {2} },
								{ 4, {5} },
								{ 5, {6} },
								{ 6, {7} },
								{ 7, {7} },
								{ 8, {6} }
	                          };
	//Default constrcutor takes care of making the initialzed map to adjaceny list
	Graph g(graph);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(4);
	g.addEdge(1, 2);
	g.addEdge(2, 2);
	g.addEdge(2, 3);
	g.display();

	
    return 0;
}

