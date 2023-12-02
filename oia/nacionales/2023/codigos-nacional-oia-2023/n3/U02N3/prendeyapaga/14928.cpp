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

#define oper max
#define NEUT 0
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p/=2)t[p/2]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

vector<ll> g[MAXN];

ll s[MAXN],e[MAXN];
vector<ll>a;

void dfs(ll x){
	s[x]=SZ(a);
	a.pb(x);
	for(auto y:g[x])dfs(y);
	e[x]=SZ(a);
}

vector<int> hoteles(vector<int>& p, vector<int>& t, vector<int>& nod) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    ll n=SZ(p);
    fore(i,0,n)g[p[i]].pb(i+1);
    ll q=SZ(t);
    dfs(0);
    STree st(n+1);
    vector<int>res(q);
    vector<ll>c(n+1);
    fore(i,0,q){
    	t[i]^=1;
    	ll x=nod[i];
    	if(t[i]){
    		res[i]=!(st.query(s[x],e[x]));
    	}
    	else res[i]=c[x];
    	if(res[i]){
    		c[x]=t[i];
    		st.upd(s[x],t[i]);
    	}
    }
    return res;
}
