#include <iostream>
#include <string>
using namespace std;

// Collective Code
struct Node
{
    int vertex, duration;
    float weight;
    Node* next;
    Node(int v, float w)
    {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class Graph
{
public:
    int n;
    Node** adjList;
    static const int INF = 1e9;

    Graph(int nodes)
    {
        n = nodes;
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

    void addEdge(int u, int v, float weight)
    {
        Node* newNode = new Node(v, weight);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = new Node(u, weight);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
 void dijkstra(int source, int destination, string locations[], float currentFuel, float averageSpeed)
    {
        int dist[n];
        bool visited[n];
        int parent[n];

        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[source] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        printShortestPath(source, destination, parent, dist, currentFuel, averageSpeed, locations);
    }

private:
    int minDistance(int dist[], bool visited[])
    {
        int min = INF, minIndex = -1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < min)
            {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    void printShortestPath(int source, int destination, int parent[], int dist[], float fuelRate, float speed, string arr[])
    {
        if (dist[destination] == INF)
        {
            cout << "No path exists from " << arr[source] << " to " << arr[destination] << endl;
            return;
        }

        float distance = dist[destination];
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

        cout << "Path to follow: ";
        int current = destination;
        while (current != -1)
        {
            cout << arr[current];
            current = parent[current];
            if (current != -1) cout << " -> ";
        }
        cout << endl;
    }
};

void setting(Graph* G)
{
    G->addEdge(0, 4, 7);
    G->addEdge(0, 3, 10);
    G->addEdge(0, 7, 13);
    G->addEdge(0, 5, 3);
    G->addEdge(1, 7, 4);
    G->addEdge(1, 5, 5);
    G->addEdge(1, 6, 5);
    G->addEdge(1, 3, 5);
    G->addEdge(1, 4, 10);
    G->addEdge(2, 7, 5);
    G->addEdge(2, 5, 6);
    G->addEdge(2, 6, 6);
    G->addEdge(2, 3, 6);
    G->addEdge(2, 4, 11);
}

int index(string arr[], string strin, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strin == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Graph G(8);
    setting(&G);

    string locations[8] = {"lassani", "zafar restaurant", "fresco", "muhammadi town", "azeem wala", "bilal town", "ali town", "shaheen town"};

    string sourceStr, destStr;
    int source, destination;
    float currentFuel, averageSpeed;

    cout << "Enter current location: ";
    getline(cin, sourceStr);
    source = index(locations, sourceStr, 8);
    if (source == -1)
    {
        cout << "Invalid location. Exiting program." << endl;
        return 1;
    }

    cout << "Enter destination: ";
    getline(cin, destStr);
    destination = index(locations, destStr, 8);
    if (destination == -1)
    {
        cout << "Invalid location. Exiting program." << endl;
        return 1;
    }

    cout << "Enter current fuel in liters: ";
    cin >> currentFuel;
    cout << "Enter average speed (km/h): ";
    cin >> averageSpeed;

    G.dijkstra(source, destination, locations, currentFuel, averageSpeed);

    return 0;
}
