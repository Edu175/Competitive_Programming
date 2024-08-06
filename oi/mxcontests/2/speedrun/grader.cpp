/* Input format:
 *
 * N -- number of nodes
 * a1 b1 -- edge 1
 * ...
 * a(N-1) b(N-1) -- edge N - 1
 * x -- start node
 */

#include <iostream>
#include <map>
#include <set>

#include "speedrun.h"
using namespace std;

static map<int, map<int, bool>> mp;
static int length = -1;
static int queries = 0;
static bool length_set = false;
static int current_node = 0;
static set<int> viz;
static map<int, set<int>> neighbours;

void setHintLen(int l) {
    if (length_set) {
        cerr << "Cannot call setHintLen twice" << endl;
        exit(0);
    }
    length = l;
    length_set = true;
}

void setHint(int i, int j, bool b) {
    if (!length_set) {
        cerr << "Must call setHintLen before setHint" << endl;
        exit(0);
    }
    mp[i][j] = b;
}

int getLength() { return length; }

bool getHint(int j) { return mp[current_node][j]; }

bool goTo(int x) {
    if (neighbours[current_node].find(x) == end(neighbours[current_node])) {
        ++queries;
        return false;
    } else {
        viz.insert(current_node = x);
        return true;
    }
}

int main() {
    int N;
    cin >> N;

    int a[N], b[N];
    for (int i = 1; i < N; ++i) {
        cin >> a[i] >> b[i];
        neighbours[a[i]].insert(b[i]);
        neighbours[b[i]].insert(a[i]);
    }

    assignHints(1, N, a, b);

    if (!length_set) {
        cerr << "Must call setHintLen at least once" << endl;
        exit(0);
    }

    cin >> current_node;
    viz.insert(current_node);

    speedrun(1, N, current_node);

    if (viz.size() < N) {
        cerr << "Haven't seen all nodes" << endl;
        exit(0);
    }

    cerr << "OK; " << queries << " incorrect goto's" << endl;
    return 0;
}
