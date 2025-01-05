#include <iostream>
#include <string>
#include <limits>
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
    static const int INF = numeric_limits<int>::max();

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
//Mehwish code
    void dijkstra(int source, int destination, string arr[], float fuelRate, float speed)
    {
        float dist[n];
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

            Node* temp = adjList[u];
            while (temp)
            {
                int v = temp->vertex;
                float weight = temp->weight;
                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
                temp = temp->next;
            }
        }
        printShortestPath(source, destination, parent, dist, fuelRate, speed, arr);
    }

private:
    int minDistance(float dist[], bool visited[])
    {
        float min = INF;
        int minIndex;

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
//Sabeeh Code
    void printShortestPath(int source, int destination, int parent[], float dist[], float CurrentFuel, float AverageSpeed, string arr[])
    {
        if (dist[destination] == INF)
        {
            cout << "No path exists from " << arr[source] << " to " << arr[destination] << endl;
            return;
        }

        float Distance = dist[destination];
        float FuelConsumption = Distance / CurrentFuel;
        float RequiredTime = Distance / AverageSpeed;

        cout << "Shortest distance from " << arr[source] << " to " << arr[destination] << " is " << Distance << " km." << endl;
        cout << "Fuel Consumption will be: " << FuelConsumption << " liters." << endl;
        cout << "Time Required is: " << RequiredTime << " hours." << endl;

        if (FuelConsumption > CurrentFuel)
        {
            cout << "WARNING: Your current fuel (" << CurrentFuel << " liters) is insufficient to reach the destination. Refuel before starting the trip." << endl;
        }
        else
        {
            cout << "You have enough fuel to reach the destination." << endl;
        }
//Mehwish code
        cout << "Path TO FOLLOW: Start)->(";
        int path[100]; // Fixed-size array to store the path
        int pathLength = 0;

        int current = destination;
        while (current != -1)
        {
            path[pathLength++] = current;
            current = parent[current];
        }

        for (int i = pathLength - 1; i >= 0; i--)
        {
            cout << arr[path[i]];
            if (i > 0)
                cout << ")->(";
        }
        cout << ")->(End)" << endl;
    }
};
//Sabeeh Code
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
//Tayyaba code
int index(string arr[], string strin)
{
    for (int i = 0; i < 8; i++)
    {
        if (strin == arr[i])
        {
            return i;
        }
    }
    cout << "Sorry! This place is not available. Try Again" << endl;
    return 8;
}

int main()
{
    Graph G(8);
    setting(&G);
    string arr[8] = {"lassani", "zafar restaurant", "fresco", "muhammadi town", "azeem wala", "bilal town", "ali town", "shaheen town"};
    string str;
    int source, destination;
    float CurrentFuel, averageSpeed;

    do
    {
        source = destination = 0;
        cout << "Enter current location: ";
        getline(cin, str);
        source = index(arr, str);
        if (source != 8)
        {
            cout << "Enter destination place: ";
            cin >> str;
            cin.ignore();
            destination = index(arr, str);
            cout << "Enter the current fuel of your delivery bike in liters: ";
            cin >> CurrentFuel;
            cout << "Enter the average speed of the bike (km per hour): ";
            cin >> averageSpeed;
        }
    } while (source == 8 || destination == 8);

    G.dijkstra(source, destination, arr, CurrentFuel, averageSpeed);

    return 0;
}
