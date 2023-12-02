#include <bits/stdc++.h>

using namespace std;

int serieparalelo(vector<int> &t, vector<int> &e){
  return 1;
}

// int serieparalelo(vector<int> &t, vector<int> &e) {
//   const int MOD = 1e9 +7;
//   vector<set<int>> adj = {
//       {},
//       {2},
//       {},
//
//   };
//   vector<vector<int>> edges = {
//     {},
//     {1, 2},
//   };
//   vector<int> indegree = {
//     -1,
//     0,
//     1,
//   };
//   for(int i = 0; i < t.size(); i++){
//     if(t[i] == 1){
//       auto edge = edges[e[i]];
//       edges.push_back({edge[0], adj.size()});
//       edges[e[i]] = {adj.size(), edge[1]};
//       adj[edge[0]].erase(edge[1]);
//       adj[edge[0]].insert(adj.size());
//       adj.push_back({edge[1]});
//       indegree.push_back(1);
//     }else{
//       auto edge = edges[e[i]];
//       edges.push_back({edge[0], adj.size()});
//       edges.push_back({adj.size(), edge[1]});
//       indegree.push_back(1);
//       indegree[edge[1]]++;
//       adj[edge[0]].insert(adj.size());
//       adj.push_back({edge[1]});
//     }
//   }
//   // for(auto a: adj){
//   //   cout << endl;
//   //   for(auto b: a){
//   //     cout << b << " ";
//   //   }
//   // }
//
//   // for(auto a: indegree){
//   //   cout << a << " ";
//   // }
//   // cout << endl;
//
//   queue<int> q;
//   q.push(1);
//   vector<int> pos(adj.size(), 0);
//   pos[1] = 1;
//
//   while(!q.empty()){
//     int curr = q.front(); q.pop();
//     for(auto& neigh: adj[curr]){
//       pos[neigh] = (pos[neigh] + pos[curr])%MOD;
//       indegree[neigh]--;
//       if(indegree[neigh]==0){
//         q.push(neigh);
//       }
//     }
//   }
//
//   return pos[2];
//
// }
