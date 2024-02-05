#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct node{
	vector<ll>v,s; ll cost;
	node(ll x):v(1,x),s(1,0),cost(0){s.pb(x);}
	node():v(0),s(1,0),cost(0){}
};
void add(node &a, ll i){
	ll x=max((ll)0,(SZ(a.v)?a.v.back()-i:0));
	a.cost+=x;
	a.v.pb(i+x);
	a.s.pb(a.s.back()+i+x);
}

struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5){}
	void upd(int p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)add(t[p>>1],v);
	}
	ll query(int l, int r){
		//cout<<"\nquery "<<l<<","<<r<<"\n";
		vector<ll>izq,der;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq.pb(l++);
			if(r&1)der.pb(--r);
		}
		reverse(ALL(der));
		vector<ll>k=izq;
		for(auto i:der)k.pb(i);
		/*for(auto i:k){
			cout<<t[i].cost<<" | ";
			imp(t[i].v);
		}*/
		ll res=t[k[0]].cost,mx=t[k[0]].v.back();
		fore(i,1,SZ(k)){
			node& nd=t[k[i]];
			res+=nd.cost;
			ll lwb=lower_bound(ALL(nd.v),mx)-nd.v.begin();
			res+=lwb*mx-nd.s[lwb];
			mx=max(mx,nd.v.back());
		}
		return res;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	STree st(n);
	fore(i,0,n)cin>>a[i],st.upd(i,a[i]);
	while(q--){
		ll l,r; cin>>l>>r; l--;
		cout<<st.query(l,r)<<"\n";
	}
	return 0;
}
