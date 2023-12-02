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

struct arrow {
    int id;
    node* start;
    node* end;
};

int finder(int num, vector<arrow> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i].id == num) {
            return i;
        }
    }
}

int corto(vector<int>& t, vector<int>& e) {
    vector<node*> graph(2);
    vector<arrow> arrows;

    node* newNode = new node;
    node* node2 = new node;

    newNode->connections.push_back(node2);

    newNode->num = 1;
    node2->num = 2;

    graph[0] = newNode;
    graph[1] = node2;

    arrow newArrow;
    newArrow.start = newNode;
    newArrow.end = node2;
    newArrow.id = 1;

    arrows = {newArrow};

    int currentNum = 3;
    int currentId = 2;
    // armar
    for (int i = 0; i < t.size(); i++) {
        // serie
        if (t[i] == 1) {
            int ind = finder(e[i], arrows);
            int id = arrows[ind].id;
            node* start = arrows[ind].start;
            node* end = arrows[ind].end;

            //cout << start->num << " " << end->num << endl;

            // borrar su conexion
            findAndErase(start, end);

            // nuevo nodo
            newNode = new node;
            graph.push_back(newNode);

            // conectar
            start->connections.push_back(newNode);
            newNode->connections.push_back(end);

            // flechas
            arrows.erase(arrows.begin() + ind);

            arrow newArrow;

            newArrow.id = id;
            newArrow.start = newNode;
            newArrow.end = end;
            arrows.push_back(newArrow);

            newArrow.id = currentId;
            newArrow.start = start;
            newArrow.end = newNode;
            arrows.push_back(newArrow);

            newNode->num = currentNum;
            currentNum++;

            currentId++;
        } else {
            // paralelo
            int ind = finder(e[i], arrows);
            node* start = arrows[ind].start;
            node* end = arrows[ind].end;

            //cout << start->num << " " << end->num << endl;

            newNode = new node;

            graph.push_back(newNode);

            start->connections.push_back(newNode);
            newNode->connections.push_back(end);

            // flechas
            arrow newArrow;

            newArrow.id = currentId;
            newArrow.start = start;
            newArrow.end = newNode;
            arrows.push_back(newArrow);

            newArrow.id = currentId + 1;
            newArrow.start = newNode;
            newArrow.end = end;
            arrows.push_back(newArrow);

            newNode->num = currentNum;
            currentNum++;
            currentId += 2;
        }

        /*for (arrow x : arrows) {
            cout << x.id << " " << x.start->num << " " << x.end->num << endl;
        }
        cout << currentId << endl;
        cout << "----------" << endl;*/
    }

    // djkistra
    vector<node*> toExplore = {graph[0]};
    graph[0]->distance = 0;

    while (!toExplore.empty()) {
        bool shouldBreak = false;

        for (node* conn : toExplore[0]->connections) {
            float newDistance = toExplore[0]->distance + 1;
            if (newDistance < conn->distance) {
                conn->distance = newDistance;
                if (conn->num == 2) {
                    shouldBreak = true;
                    break;
                }
                toExplore.push_back(conn);
            }
        }

        if (shouldBreak) break;

        toExplore.erase(toExplore.begin());
    }


    return graph[1]->distance;
}

/*int main()
{
    //corto({1}, {1});
    cout << corto({2, 1}, {1, 1});
    //cout << "Hello world!" << endl;
    return 0;
}*/
