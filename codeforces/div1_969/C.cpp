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
typedef ii node;
node NEUT={0,-1}; // gcd, pivot
node oper(node a, node b){
	if(a.snd==-1)return b;
	if(b.snd==-1)return a;
	ll g=gcd(gcd(a.fst,b.fst),a.snd-b.snd);
	ll p=a.snd;
	return {g,p};
}
struct STree{
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
ll is_pot(ll p){
	return __builtin_popcountll(p)==1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv bl(n); ll cnt=0;
		fore(i,0,n){
			if(i&&a[i]!=a[i-1])cnt++;
			bl[i]=cnt;
		}
		ll res=0;
		vv oc(n);
		fore(i,0,n)oc[bl[i]]++;
		for(auto c:oc)res+=c*(c+1)/2;
		
		bl.pb(cnt+1);
		
		STree st(n);
		fore(i,0,n)st.upd(i,{0,a[i]});
		
		ll po=n;
		for(ll i=n-1;i>=0;i--){
			while(bl[i]<bl[po]&&is_pot(st.query(i,po).fst))po--;
			res+=n-po;
			// cerr<<i<<": "<<po<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
