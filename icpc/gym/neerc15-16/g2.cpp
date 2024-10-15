#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll in[MAXN],vis[MAXN];

int main(){FIN;
	#ifdef ONLINE_JUDGE
	freopen("graph.in","r",stdin);     freopen("graph.out","w",stdout);
	#endif
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--; b--;
		g[a].pb(b);
		in[b]++;
	}
	priority_queue<ll>tap;
	vector<ll>z;
	fore(x,0,n)if(!in[x])z.pb(x);
	while(SZ(tap)<k){
		vector<ll>can;
		sort(ALL(z));
		for(auto x:z)if(SZ(tap)<k){
			tap.push(x);
			can.pb(x);
		}
		if(SZ(tap)==k)break;
		for(auto x:can){
			for(auto y:g[x]){
				in[y]--;
				if(in[y]==0)z.pb(y);
			}
		}
	}
	vector<ii>ed;
	if(SZ(tap)){
		vector<ll>v;
		while(SZ(tap))v.pb(tap.top()),tap.pop();
		reverse(ALL(v));
		fore(i,0,SZ(v)-1)ed.pb({v[i+1],v[i]});
		ed.pb({z,v.back()});
	}
	
	return 0;
}