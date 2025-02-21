#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int corto(vector<int> &t, vector<int> &e) {
    // armar grafo
	vector<vector<int> > grr(2+1);
	vector<int> dists(2+1);
	vector<pair<int, int> > flecha(2);
	flecha[1] = {1, 2};
	grr[1].push_back(2);
	for (int i = 0; i<t.size(); i++) {
		int n = grr.size()-1;
		//int s = flecha.size()-1;
		int op = t[i];
		auto &f = flecha[e[i]];
		if (op == 1) {
			grr.push_back({f.second});
			grr[f.first].erase(find(grr[f.first].begin(), grr[f.first].end(), f.second));
			grr[f.first].push_back(n+1);
			flecha.push_back({f.first, n+1});
			f.first = n+1;
		}
		else if (op == 2) {
			grr.push_back({f.second});
			grr[f.first].push_back(n+1);
			flecha.push_back({f.first, n+1});
			flecha.push_back({n+1, f.second});
		}
	}
    // bfs
    vector<int> dist(grr.size(), -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
	while (!q.empty()) {
		int a = q.front();
		for (int c: grr[a]) {
			if (dist[c] == -1 || dist[a] + 1 < dist[c]) {
				q.push(c);
				dist[c] = dist[a] + 1;
			}
		}
	}
	return dist[2];
}
