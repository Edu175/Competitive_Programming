#include "garden.h"
#include "gardenlib.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=300005;

vector<ll> g[MAXN];

ll n,p;
ll go(ll u, ll v){
	if(SZ(g[v])==1)return 2*v;
	if(g[v][0]==u)return 2*v+1;
	return 2*v;
}
ll a[MAXN];
ll ds[2][MAXN];
ll zs[2];
void calc(ll w){
	vector<ll>d(2*n,-1),vis(2*n),ord;
	ll e=2*p+w;
	zs[w]=0;
	fore(x,0,2*n)if(!vis[x]){
		vector<ll>p,cyc;
		for(ll y=x;!vis[y];y=a[y]){
			p.pb(y); vis[y]=1;
		}
		ll did=0;
		for(auto x:p){
			did|=x==a[p.back()];
			if(did)cyc.pb(x);
		}
		reverse(ALL(p));
		for(auto i:p)ord.pb(i);
		if(count(ALL(cyc),e)){
			ll m=SZ(cyc);
			ll pos=-1;
			fore(i,0,m)if(cyc[i]==e)pos=i;
			fore(i,0,m){
				d[cyc[i]]=(pos-i+m)%m;
			}
			zs[w]=m;
		}
	}
	for(auto x:ord)if(d[x]==-1){
		if(x==e)d[x]=0;
		else if(d[a[x]]!=-1)d[x]=d[a[x]]+1;
	}
	d[e]=zs[w];
	fore(i,0,2*n)ds[w][i]=d[i];
	// cout<<"calc "<<w<<": "<<zs[w]<<"\n";
	// fore(i,0,2*n)cout<<d[i]<<" ";;cout<<"\n";
	// imp(ord);
}

void count_routes(int N, int m, int P, int R[][2], int q, int qs[])
{
	n=N,p=P;
	fore(i,0,m){
		ll u=R[i][0],v=R[i][1];
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(x,0,n){
		a[2*x]=go(x,g[x][0]);
		if(SZ(g[x])>1)a[2*x+1]=go(x,g[x][1]);
	}
	// fore(x,0,2*n)cout<<a[x]<<" ";;cout<<"\n";
	calc(0); calc(1);
	fore(_,0,q){
		ll k=qs[_],res=0;
		fore(x,0,2*n)if(x%2==0){
			ll flag=0;
			fore(w,0,2){
				ll z=zs[w];
				auto d=ds[w];
				if(d[x]!=-1){
					ll dif=k-d[x];
					flag|=(dif==0||(dif>=0&&z&&dif%z==0));
					// cout<<x<<" "<<w<<": "<<dif<<"\n";
				}
			}
			// if(flag)cout<<x<<" x\n";
			res+=flag;
		}
		// cout<<res<<endl;
		answer(res);
	}
}


