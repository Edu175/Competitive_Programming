#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream input; input.open("input",ios::in);
	
	
	// cerr<<"n is "<<n<<"\n";
    // Initialize RNG
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; input>>t;
	cout<<t<<endl;
	while(t--){
		int n; input>>n;
		// Generate random labels for vertices
	
		set<pair<int, int>> hidden_edges;
		vector<vector<int>> adj(n + 1);
	
		// Generate a random tree
		vector<int> p(n); iota(p.begin(),p.end(),0);
		for (int i = 1; i < n; i++) {
		    int parent = p[uniform_int_distribution<int>(0, i - 1)(rng)];
		    int u = p[i];
		    int v = parent;
		    adj[u].push_back(v);
		    adj[v].push_back(u);
		    if (u > v) swap(u, v);
		    hidden_edges.insert({u, v});
		}
		
		// for(int i = 0; i < n-1; i++){
		// 	int u,v; input>>u>>v; u--,v--;
		// 	adj[u].push_back(v);
		// 	adj[v].push_back(u);
		// 	if (u > v) swap(u, v);
		// 	hidden_edges.insert({u, v});
		// }
		
		// Print the hidden tree to stderr so you can verify your solution's output
		// cerr << "[INTERACTOR] Hidden tree edges: ";
		// for (auto e : hidden_edges) {
		//     cerr << "(" << e.first << ", " << e.second << ") ";
		// }
		// cerr << "\n--------------------------------------------------" << endl;
	
		// Start Interaction (Feed to your solution)
		cout << n << endl; // Size of the tree
	
		int total_k = 0;
		int max_queries_sum = 30 * n;
	
		while (true) {
			string type;
			if (!(cin >> type)) break;
	
			if (type == "?") {
				int k;
				cin >> k;
				total_k += k;
	
				vector<int> a(k);
				for (int i = 0; i < k; i++) {
					cin >> a[i]; a[i]--;
				}
	
				vector<bool> in_S(n + 1, false);
				string s = "";
	
				for (int i = 0; i < k; i++) {
					int v = a[i];
					bool can_add = true;
					
					// Check if any neighbor is already in S
					for (int u : adj[v]) {
						if (in_S[u]) {
							can_add = false;
							break;
						}
					}
					
					if (can_add) {
						in_S[v] = true;
						s += "1";
					} else {
						s += "0";
					}
				}
				// Send the response back to your solution
				cout << s << endl;
	
			} else if (type == "!") {
				set<pair<int, int>> guessed_edges;
				for (int i = 0; i < n - 1; i++) {
					int u, v;
					cin >> u >> v; u--,v--;
					if (u > v) swap(u, v);
					guessed_edges.insert({u, v});
				}
	
				if (guessed_edges == hidden_edges) {
					cerr << "[INTERACTOR] CORRECT! Used total k = " << total_k << " out of " << max_queries_sum << endl;
				} else {
					cerr << "[INTERACTOR] WRONG ANSWER! Edges do not match." << endl;
				}
				break;
			} else {
				cerr << "[INTERACTOR] Invalid query format! Expected '?' or '!'" << endl;
				cout << -1 << endl;
				return 0;
			}
		}
		if (total_k > max_queries_sum) {
			cerr << "[INTERACTOR] LIMIT EXCEEDED! Total k: " << total_k << " > " << max_queries_sum << endl;
		}
	}
    return 0;
}