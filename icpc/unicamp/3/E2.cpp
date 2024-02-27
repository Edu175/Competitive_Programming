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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}


const ll MAXN=1e5+5;

vector<ll>cmp[MAXN];
ll id[MAXN],val[MAXN],sz[MAXN];
ll dp[MAXN];

void uf_init(ll n){
	fore(i,0,n){
		cmp[i]={i},id[i]=i,val[i]=0,dp[i]=0;
		sz[i]=1;
	}
}

void uf_join(ll x, ll y, ll w){
	x=id[x],y=id[y];
	if(x==y)return;
	if(SZ(cmp[x])<SZ(cmp[y]))swap(x,y);
	//cout<<"join "<<x<<","<<y<<" "<<w<<"\n";
	//cout<<cmp[x]<<" "<<cmp[y]<<"\n";
	ll s=val[y];
	ll z=sz[x];
	if(w)cmp[x].pb(-w*sz[y]),val[x]+=w*sz[y];
	for(auto i:cmp[y]){
		if(i<0){s+=i;continue;}
		//cout<<"dp["<<i<<"]+="<<s<<"+"<<w*z<<" ";
		dp[i]+=s+w*z;
		cmp[x].pb(i);
		id[i]=x;
		sz[x]++;
	}
	//cout<<"\n";
	sz[y]=0;
	cmp[y].clear();
	//cout<<val[x]<<" "<<sz[x]<<" "<<cmp[x]<<"\n\n";
}

int main(){FIN;
	ifstream cin;   cin.open("road.in", ios::in);
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case "<<_+1<<":\n";
		ll n,m; cin>>n>>m;
		vector<pair<ll,ii>>es;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			es.pb({w,{u,v}});
		}
		sort(ALL(es));
		uf_init(n+3);
		fore(i,0,SZ(es))uf_join(es[i].snd.fst,es[i].snd.snd,es[i].fst);
		ll s=val[id[0]];
		for(auto i:cmp[id[0]]){
			if(i<0){s+=i;continue;}
			//cout<<"dp["<<i<<"]+="<<s<<" ";
			dp[i]+=s;
		}
		//cout<<"\n";
		fore(i,0,n)cout<<dp[i]<<"\n";
	}
	return 0;
}
