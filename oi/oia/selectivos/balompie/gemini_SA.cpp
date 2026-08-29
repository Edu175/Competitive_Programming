#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi.fst<<","<<messi.snd<<" ";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll MAXN=1005;
ll deg[MAXN], maxd[MAXN];
mt19937 rng(32123);

ll simulated_annealing(ll n, ll m, const vector<ii>& edges) {
    ll res = 0, best = 0;
    vector<ll> w(m, 0); // O(1) edge weight lookup instead of map<ii, ll>
    
    // Adjust T_init based on the expected maximum change in objective function
    double T_init = 1e5; 
    double T_final = 1e-4;
    double T = T_init;
    
    uniform_real_distribution<double> rnd(0.0, 1.0);
    int iters = 0;
    
    while(true) {
        // Check clock every 1024 iterations to avoid sys-call overhead
        if((++iters & 1023) == 0) { 
            double elapsed = (double)clock() / CLOCKS_PER_SEC;
            if(elapsed >= 1.9) break;
            // Time-based exponential cooling guarantees we reach T_final precisely at 1.9s
            T = T_init * pow(T_final / T_init, elapsed / 1.9); 
        }
        
        int id = rng() % m;
        ll u = edges[id].fst;
        ll v = edges[id].snd;
        
        ll cap = min(maxd[u] - deg[u], maxd[v] - deg[v]);
        ll cur_w = w[id];
        
        // If we can neither add nor subtract, skip immediately
        if(cap == 0 && cur_w == 0) continue; 
        
        bool add_op = false;
        if(cur_w == 0) add_op = true;
        else if(cap == 0) add_op = false;
        else add_op = rng() % 2; // 50/50 chance if both are valid
        
        ll k = 0;
        if(add_op) {
            k = rng() % cap + 1; 
        } else {
            k = rng() % cur_w + 1;
        }
        
        ll add = add_op ? k : -k;
        ll resi = res + add;
        
        // Metropolis Acceptance Criterion
        if(resi > res || exp((resi - res) / T) >= rnd(rng)) {
            res = resi;
            w[id] += add;
            deg[u] += add;
            deg[v] += add;
            if(res > best) best = res;
        }
    }
    return best;
}

int main(){FIN;
    ll n, m; 
    if(!(cin>>n>>m)) return 0;
    fore(i,0,n) cin>>maxd[i];
    
    vector<ii> edges;
    fore(i,0,m){
        ll u,v; cin>>u>>v; u--,v--;
        if(u>v) swap(u,v);
        edges.pb({u,v});
    }
    
    ll res = simulated_annealing(n, m, edges);
    cout<<res<<"\n";
    return 0;
}