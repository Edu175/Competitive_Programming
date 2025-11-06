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
typedef ll tn; // node type
typedef ll tl; // lazy type
const ll INF=1e18;
#define NEUT -INF
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
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
	STree(int n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
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
};
ll L,k;

ll solve(vv h, vv is){ // max delta
	ll m=SZ(h);
	vv ch(m);
	fore(i,0,m){
		if(i+L<m){
			ll s=h[i],t=h[i+L];
			ch[i]-=s==k;
			ch[i]+=s==k+1;
			
			ch[i]+=t==k-1;
			ch[i]-=t==k;
		}
	}
	vector<vv> pos(3);
	fore(i,0,m){
		if(h[i]==k)pos[0].pb(i);
		if(h[i]==k-1)pos[1].pb(i);
		if(h[i]==k+1)pos[2].pb(i);
	}
	auto cant=[&](ll w, ll l, ll r){
		auto &v=pos[w];
		ll res=lower_bound(ALL(v),r)-lower_bound(ALL(v),l);
		return res;
	};
	STree st(m);
	ll res=0;
	ll far=-INF; // max #k-1 - #k
	for(ll i=m-1;i>=0;i--){
		st.upd(i,st.n,ch[i]);
		ll rhs=cant(1,i+L,i+2*L)-cant(0,i+L,i+2*L);
		ll lhs=-cant(0,i,i+L)+cant(2,i,i+L);
		if(i+2*L<=m)far=max(far,rhs);
		ll close=st.query(i,min(i+L,m-L));
		ll cfar=far+lhs;
		
		ll cur=max(close,cfar);
		if(is[i]){
			res=max(res,cur);
			// cout<<i<<": "<<close<<" "<<cfar<<": "<<cur<<"\n";
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>L>>k;
		ll m=4*n+5;
		vv ch(m),is(m);
		fore(i,0,n){
			ll p; cin>>p;
			ch[p]++;
			ch[p+L]--;
			is[p]=1;
		}
		vv h(m);
		ll s=0;
		fore(i,0,m){
			s+=ch[i];
			h[i]=s;
		}
		ll fij=0;
		fore(i,0,m)fij+=h[i]==k;
		ll del1=solve(h,is);
		vv is2(m);
		fore(i,0,m)if(i+L-1<m)is2[i+L-1]=is[i];
		is=is2;
		reverse(ALL(is));
		reverse(ALL(h));
		ll del2=solve(h,is);
		ll res=fij+max(del1,del2);
		// cout<<fij<<" "<<del1<<" "<<del2<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
