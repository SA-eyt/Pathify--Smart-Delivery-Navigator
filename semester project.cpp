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

    void addEdge(int u, int v, int weight)
    {
        Node* newNode = new Node(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
        newNode = new Node(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    void dijkstra(int destination, int source, string arr[7], float fuelRate, float speed)
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

        dist[destination] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && adjList[u][v] && dist[u] != INF && dist[u] + adjList[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adjList[u][v];
                    parent[v] = u;
                }
            }
        }

        printShortestPath(destination, source, parent, dist, arr, fuelRate, speed);
    }

private:
    int minDistance(int dist[], bool visited[])
    {
        int min = INF, minIndex;

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

    void printShortestPath(int destination, int source, int parent[], int dist[], string arr[7], float fuelRate, float speed)
    {
        if (dist[source] == INF)
        {
            cout << "No path exists from " << arr[destination] << " to " << arr[source] << endl;
            return;
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
        cout << "End" << endl;
    }
};

void setting(Graph* G)
{
    G->addEdge(0, 4, 7.5);
    G->addEdge(0, 3, 10.1);
    G->addEdge(0, 7, 13);
    G->addEdge(0, 5, 2.8);
    G->addEdge(1, 7, 3.7);
    G->addEdge(1, 5, 5.3);
    G->addEdge(1, 6, 4.7);
    G->addEdge(1, 3, 4.5);
    G->addEdge(1, 4, 9.9);
    G->addEdge(2, 7, 4.6);
    G->addEdge(2, 5, 6.2);
    G->addEdge(2, 6, 5.6);
    G->addEdge(2, 3, 5.4);
    G->addEdge(2, 4, 10.2);
}

int index(string arr[8], string strin)
{
    for (int i = 0; i < 8; i++)
    {
        if (strin == arr[i])
        {
            return i;
        }
    }
    cout << "Sorry! This place is not available. Try Again." << endl;
    return 8;
}

int main()
{
    Graph G(8);
    setting(&G);
    string arr[8] = {"lassani", "zafar restaurant", "fresco", "muhammadi town", "azeem wala", "bilal town", "ali town", "shaheen town"};
    string str1, str2;
    int destination, source;

    float fuelRate = 12.0; // Fuel consumption rate (km per liter)
    float speed = 60.0; // Average speed (km per hour)

    do
    {
        destination = 0;
        source = 0;
        cout << "Enter current location : ";
        getline(cin, str1);
        destination = index(arr, str1);
        if (destination != 8)
        {
            cout << "Enter source place: ";
            getline(cin, str2);
            source = index(arr, str2);
        }
    } while (destination == 8 || source == 8);

    G.dijkstra(source, destination, arr, fuelRate, speed);

    return 0;
}
