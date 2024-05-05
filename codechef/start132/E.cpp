#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef ii node;
ii oper(ii a, ii b){
	return {add(a.fst,b.fst),add(a.snd,b.snd)};
}
#define NEUT {0,0}
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		//cout<<"upd "<<p<<" "<<v.fst<<","<<v.snd<<"\n";
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ii query(int l, int r){
		//cout<<"query "<<l<<","<<r<<" = ";	
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		//ll ans=;
		//cout<<res.fst<<","<<res.snd<<" = "<<ans<<"\n";
		return res;
	}
};
ll prom(ii res){
	return mul(res.fst,fpow(res.snd,MOD-2));
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		map<ll,vector<ll>>mp;
		fore(i,0,n){
			ll k; cin>>k;
			fore(_,0,k){
				ll x; cin>>x;
				mp[x].pb(i);
			}
		}
		vector<ll>ord;
		for(auto i:mp)ord.pb(i.fst);
		reverse(ALL(ord));
		STree st(n);
		for(auto x:ord){
			auto v=mp[x];
			vector<ll>dp(SZ(v));
			fore(j,0,SZ(v))
				dp[j]=add(x,prom(oper(st.query(0,v[j]),st.query(v[j]+1,n))));
			fore(j,0,SZ(v))st.upd(v[j],{dp[j],1});
		}
		ll res=prom(st.query(0,n));
		cout<<res<<"\n";
	}
	return 0;
}
