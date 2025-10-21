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
//*	if using as STree lazy creation change to
//	ks=(k?k: ... );
//	to avoid mle 


typedef ll node;
node oper(node a, node b){return a+b;}
node inv(node a, node b){return a-b;}
node NEUT=0;
struct STree{ //persistent 
	vector<node>st; vector<int>L,R; ll n,rt;
	STree(){}
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]=v;return ks;}
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
	
	// (for 2d static queries)
	// n = 2nd coordinate
	vector<int>rts,keys;
	void init(vector<pair<ii,node>>a){
		// init 2d updates, (x,y) coords, value
		rts={0}; keys={};
		sort(ALL(a),[&](pair<ii,node>a, pair<ii,node> b){
			return a.fst.fst<b.fst.fst;});
		for(auto [pa,v]:a){
			auto [x,y]=pa;
			keys.pb(x);
			rts.pb(upd(y,v));
		}
	}
	node get(ll i, ll j0, ll j1){ // get rectangle [0,i) [j0,j1)
		ll p=lower_bound(ALL(keys),i)-keys.begin();
		return query(rts[p],j0,j1);
	}
	node get(ll i0, ll i1, ll j0, ll j1){
		// get rectangle [i0,i1) [j0,j1) with inverse operation
		cout<<"get "<<i0<<","<<i1<<" "<<j0<<","<<j1<<"\n";
		ll r=get(i1,j0,j1),l=get(i0,j0,j1);
		cout<<l<<" "<<r<<" = "<<r-l<<"\n";
		return inv(r,l);
	}
};
const ll MAXN=805;
ll n,m;
ll a[MAXN][MAXN];
STree st[MAXN*MAXN]; // for each val
ll cantbf(ll k){
	ll res=0;
	cout<<"bf "<<k<<":\n";
	fore(i,0,n)fore(j,0,m)fore(r,0,n)fore(c,0,m){
		if(a[i][j]!=a[r][c]&&max(abs(r-i),abs(j-c)))res++,cout<<i<<","<<j<<" "<<r<<","<<c<<"\n";
	}
	return res;
}
ll cant(ll k){ // <= k
	ll res=0;
	cout<<"cant "<<k<<":\n";
	fore(i,0,n)fore(j,0,m){
		ll i0=i-k,i1=i+k+1;
		ll j0=j-k,j1=j+k+1;
		i0=max(i0,0ll);
		j0=max(j0,0ll);
		i1=min(i1,n);
		j1=min(j1,m);
		ll ig=st[a[i][j]].get(i0,i1,j0,j1);
		ll dif=(j1-j0)*(i1-i0)-ig;
		cout<<i<<","<<j<<": "<<ig<<" "<<dif<<"\n";
		res+=dif;
	}
	cantbf(k);
	exit(0);
	return res;
}

int main(){FIN;
	// cout<<sizeof(vector<ll>(1,500))<<"\n";
	
	ll ljgfjfdg; cin>>ljgfjfdg;
	fore(ldjg,0,ljgfjfdg){
		cout<<"Case #"<<ldjg+1<<": ";
		ll k; cin>>n>>m>>k; k--;
		fore(i,0,n)fore(j,0,m){
			cin>>a[i][j]; a[i][j]--;
		}
		fore(i,0,n*m)st[i]=STree(m);
		vector<pair<ii,node>> ini[n*m];
		fore(i,0,n)fore(j,0,m)ini[a[i][j]].pb({{i,j},1});
		fore(i,0,n*m)st[i].init(ini[i]);
		ll l=1,r=n+m;
		while(l<=r){
			ll h=(l+r)/2;
			if(cant(h)>k)r=h-1;
			else l=h+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
