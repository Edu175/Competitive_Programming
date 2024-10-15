#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
/*
1.008  e9
1.05   e9
*/

const ll NUMERO=1.008e9;
const ll INF=(log(1e9)+2)*NUMERO;
#define NEUT 0
#define CLEAR 0 // cleared lazy node
#define oper max
void acum(int &a, int v){ // accumulate lazy node
	a=max(a,v);
}
ll calc(ll s, ll e, int a, int v){ // calculate STree range, a=previous value
	return max(a,v);
} 

struct STree{
	vector<int>st,Le,Ri,lazy;
	STree():st(1,NEUT),Le(1,0),Ri(1,0),lazy(1,CLEAR){}
	ll new_node(){
		// cout<<"new_node"<<endl;
		ll ks=SZ(st);
		st.pb(NEUT),Le.pb(0),Ri.pb(0),lazy.pb(CLEAR);
		return ks;
	}
	ll L(ll k){
		if(Le[k])return Le[k];
		ll ks=new_node();
		return Le[k]=ks;
	}
	ll R(ll k){
		if(Ri[k])return Ri[k];
		ll ks=new_node();
		return Ri[k]=ks;
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[L(k)],lazy[k]);
			acum(lazy[R(k)],lazy[k]);
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
		upd(L(k),s,m,a,b,v),upd(R(k),m,e,a,b,v);
		st[k]=oper(st[L(k)],st[R(k)]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(L(k),s,m,a,b),query(R(k),m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(0,-INF,INF,a,b,v);}
	ll query(ll a, ll b){return query(0,-INF,INF,a,b);}
};
ll f(ii a){
	return (log(a.fst)-log(a.snd))*NUMERO;
}

int main(){JET
	ll n; cin>>n;
	ll v=0;
	STree st;
	fore(_,0,n){
		char ty; cin>>ty;
		ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd;
		s.fst^=v,s.snd^=v,e.fst^=v,e.snd^=v;
		ll l=f(s),r=f(e);
		if(ty=='B'){
			ll h; cin>>h; h^=v;
			st.upd(l,r+1,h);
		}
		else {
			ll res=st.query(l,r+1);
			v=res;
			cout<<res<<"\n";
		}
	}
	
	return 0;
}