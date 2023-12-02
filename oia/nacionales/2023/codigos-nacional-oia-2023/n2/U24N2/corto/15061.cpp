#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define fst first
#define snd second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
set<ii> bloq;
map<int,ii> edges;
vector<vi> adj;
int corto(vi &t, vi &e) {
	int n = SIZE(t);
	adj.resize(n+3);
	adj[1].push_back(2);
	edges[1] = {1,2};
	int s = 1;
	forn(i, n) {
		int A = edges[e[i]].fst;
		int B = edges[e[i]].snd;
		adj[A].push_back(i+3);
		adj[i+3].push_back(B);
		s++;
		edges[s] = {A, i+3};
		if(t[i]==1) {
			edges[e[i]] = {i+3, B};
			bloq.insert({A,B});
		} else {
			s++;
			edges[s] = {i+3, B};
		}
	}
	queue<int> q;
	vector<bool> vis(n+3, false);
	q.push(1);
	vis[1] = true;
	int dist = 0;
	while(!q.empty()) {
		int sz = SIZE(q);
		forn(_,sz) {
			int u = q.front();
			q.pop();
			if(u == 2) return dist; 
			for(int v:adj[u]) {
				if(bloq.find({u,v}) != bloq.end()) continue;
				if(!vis[v]) q.push(v);
			}
		}
		dist++;
	}
	return dist;
}
