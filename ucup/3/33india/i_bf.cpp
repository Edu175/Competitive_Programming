#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct STree{
	typedef ll node;
	#define NEUT 0
	ll oper(ll a, ll b){return max(a,b);}
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
ll good(string s){
	ll ca=0,cb=0;
	for(auto i:s){
		if(i=='A')ca++;
		else if(i=='B')cb++;
		else if(ca>cb)ca++;
		else if(cb>ca)cb++;
	}
	return ca>cb;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			auto t=s.substr(l,r-l);
			ll n=r-l,res=n+5;
			fore(mk,0,1ll<<n){
				ll resi=0;
				auto ti=t;
				fore(i,0,n)if(mk>>i&1)resi++,ti[i]='.';
				if(good(ti))res=min(res,resi);
			}
			if(res>=n+5)res=-1;
			cout<<res<<"\n";
		}
	}
	return 0;
}