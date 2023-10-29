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

struct node{
	ll mn=0,mx=0,id=-1;
	node(){}
	node(ll v, ll i):mn(v),mx(v),id(i){}
	void prnt(){cout<<mn<<","<<mx<<"("<<id<<") ";}
};

node NEUT;
#define CLEAR 0 // cleared lazy node
node oper(node a, node b){
	if(a.id==-1)return b;
	if(b.id==-1)return a;
	node c;
	c.mn=min(a.mn,b.mn);
	if(a.mx>=b.mx)c.mx=a.mx,c.id=a.id;
	else c.mx=b.mx,c.id=b.id;
	return c;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
node calc(ll s, ll e, node a, ll v){ // calculate STree range, a=previous value
	a.mn+=v,a.mx+=v;
	return a;
} 

struct STree{
	vector<node>st; vector<ll>lazy; ll n;
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
	void change(ll k, ll s, ll e, ll p, node v){ // single element
		push(k,s,e);
		if(e<=p||p<s)return;
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		change(2*k,s,m,p,v);
		change(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
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
	void change(ll p, node v){change(1,0,n,p,v);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	node query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	//cout<<NEUT.id<<"\n";
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<ii>>ev(n+1);
		ll q; cin>>q;
		fore(i,1,q+1){
			ll l,r,x; cin>>l>>r>>x; l--;
			ev[l].pb({i,x});
			ev[r].pb({i,-x});
		}
		STree st(q+1);
		//cout<<st.n<<"\n";
		fore(i,0,st.n)st.change(i,node(0,i));
		vector<ll>res(n);
		fore(i,0,n){
			for(auto [p,x]:ev[i])st.upd(p,st.n,x);
			//cout<<i<<": ";
			//fore(i,0,st.n)st.query(i,i+1).prnt();
			//cout<<"\n";
			//st.query(0,st.n).prnt();
			//cout<<"\n";
			ll mn=st.query(0,st.n).mn;
			while(st.query(0,st.n).mx!=mn){
				ll p=st.query(0,st.n).id;
				assert(p!=-1);
				st.change(p,NEUT);
			}
			//fore(i,0,st.n)st.query(i,i+1).prnt();
			//cout<<"\n\n";
			assert(st.query(0,st.n).id!=-1);
			res[i]=a[i]+mn;
		}
		imp(res);
	}
	return 0;
}
