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
const ll MAXN=1e5+5;
ll xp[MAXN];

ll get(ll s, ll e){return xp[e]^xp[s];}


#define NEUT 0
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){return a^b;}
void acum(ll &a, ll v){a^=v;} // accumulate lazy node
ll calc(ll s, ll e, ll a, ll v){
	if(!v)return a;
	return get(s,e)^a;
} // calculate STree range, a=previous value

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		string S; cin>>S;
		ll s[n];
		fore(i,0,n)s[i]=S[i]-'0';
		xp[0]=0;
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
		STree st(n);
		fore(i,0,n)if(s[i])st.upd(i,i+1,1);
		ll q; cin>>q;
		while(q--){
			ll ty; cin>>ty; ty--;
			if(!ty){
				ll l,r; cin>>l>>r; l--;
				st.upd(l,r,1);
			}
			else {
				ll g; cin>>g;
				ll res=st.query(0,n);
				if(g==0)res=get(0,n)^res;
				cout<<res<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}
