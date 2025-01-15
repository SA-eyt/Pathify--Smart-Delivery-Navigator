//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <System.SysUtils.hpp> // For StrToFloat and other conversions
#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

// Struct for adjacency list node
struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(NULL) {}
};
String fiul,tam,warning,pathh,distanc ;
// Graph class definition
class Graph {
public:
	int n;
    int** adjMatrix;
    Node** adjList;

	static const int INF = 1e9;

	Graph(int nodes) {
		n = nodes;
		adjMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
			for (int j = 0; j < n; j++) {
				adjMatrix[i][j] = 0;
            }
		}

		adjList = new Node*[n];
		for (int i = 0; i < n; i++) {
			adjList[i] = NULL;
		}
    }

    ~Graph() {
		for (int i = 0; i < n; i++) {
			delete[] adjMatrix[i];
		}
		delete[] adjMatrix;

		for (int i = 0; i < n; i++) {
			Node* current = adjList[i];
			while (current) {
                Node* temp = current;
				current = current->next;
                delete temp;
			}
		}
		delete[] adjList;
	}

	void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
		adjMatrix[v][u] = weight;

		Node* newNode = new Node(v);
		newNode->next = adjList[u];
		adjList[u] = newNode;

        newNode = new Node(u);
		newNode->next = adjList[v];
        adjList[v] = newNode;
	}

	void dijkstra(int source, int destination, String arr[7], float fuelRate, float speed) {

			int dist[8];
			  bool visited[8];
			  int parent[8];
		for (int i = 0; i < n; i++) {
			dist[i] = INF;
			visited[i] = false;
			parent[i] = -1;
		}

        dist[source] = 0;

        for (int count = 0; count < n - 1; count++) {
			int u = minDistance(dist, visited);
			visited[u] = true;

            for (int v = 0; v < n; v++) {
				if (!visited[v] && adjMatrix[u][v] != 0 && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
					dist[v] = dist[u] + adjMatrix[u][v];
					parent[v] = u;
				}
			}
		}
			printShortestPath(destination, source, parent, dist, arr, fuelRate, speed);



	}

private:
    int minDistance(int dist[], bool visited[]) {
		int min = INF, minIndex;

		for (int v = 0; v < n; v++) {
			if (!visited[v] && dist[v] < min) {
				min = dist[v];
				minIndex = v;
			}
		}
		return minIndex;
	}
	void printShortestPath(int destination, int source, int parent[], int dist[], String arr[7], float fuelRate, float speed) {
    if (dist[destination] == INF) {
        ShowMessage("No path exists");
        return;
    }

    // Corrected: Access dist[destination] for the distance
    float distance = dist[destination];  // Get the actual distance to the destination
    float fuelConsumption = distance / fuelRate;
    float requiredTime = distance / speed;
    requiredTime=   requiredTime*60;
    distanc = distance;  // Store the correct distance
    fiul = fuelConsumption;
	tam = FormatFloat("0.00", requiredTime);

    // Set the warning if fuel consumption is greater than available fuel
    if (fuelRate < fuelConsumption) {
        warning = "WARNING: Your current fuel is insufficient. Refuel before starting the trip.";
    }

    // Build the path from source to destination
	String path = "";
	int current = destination;
    while (current != -1) {
		path = arr[current] + " -> " +path;  // Prepend to the path
        current = parent[current];  // Use the parent array from your dijkstra function
    }
    path += "End";

    pathh = path;  // Store the path
}
};

// Function to initialize the graph
void setting(Graph* G) {
	G->addEdge(0, 4, 7);
    G->addEdge(0, 3, 10);
	G->addEdge(0, 7, 13);
	G->addEdge(0, 5, 2);
	G->addEdge(1, 7, 3);
    G->addEdge(1, 5, 5);
	G->addEdge(1, 6, 4);
	G->addEdge(1, 3, 4);
    G->addEdge(1, 4, 9);
	G->addEdge(2, 7, 4);
    G->addEdge(2, 5, 6);
	G->addEdge(2, 6, 5);
	G->addEdge(2, 3, 5);
	G->addEdge(2, 4, 10);
}

// Function to find the index of a location
int index(String arr[8], String strin) {
	for (int i = 0; i < 8; i++) {
        if (strin == arr[i]) {
			return i;
		}
	}
    return -1; // Return -1 if not found
}

// Global variables
Graph G(8);
String arr[8] = {"lassani", "zafarrestaurant", "fresco", "muhammaditown", "azeemwala", "bilaltown", "alitown", "shaheentown"};
int destination, source;
float fuelRate, speed;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {setting(&G);Label4->Text="";
Label2->Text="";
		 Label3->Text="";
		 d->Text="";
		 t->Text="";
		 f->Text="";
		 p->Text="";}
String sanitizeInput(String input) {
    // Convert to lowercase
    input = input.LowerCase();

    // Remove all spaces
    input = StringReplace(input, " ", "", TReplaceFlags() << rfReplaceAll);

    return input;
}
// Button click event handler
void __fastcall TForm1::Button1Click(TObject *Sender) {

	String str1, str2;

	// Retrieve input from GUI components
	str1 = sanitizeInput(box->Text);       // Source
str2 = sanitizeInput(boxx->Text);      // Destination


	source = index(arr, str1);
	destination = index(arr, str2);
     if( boxxx->Text=="" || boxxxx->Text=="" || boxx->Text==""|| box->Text=="")
	{
		ShowMessage("Please Fill all the text boxes.!");
		return;
	}
	else if( source == -1)
	{
		ShowMessage("Invalid source!");
		box->Text="";
				boxx->Text="";
				boxxx->Text="";
				boxxxx->Text="";
		return;
	}
	else if(destination == -1)
	{
		 ShowMessage("Invalid destination!");
		 box->Text="";
				boxx->Text="";
				boxxx->Text="";
				boxxxx->Text="";
		 return;
	}

	else{
				fuelRate = StrToFloat(boxxx->Text);
				speed = StrToFloat(boxxxx->Text);
				G.dijkstra(source, destination, arr, fuelRate, speed);
				Label2->Text=str1;
				Label3->Text=str2;
				box->Text="";
				boxx->Text="";
				boxxx->Text="";
				boxxxx->Text="";
				d->Text= distanc;
				f->Text=fiul;
				t->Text=tam;
				Label4->Text=warning;
				 p->Text=pathh;

	}
	}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
		 Label2->Text="";
		 Label3->Text="";
		 d->Text="";
		 t->Text="";
		 f->Text="";
		 p->Text="";
		 box->Text="";
		 boxx->Text="";
		 boxxx->Text="";
		 boxxxx->Text="";
		 Label4->Text="";
}
//---------------------------------------------------------------------------


