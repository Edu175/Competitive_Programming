#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node {
    int num;
    float distance = INFINITY;
    vector<node*> connections;
};

void findAndErase(node* a, node* b) {
    for (int i = 0; i < a->connections.size(); i++) {
        if (a->connections[i] == b) {
            a->connections.erase(a->connections.begin() + i);
            break;
        }
    }
}

int corto(vector<int>& t, vector<int>& e) {
    vector<node*> graph(2);
    vector<pair<node*, node*>> arrows;

    node* newNode = new node;
    node* node2 = new node;

    newNode->connections.push_back(node2);

    newNode->num = 1;
    node2->num = 2;

    graph[0] = newNode;
    graph[1] = node2;

    arrows.push_back({newNode, node2});

    int currentNum = 3;
    // armar
    for (int i = 0; i < t.size(); i++) {
        // serie
        if (t[i] == 1) {
            node* start = arrows[e[i] - 1].first;
            node* end = arrows[e[i] - 1].second;

            // borrar su conexion
            findAndErase(start, end);

            // nuevo nodo
            newNode = new node;
            graph.push_back(newNode);

            // conectar
            start->connections.push_back(newNode);
            newNode->connections.push_back(end);

            // flechas
            arrows.erase(arrows.begin() + i);

            arrows.push_back({newNode, end});
            arrows.push_back({start, newNode});

            newNode->num = currentNum;
            currentNum++;
        } else {
            // paralelo
            node* start = arrows[e[i] - 1].first;
            node* end = arrows[e[i] - 1].second;

            // conectar
            newNode = new node;

            graph.push_back(newNode);

            start->connections.push_back(newNode);
            newNode->connections.push_back(end);

            // flechas
            arrows.push_back({start, newNode});
            arrows.push_back({newNode, end});

            newNode->num = currentNum;
            currentNum++;
        }
    }

    // djkistra
    vector<node*> toExplore = {graph[0]};
    graph[0]->distance = 0;

    while (!toExplore.empty()) {
        for (node* conn : toExplore[0]->connections) {
            float newDistance = toExplore[0]->distance + 1;
            if (newDistance < conn->distance) {
                conn->distance = newDistance;
                toExplore.push_back(conn);
            }
        }

        toExplore.erase(toExplore.begin());
    }


    return graph[1]->distance;
}

/*int main()
{
    cout << corto({2, 2, 2, 2}, {1, 1, 1, 1});
    //cout << "Hello world!" << endl;
    return 0;
}*/
