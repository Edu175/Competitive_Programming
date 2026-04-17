#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#ifdef PROBANDO_JIJIJIAJAJAJA
#include <iostream>
#endif

using namespace std;

bool pred(const int &a)
{
    return a == 1;
}

int posToMatch;

bool pred2(const pair<int, int> &a)
{
    return a.first == posToMatch;
}

int corto(vector<int> &commands, vector<int> &arguments)
{
    int numNodes = 2;
    vector<pair<int, int>> connections(1, {0, 1});
    for (size_t i = 0; i < commands.size(); i++)
    {

        // cout << numNodes << '\n';

        // for (auto connection : connections)
        // {
        //     cout << "From " << connection.first + 1 << " to " << connection.second + 1 << '\n';
        // }
        // cout << '\n';
        // fflush(stdout);

        int command = commands[i];
        int connectionIdx = arguments[i] - 1;
        switch (command)
        {
        case 1:
        {
            int acc = connections[connectionIdx].first;
            connections[connectionIdx].first = numNodes;
            connections.push_back({acc, numNodes++});
            break;
        }
        case 2:
        {
            auto connectionBase = connections[connectionIdx];
            connections.push_back({connectionBase.first, numNodes});
            connections.push_back({numNodes++, connectionBase.second});
        }

        default:
            break;
        }
    }

    vector<int> graph(numNodes, -1);
    graph[0] = 0;
    vector<bool> visited(numNodes, false);
    queue<int> q;
    q.push(0);
    while (q.empty() == false)
    {
        int current = q.front();
        q.pop();
        posToMatch = current;
        size_t startIdx = 0;
        pair<int, int> found;
        bool foundAll = false;
        while (!foundAll)
        {
            foundAll = true;
            for (size_t i = startIdx; i < connections.size(); i++)
            {
                if (pred2(connections[i]))
                {
                    foundAll = false;
                    found = connections[i];
                    startIdx = i + 1;
                    break;
                }
            }
            if (foundAll)
                break;
            q.push(found.second);
            int newCost = graph[current] + 1;
            if (newCost < graph[found.second] || graph[found.second] == -1)
            {
                graph[found.second] = newCost;
            }
        }
    }

    return graph[1];
}
