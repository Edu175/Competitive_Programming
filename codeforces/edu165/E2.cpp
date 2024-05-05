#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto edu:v)cout<<edu<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e9;
#define NEUT INF
#define CLEAR 0 // cleared lazy node
#define oper min
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
} 

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),c(n);
		deque<ll>p[n];
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]].pb(i);
		fore(i,0,n)p[i].pb(n);
		STree st(n);
		auto update=[&](ll i, ll v){
			if(SZ(p[i])>1){
				st.upd(p[i][0],p[i][1],v);
			}
		};
		//#define update(i,v) if(SZ(p[i])>1){st.upd(p[i][0],p[i][1],v);}
		fore(i,0,n)update(i,1);
		vector<ii>b;
		fore(i,0,n){
			ll l=i,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(i,m+1)==0)r=m-1;
				else l=m+1;
			}
			if(l<n)b.pb({i,l});
			
			update(a[i],-1);
			p[a[i]].pop_front();
			update(a[i],1);
		}
		vector<ii>d;
		for(auto [l,r]:b){
			while(SZ(d)&&d.back().snd>=r)d.pop_back();
			d.pb({l,r});
		}
		if(!SZ(d))cout<<"0\n";
		else {
			ll e=d[0].snd;
			ll res=1;
			for(auto [l,r]:d){
				if(e>=l)continue;
				else res++,e=r;
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
