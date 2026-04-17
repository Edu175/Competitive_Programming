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
const ll INF=1e18;
typedef ll tn; // node type
typedef ll tl; // lazy type
#define NEUT 0
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return min(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> byc(m);
		vv a(n*m),c(n*m);
		fore(i,0,n*m)cin>>a[i],a[i]--;
		fore(i,0,n*m)cin>>c[i],c[i]--;
		fore(i,0,n*m){
			byc[c[i]].pb(a[i]);
		}
		vv good(n,1);
		vector<vv> rans(n+1);
		fore(j,0,m){
			auto &v=byc[j];
			ll mx=-1;
			vv bad(n);
			for(auto x:v){
				mx=max(mx,x);
				if(mx!=x)bad[x]=1,good[x]=0;
			}
			ll l=0;
			fore(i,0,n){
				if(i==n-1||bad[i]!=bad[i+1]){
					if(!bad[i]){
						rans[l].pb(i+1);
						// cerr<<"range "<<l<<","<<i+1<<"\n";
					}
					l=i+1;
				}
			}
		}
		STree st(n+1);
		// st.upd(n,n+1,-st.query(n,n+1)); // last is 0
		st.upd(n,0);
		for(ll i=n-1;i>=0;i--){
			for(auto r:rans[i+1])st.upd(i+1,r,1);
			ll cur=st.query(i+1,n+1); cur--;
			if(good[i])st.upd(i,cur);
		}
		for(auto r:rans[0])st.upd(0,r,1);
		ll res=st.query(0,n+1);
		res+=n;
		res--;
		cout<<res<<"\n";
	}
	return 0;
}
