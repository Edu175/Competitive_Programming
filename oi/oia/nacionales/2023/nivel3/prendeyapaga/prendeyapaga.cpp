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

ll oper(ll a, ll b, ll ty){
	if(ty)return a+b;
	return max(a,b);
}
ll NEUT[2]={0,0};
struct STree{
	vector<ll>t; ll n,ty;
	STree(ll n, ll ty):t(2*n+5,NEUT[ty]),n(n),ty(ty){}
	void upd(ll p, ll v){
		/*if(ty){
			cout<<"upd "<<p<<" "<<v<<"\n";
		}*/
		p+=n;
		if(ty)t[p]+=v;
		else t[p]=v;
		for(;p>1;p/=2)t[p/2]=oper(t[p],t[p^1],ty);
	}
	ll query(ll l, ll r){
		ll res=NEUT[ty];
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)res=oper(res,t[l++],ty);
			if(r&1)res=oper(res,t[--r],ty);
		}
		return res;
	}
};

/*struct STlazy{
	vector<ll>st,lazy; ll n;
	STlazy(ll n):st(4*n+5),lazy(4*n+5),n(n){}
	void push(ll k, ll s, ll e){
		
	}
};*/

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
    STree st(n+1,0);
    STree pre(n+2,1);
    vector<int>res(q);
    vector<ll>c(n+1);
    fore(i,0,q){
    	t[i]^=1;
    	ll x=nod[i];
    	if(t[i]){
    		//cout<<i<<": "<<pre.query(0,s[x]+1)<<"\n";
    		if(st.query(s[x],e[x])==0&&pre.query(0,s[x]+1)==0)res[i]=1;
    		else res[i]=0;
    	}
    	else res[i]=c[x];
    	if(res[i]){
    		c[x]=t[i];
    		st.upd(s[x],t[i]);
    		if(t[i]){
    			pre.upd(s[x],1);
    			pre.upd(e[x],-1);
    		}
    		else {
    			pre.upd(s[x],-1);
    			pre.upd(e[x],1);
    		}
    	}
    }
    return res;
}
