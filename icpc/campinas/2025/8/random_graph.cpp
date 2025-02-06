#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

// Generates a random connected simple graph
// (no self-loops nor multi-edges)
// given N,M number of nodes and edges, respectively 

// edges are given in ascending order, and u < v
// if you want to change it uncomment the corresponding lines

random_device rd;
mt19937 rng(rd());

int main(){
    JET
    ll N,M; cin>>N>>M;
	// ll V; cin>>V; // weighted
	ll n=rng()%(N-1)+2;
	M=max(M,n-1);
	M=min(M,n*(n-1)/2);
	ll g[n][n]; mset(g,0);
	fore(i,1,n)g[rng()%i][i]=1;
	vector<ii>all;
	fore(i,0,n)fore(j,i+1,n)if(!g[i][j])all.pb({i,j});
	ll m=rng()%(M-(n-1)+1);
	shuffle(ALL(all),rng);
	fore(i,0,m)g[all[i].fst][all[i].snd]=1;
	
	cout<<n<<" "<<m+n-1<<"\n";
	vector<ii>ed;
	fore(i,0,n)fore(j,i+1,n)if(g[i][j])ed.pb({i,j});
	
	// shuffle(ALL(ed),rng); // easier to debug if commented
	
	for(auto [u,v]:ed){
		// if(rng()&1)swap(u,v); // easier to debug if commented
		
		cout<<u+1<<" "<<v+1<<"\n";
		// cout<<u+1<<" "<<v+1<<" "<<rng()%(V+1)<<"\n"; // weighted
	}
}