#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Graph
{
public:
    int n;
    int** adjMatrix;
    Node** adjList;

    static const int INF = 1e9;

    Graph(int nodes)
    {
        n = nodes;
        adjMatrix = new int*[n];
        for (int i = 0; i < n; i++)
        {
            adjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }

        adjList = new Node*[n];
        for (int i = 0; i < n; i++)
        {
            adjList[i] = NULL;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        for (int i = 0; i < n; i++)
        {
            Node* current = adjList[i];
            while (current)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;

        Node* newNode = new Node(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
        newNode = new Node(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
        float distance = dist[source];
        float fuelConsumption = distance / fuelRate;
        float requiredTime = distance / speed;

        cout << "Shortest distance from " << arr[source] << " to " << arr[destination] << " is " << distance << " Km." << endl;
        cout << "Fuel Consumption: " << fuelConsumption << " liters." << endl;
        cout << "Time Required: " << requiredTime << " hours." << endl;

        if (fuelRate < fuelConsumption)
        {
            cout << "WARNING: Your current fuel (" << fuelRate << " liters) is insufficient. Refuel before starting the trip." << endl;
        }
        else
        {
            cout << "You have enough fuel to reach the destination." << endl;
        }

        cout << "Path TO FOLLOW: Start -> ";
        int current = source;
        while (current != -1)
        {
            cout << arr[current] << " -> ";
            current = parent[current];
        }
        cout << " End" << endl;
    }
