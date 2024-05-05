#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu.fst<<","<<edu.snd<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
struct node{
	ll xs,ys,q;
};
node NEUT={0,0,0};
node oper(node a, node b){return {a.xs+b.xs,a.ys+b.ys,a.q+b.q};}
struct STree{ //persistent
	vector<node>st; vector<int>L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){return upd(rt,p,v);} // update on last root
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
vector<ll>rts={0};
STree st(0);
node query(ll i0, ll i1, ll j0, ll j1){ // [,)
	auto e=st.query(rts[i1],j0,j1);
	auto s=st.query(rts[i0],j0,j1);
	return {e.xs-s.xs,e.ys-s.ys,e.q-s.q};
}
const ll db=0;
ll solve(vector<ii>a){
	if(db)cout<<"solve ";
	if(db){imp(a);}
	ll n=SZ(a);
	rts={0};
	map<ll,ll>mp;
	auto _a=a;
	fore(i,0,n){
		auto [x,y]=a[i];
		a[i]={x-y+1e9,x+y};
		mp[a[i].fst]=mp[a[i].snd]=-1;
	}
	ll k=0;
	for(auto &i:mp)i.snd=k++;
	vector<ll>upd[k];
	fore(i,0,SZ(a))upd[mp[a[i].fst]].pb(i);
	st=STree(k);
	fore(x,0,k){
		for(auto i:upd[x])st.upd(mp[a[i].snd],{_a[i].fst,_a[i].snd,1});
		rts.pb(st.rt);
	}
	ll res=0;
	fore(h,0,n){
		auto [x,y]=a[h];
		auto [_x,_y]=_a[h];
		ll xi=mp[x],yi=mp[y];
		vector<node>qs;
		qs.pb(query(0,xi,0,yi));
		qs.pb(query(xi,k,0,yi));
		qs.pb(query(xi,k,yi,k));
		qs.pb(query(0,xi,yi,k));
		ll resi=0;
		if(db)cout<<h<<" "<<_x<<","<<_y<<" ("<<x<<","<<y<<"):\n";
		fore(i,0,4){
			auto q=qs[i];
			ll r=0;
			if(i%2==0)r=q.xs-_x*q.q;
			else r=q.ys-_y*q.q;
			resi+=abs(r);
			if(db)cout<<i<<": ["<<q.xs<<","<<q.ys<<","<<q.q<<"] = "<<r<<"\n";
		}
		if(db)cout<<resi<<"\n\n";
		res+=resi;
	}
	if(db)cout<<"res= "<<res<<"\n\n\n";
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	vector<ii>a[2];
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		a[(x+y)&1].pb({x,y});
	}
	ll res=0;
	res+=solve(a[0]);
	res+=solve(a[1]);
	cout<<res/2<<"\n";
	return 0;
}
