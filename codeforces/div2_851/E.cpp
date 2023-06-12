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
#define oper max
#define NEUT 0

struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(ll s=1ll<<(64-__builtin_clzll(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(ll i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=2e5+5;
ll dp[MAXN];

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),sp(n+1),id(n+1);
	fore(i,0,n)cin>>a[i];
	vector<pair<ll,ll>>v;
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	fore(i,0,n+1)v.pb({sp[i],i});
	sort(ALL(v));
	fore(i,0,n+1)id[v[i].snd]=i;
	STree st(n+1);
	ll maxi=0;
	for(ll i=n;i>=0;i--){
		ll &res=dp[i];
		res=max(st.query(id[i],n+1)-i,maxi);
		st.upd(id[i],res+i);
		maxi=max(maxi,res);
		//cout<<i<<": "<<res<<"\n";
	}
	cout<<dp[0]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
