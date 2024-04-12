#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=505;

ll n,m;
vector<ll> g[MAXN];
ll mat[MAXN],us[MAXN];

bool match(ll x){
	if(us[x])return 0;
	us[x]=1;
	for(auto y:g[x]){
		if(mat[y]==-1||match(mat[y])){
			mat[y]=x; return 1;
		}
	}
	return 0;
}

vector<ii> max_matching(){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n){
		mset(us,0);
		if(match(i))res++;
	}
	vector<ii>ed;
	fore(i,0,m)if(mat[i]!=-1)ed.pb({mat[i],i});
	assert(SZ(ed)==res);
	return ed;
}

int main(){FIN;
	ll k; cin>>n>>m>>k;
	fore(i,0,k){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	auto res=max_matching();
	cout<<SZ(res)<<"\n";
	for(auto [u,v]:res)cout<<u+1<<" "<<v+1<<"\n";
	return 0;
}
