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
typedef ll node;
#define oper max
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<vv> h(n);
		fore(i,0,n){
			cin>>a[i];
			a[i]--;
			a[i]=n-1-a[i];
			h[a[i]].pb(i);
		}
		STree st(n);
		ll mx=0;
		vv best(n);
		ll res=0;
		fore(c,0,n){
			if(c>=2)mx=max(mx,best[c-2]);
			for(auto i:h[c]){
				ll cur=max(st.query(0,i),mx)+1;
				best[c]=max(best[c],cur);
				res=max(res,cur);
				st.upd(i,cur);
			}
		}
		cout<<n-res<<"\n";
	}
	return 0;
}
