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
const ll MAXN=1005,MOD=998244353;

vector<ll> g[MAXN],g2[MAXN]; set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	fore(i,0,n)idx[i]=0,cmp[i]=-1,g2[i].clear(),gst[i].clear();
	qidx=0; qcmp=0;
	/*mset(idx,0); // NO TEST CASES
	mset(cmp,-1);*/
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		vector<ll>a(2*n);
		vector<vector<ll>>p(n);
		fore(i,0,2*n)cin>>a[i],a[i]--,p[a[i]].pb(i);
		fore(i,0,n){
			fore(j,p[i][0]+1,p[i][1])g[i].pb(a[j]);
		}
		scc();
		vector<ll>in(n2),sz(n2);
		fore(i,0,n2)for(auto j:g2[i])in[j]++;
		fore(i,0,n)sz[cmp[i]]++;
		ll res=0,num=1;
		fore(i,0,n2)if(!in[i]){
			res++;
			num=num*sz[i]*2%MOD;
		}
		cout<<res<<" "<<num<<"\n";
	}
	return 0;
}
