#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll NEUT=0;
#define oper gcd
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
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

ll cd[MAXN];

void criba(){
	fore(d,1,MAXN)for(ll i=0;i<MAXN;i+=d)cd[i]++;
}

int main(){
	JET
	criba();
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		set<ll>st; // con el anterior
		st.insert(0);
		fore(i,0,n)cin>>a[i];
		STree seg(n);
		auto agr=[&](ll i){
			assert(i);
			if(st.count(i))return;
			auto it=st.lower_bound(i);
			ll l=*prev(it);
			if(it!=st.end()){
				seg.upd(i,*it-i);
			}
			seg.upd(l,i-l);
			st.insert(i);
		};
		auto saca=[&](ll i){
			assert(i);
			if(!st.count(i))return;
			st.erase(i);
			auto it=st.lower_bound(i);
			ll l=*prev(it);
			seg.upd(i,0);
			if(it==st.end())seg.upd(l,0);
			else seg.upd(l,*it-l);
		};
		fore(i,1,n)if(a[i-1]>a[i])agr(i);
		auto query=[&](){
			ll g=seg.query(0,n);
			ll c=cd[g];
			c=min(c,n);
			cout<<c<<"\n";
		};
		query();
		while(q--){
			ll p,v; cin>>p>>v; p--;
			a[p]=v;
			if(p){
				if(a[p-1]>v)agr(p);
				else saca(p);
			}
			if(p!=n-1){
				if(v>a[p+1])agr(p+1);
				else saca(p+1);
			}
			// for(auto i:st)cout<<i<<" ";;cout<<"\n";
			query();
		}
	}
	return 0;
}