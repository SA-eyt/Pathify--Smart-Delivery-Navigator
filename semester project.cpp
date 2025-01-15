#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
//Collective Code
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
//Mehwish code
    void dijkstra(int source, int destination, string arr[7], float fuelRate, float speed)
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

                if (!visited[v] && adjMatrix[u][v] != 0 && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adjMatrix[u][v];
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
//Sabeeh code
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
};
//Mehwish code
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
string sanitizeInput(std::string input) {
    // Convert to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Remove all spaces
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    return input;
}
int main()
{
    Graph G(8);
    setting(&G);
    string arr[8] = {"lassani", "zafar restaurant", "fresco", "muhammadi town", "azeem wala", "bilal town", "ali town", "shaheen town"};
    string str1, str2;
    int destination, source;

    float fuelRate,speed;

    do
    {
        destination = 0;
        source = 0;
        cout << "Enter current location : ";
        getline(cin, str1);str1 = sanitizeInput(str1);
        destination = index(arr, str1);
        if (destination != 8)
        {
            cout << "Enter source place: ";
            getline(cin, str2);
            str2 = sanitizeInput(str2);
            source = index(arr, str2);
            cout << "Enter fuel rate in (km/liters) : ";
            cin >> fuelRate;
            cout << "Enter average speed (km/h): ";
            cin >> speed;
            cout<<endl;
        }

    }
    while (destination == 8 || source == 8);

    G.dijkstra(source, destination, arr, fuelRate, speed);

    return 0;
}
