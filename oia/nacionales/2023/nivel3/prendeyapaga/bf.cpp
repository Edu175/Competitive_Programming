#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll> g[MAXN];

ll c[MAXN];
ll dfs(ll x){
	ll res=c[x];
	for(auto y:g[x])res|=dfs(y);
	return res;
}

vector<int> hoteles(vector<int>& p, vector<int>& t, vector<int>& nod) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    ll n=SZ(p);
    fore(i,0,n)g[p[i]].pb(i+1);
    ll q=SZ(t);
    vector<int>res(q);
    fore(i,0,q){
    	t[i]^=1;
    	ll x=nod[i];
    	if(t[i]){
    		ll flag=dfs(x);
    		ll xi=x;
    		while(xi>0)flag|=c[xi],xi=p[xi-1];
    		flag|=c[xi];
    		res[i]=!flag;
    	}
    	else res[i]=c[x];
    	if(res[i]){
    		c[x]=t[i];
    	}
    }
    return res;
}
