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

typedef pair<ii,ii> node;
node oper(node a, node b){
	return {max(a.fst,b.fst),min(a.snd,b.snd)};
}
node NEUT={{0,0},{1e8,1e8}};
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		STree st(n);
		fore(i,0,n)st.upd(i,{{a[i],i},{a[i],i}});
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			node res=st.query(l,r);
			if(res.fst.fst==res.snd.fst)cout<<"-1 -1\n";
			else cout<<res.fst.snd+1<<" "<<res.snd.snd+1<<"\n";
		}
	}
	return 0;
}
