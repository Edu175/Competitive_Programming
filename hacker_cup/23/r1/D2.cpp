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
const ll M=1e9+7;

#define CLEAR 0 // cleared lazy node
struct node{
	ii f,b;
	node(ii f, ii b):f(f),b(b){}
};
node NEUT=node({0,-M},{0,-M});
node oper(node a, node b){
	return node(max(a.f,b.f),max(a.b,b.b));
}
void acum(ll &a, ll v){a^=v;} // accumulate lazy node
node calc(ll s, ll e, node a, ll v){
	if(v)swap(a.f,a.b);
	return a;
}
// calculate STree range, a=previous value

struct STree{
	vector<node>st; vector<ll> lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<ll> &a){
		if(s+1==e){st[k]=node({a[s],-s},{M-a[s],-s});return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	node query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		STree st(n);
		st.init(a);
		ll res=0;
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			st.upd(l,r,1);
			ll resi=-st.query(0,n).f.snd;
			//cout<<resi<<" ";
			res+=resi+1;
		}
		cout<<res<<"\n";
	}
	return 0;
}
