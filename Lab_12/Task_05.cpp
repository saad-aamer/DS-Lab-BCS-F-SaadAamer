#include <iostream>
#include <queue>
using namespace std;

#define MAX_NODES 5

struct Node {
    int vertex;
    Node* next;
};

Node* graphList[MAX_NODES + 1];
int graphMatrix[MAX_NODES + 1][MAX_NODES + 1];

void addConnection(int u, int v) {
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->next = graphList[u];
    graphList[u] = newNode;

    newNode = new Node();
    newNode->vertex = u;
    newNode->next = graphList[v];
    graphList[v] = newNode;

    graphMatrix[u][v] = 1;
    graphMatrix[v][u] = 1;
}

void BFS(int startNode) {
    bool visited[MAX_NODES + 1] = {false};
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "\nBFS Order: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        Node* temp = graphList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                q.push(temp->vertex);
            }
            temp = temp->next;
        }
    }
}

bool visitedDFS[MAX_NODES + 1];

void DFS(int node) {
    visitedDFS[node] = true;
    cout << node << " ";

    Node* temp = graphList[node];
    while (temp != NULL) {
        if (!visitedDFS[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

void showList() {
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= MAX_NODES; i++) {
        cout << i << " -> ";
        Node* temp = graphList[i];
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

void showMatrix() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= MAX_NODES; i++) {
        for (int j = 1; j <= MAX_NODES; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    for (int i = 1; i <= MAX_NODES; i++) {
        graphList[i] = NULL;
        for (int j = 1; j <= MAX_NODES; j++)
            graphMatrix[i][j] = 0;
    }

    addConnection(1, 4);
    addConnection(2, 4);
    addConnection(4, 5);
    addConnection(2, 5);
    addConnection(3, 5);

    showList();
    showMatrix();

    BFS(1);

    cout << "\nDFS Order: ";
    for (int i = 1; i <= MAX_NODES; i++)
        visitedDFS[i] = false;
    DFS(1);

    cout << endl;
    return 0;
}
