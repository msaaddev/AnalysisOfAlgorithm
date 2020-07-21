/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Graph Task: 1

=================================================*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// function prototypes
void readData(int &numOfVertices, int &isDirected, char vertices[], int &numOfEdges, char edges[][100]);
void neighbor(char edges[][100], char vertice, int numOfVertices);
void UI();

int main()
{
	// variable declaration
	int numOfVertices, isDirected, numOfEdges;
	char vertices[100];
	char edges[100][100] = {'/'};
	int option = 0;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			edges[i][j] = '/';

	// reading data from the external file
	readData(numOfVertices, isDirected, vertices, numOfEdges, edges);

	UI();
	cin >> option;

	// dealing with edge case
	if (option > 4)
	{
		cout << "Incorrect Option. Exiting the program.";
		return 0;
	}

	// switching to appropriate action according to user input
	switch (option)
	{
	case 1:
		cout << "\n There are " << numOfVertices << " vertices.";
		break;
	case 2:
		cout << "\n There are " << numOfEdges << " edges.";
		break;
	case 3:
		if (isDirected)
			cout << "\nYes, the graph is directed.";
		else
			cout << "\nNo, the graph is not directed.";
		break;
	case 4:
		char vertice;
		cout << "\nEnter the vertice you want to see the neighbor of: ";
		cin >> vertice;
		neighbor(edges, vertice, numOfVertices);
		break;
	}
}

/**
 *
 *
 * @param numOfVertices - An integer variable to store total number of vertices
 * @param isDirected - An integer variable to see if the graph is directed or not
 * @param vertices - A char array to store vertices
 * @param numOfEdges - An integer to store total number of edges
 * @param edges - A 2D array to store edges of the graph
 */

void readData(int &numOfVertices, int &isDirected, char vertices[], int &numOfEdges, char edges[][100])
{
	string data;
	char underscore;

	// opening file data.txt and extracting data
	ifstream read;
	read.open("data.txt");

	read >> numOfVertices;
	read >> underscore;
	read >> isDirected;

	for (int i = 0; i < numOfVertices; i++)
	{
		read >> vertices[i];
		edges[i][0] = vertices[i];
	}

	read >> numOfEdges;

	// extracting and assigning edges to approprate vertices
	if (isDirected)
	{

		for (int i = 0; i < numOfEdges; i++)
		{
			bool check = true;
			char firstEdge, nextEdge;
			read >> firstEdge;
			read >> nextEdge;

			for (int j = 0; j < numOfVertices; j++)
			{
				if (edges[j][0] == nextEdge)
				{
					int counter = 0;
					while (edges[j][counter] != '/')
					{
						if (edges[j][counter] == firstEdge)
						{
							check = false;
							break;
						}
						counter++;
					}
				}
			}

			if (check)
			{
				for (int j = 0; j < numOfVertices; j++)
					if (edges[j][0] == firstEdge)
					{
						int counter = 1;
						while (edges[j][counter] != '/')
							counter++;
						edges[j][counter] = nextEdge;
					}
			}
		}
	}
	else
	{
		for (int i = 0; i < numOfEdges; i++)
		{
			char checkEdge;
			read >> checkEdge;

			for (int j = 0; j < numOfVertices; j++)
				if (edges[j][0] == checkEdge)
				{
					int counter = 1;
					while (edges[j][counter] != '/')
						counter++;
					read >> edges[j][counter];
				}
		}
	}

	read.close();
}

/**
 *
 *
 * @param edges - 2D array that stores our edges
 * @param vertic - vertice of which we want to see edges
 * @param numOfVertices - total number of vertices in the graph
 */

void neighbor(char edges[][100], char vertice, int numOfVertices)
{
	// extracting the edges of a vertice
	for (int i = 0; i < numOfVertices; i++)
	{
		if (edges[i][0] == vertice)
		{
			int counter = 1;
			cout << "Its neighbor/s are ";
			while (edges[i][counter] != '/')
			{
				cout << edges[i][counter] << " ";
				counter++;
			}
		}
	}
}

/**
 *
 *
 * interface of the CLI
 */

void UI()
{
	cout << "\n*********************** Menu *************************\n";
	cout << "1. How many Vertices are there?\n";
	cout << "2. How many Edges are there?\n";
	cout << "3. Is the Graph directed?\n";
	cout << "4. Which are the neighbor of any Vertex?\n";
	cout << "\nSelect any option: ";
}
