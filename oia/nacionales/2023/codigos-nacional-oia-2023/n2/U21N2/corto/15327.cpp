#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define paint pair<int, int>

using namespace std;

vector<paint> s = vector<paint>(1);
vector<vector<int>> adj;
queue<paint> q;
vector<bool> visited;

void sexp(int i);
void pexp(int i);

int n = 2;

/* DEBUG
void printArrow(int i)
{
    cout << i << ": " << s[i].first << "->" << s[i].second << endl;
}
*/

int corto(vector<int> &t, vector<int> &e)
{
    s.push_back(paint(1, 2));
    //printArrow(1);

    for (int i = 0; i < (int)t.size(); ++i)
    {
        if (t[i] == 1)
            sexp(e[i]);
        else
            pexp(e[i]);
    }

    /* DEBUG
    cout << "s passed" << endl;

    for (int i = 1; i < s.size(); ++i)
        printArrow(i);
    */

    adj = vector<vector<int>>(n+1);
    for (auto i : s)
        adj[i.first].push_back(i.second);

    /* DEBUG
    for (int i = 1; i < adj.size(); ++i)
    {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    cout << "adj passed" << endl;
    */

    visited = vector<bool>(n+1);
    
    int cs = 1;
    int depth = 0;
    visited[1] = true;

    while (cs != 2)
    {
        for (auto i : adj[cs])
            if (!visited[i])
            {
                q.push(paint(i, depth));
                visited[i] = true;
            }

        cs = q.front().first;
        depth = q.front().second + 1;
        q.pop();
    }
    return depth;
}

void sexp(int i)
{
    s.push_back(paint(s[i].first, ++n));
    s[i].first = n;
}

void pexp(int i)
{
    s.push_back(paint(s[i].first, ++n));
    s.push_back(paint(n, s[i].second));
}
