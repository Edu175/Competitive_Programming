#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#ifdef PROBANDO_JIJIJIAJAJAJA
#include <iostream>
#endif

using namespace std;

bool pred(const int &a)
{
    return a == 1;
}

int posToMatch;

int comp(const void *a, const void *b)
{
    auto arg1 = (*(const pair<int, int> *)a).first;
    auto arg2 = (*(const pair<int, int> *)b).first;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
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

    qsort(connections.begin().base(), connections.size(), sizeof(pair<int, int>), comp);
    vector<int> graph(numNodes, -1);
    graph[0] = 0;
    queue<int> q;
    vector<bool> visited(numNodes, false);
    q.push(0);
    while (q.empty() == false)
    {
        for (auto g : graph)
        {
            printf("%2d ", g);
        }
        printf("\n");
        int current = q.front();
        q.pop();
        if (visited[current] == true)
        {
            continue;
        }
        bool foundAll = false;
        vector<bool> alreadyAdded(numNodes, false);

        while (!foundAll)
        {
            foundAll = true;
            int lo = -1;
            int hi = connections.size() + 1;
            while (hi - lo > 1)
            {
                int mid = (hi + lo) / 2;
                if (connections[mid].first <= current && alreadyAdded[connections[mid].second] == false)
                {
                    lo = mid;
                }
                else
                {
                    hi = mid;
                }
            }
            float res = ((float)hi + (float)lo) / 2.0;
            if (res < 0 || res >= connections.size())
            {
                break;
            }
            else
            {
                foundAll = false;
            }
            auto found = connections[res];
            if (visited[res] == false && alreadyAdded[res] == false)
            {
                q.push(found.second);
            }
            alreadyAdded[found.second] = true;
            int newCost = graph[current] + 1;
            if (newCost < graph[found.second] || graph[found.second] == -1)
            {
                graph[found.second] = newCost;
            }
        }
        visited[current] = true;
    }

    for (auto g : graph)
    {
        cout << g << ' ';
    }

    return graph[1];
}
