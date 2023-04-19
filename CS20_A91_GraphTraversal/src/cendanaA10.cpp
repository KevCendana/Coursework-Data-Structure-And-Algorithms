#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
	int vertexValue;
	bool visited;
	vector<int>neighbors;
};

void buildGraph (vector <Vertex> &graph);
int vertexIndex (vector <Vertex> name, int value);
void dft (vector <Vertex> graph);
void dftInternal(vector <Vertex> &graph, int vPos);
void bft (vector <Vertex> graph);

int main()
{
	vector<Vertex> graph;
	buildGraph(graph);
	dft(graph);
	cout << endl;
	bft(graph);
	cout << endl;
	cout << "Have a great day :)";
	return 0;
}

void buildGraph (vector <Vertex> &graph)
{
	cout << "Populated graph: " << endl;
	cout << endl;
	fstream file;
	file.open("a10data.txt");
	string line;
	int i;
	bool start = true;

	if (file.fail())
	{
		cout << "Could not open file :(" << endl;
	}
	else
	{
		Vertex v;
		while(!file.eof())
		{
			file >> i;
			if (start == true && i != -1)
			{
				//cout << "vertex: " << i << " ";
				v = Vertex();	//Refresh v
				v.vertexValue = i;
				start = false;
			}
			else if (start == false && i != -1)
			{
				//cout << "neighbor: " << i << " ";
				v.neighbors.push_back(i);
			}
			else if (i == -1)
			{
				//cout << "restart: " << i << endl;
				start = true;
				graph.push_back(v);
			}
		}
	}

	file.close();

	for (unsigned int i = 0; i < graph.size(); i++)
	{
		cout << "vertex number " << i << " ";
		cout << "value " << graph[i].vertexValue << " ";
		cout << "neighbors-> ";
		if (!graph[i].neighbors.empty())
		{
			for (unsigned int j = 0; j < graph[i].neighbors.size(); j++)
			{
				cout << graph[i].neighbors[j] << " ";
			}
		}
		cout << endl;
	}

	cout << endl;
}

int vertexIndex (vector <Vertex> name, int value)
{
	for (unsigned int i = 0; i < name.size(); i++)
	{
		if (name[i].vertexValue == value)
		{
			return i;
		}
	}
	return -1;
}

void dft (vector <Vertex> graph)
{
	 cout << "Depth-first traversal: " << endl;
	cout << endl;

	//set all vertices as unvisited
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		graph[i].visited = false;
	}

	//position at first vertex in the graph
	unsigned int visitedCount = 0;
	int currentIndex = 0;

	//loop through graph and call dft internal on non visited vertexes
	while (visitedCount < graph.size())
	{
		if (graph[currentIndex].visited == false)
		{
			dftInternal(graph, currentIndex);
		}
		currentIndex++;
		visitedCount++;
	}
	cout << endl;
}

void dftInternal(vector <Vertex> &graph, int vPos)
{
	//print and visit vertex
	if (graph[vPos].visited == false)
	{
		cout << graph[vPos].vertexValue << " ";
	}
	graph[vPos].visited = true;

	//check current for neighbors
	if (graph[vPos].neighbors.size() > 0)
	{
		//loop through neighbors if they have any
		unsigned int neighborCount = 0;
		while (neighborCount < graph[vPos].neighbors.size())
		{
			//find position of neighbor using vertexIndex and change it to current
			int neighborPos = vertexIndex(graph, graph[vPos].neighbors[neighborCount]);

			if (graph[neighborPos].visited == false)
			{
				dftInternal(graph, neighborPos);
			}
			neighborCount++;
		}
	}
}

void bft (vector <Vertex> graph)
{
	cout << "Breadth-first traversal" << endl;
	cout << endl;

	//set all vertexes as unvisited
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		graph[i].visited = false;
	}

	queue <Vertex> q;
	q.push(graph[0]);
	graph[0].visited = true;
	cout << graph[0].vertexValue << " ";

	while (!q.empty())
	{
		//get index of front vertex in queue
		int front = vertexIndex(graph, q.front().vertexValue);

		//loop through neighbors if they have any
		if (graph[front].neighbors.size() > 0)
		{
			unsigned int neighborCount = 0;
			while (neighborCount < graph[front].neighbors.size())
			{
				//find position of neighbor using vertexIndex and add them to the queue
				int neighborPos = vertexIndex(graph, graph[front].neighbors[neighborCount]);
				if (graph[neighborPos].visited == false)
				{
					graph[neighborPos].visited = true;
					cout << graph[neighborPos].vertexValue << " ";
					q.push(graph[neighborPos]);
				}
				neighborCount++;
			}
		}
		//pop front of queue to move on to next vertex
		if (q.size() > 0)
		{
			q.pop();
		}
		//reach remaining nodes that are not neighbors to anything
		if (q.empty())
		{
			for (unsigned int i = 0; i < graph.size(); i++)
			{
				if (graph[i].visited == false)
				{
					cout << i << " ";
				}
			}
		}
	}

	cout << endl;
}
