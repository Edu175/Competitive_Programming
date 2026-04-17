#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
struct tn{
	ll hist,sum,sum2;
};
struct tl{
	ll c,b,a,x;
	bool operator==(tl r){return c==r.c&&b==r.b&&a==r.a&&x==r.x;}
};

tn NEUT({0,0,0}); // operation neutral
tl CLEAR({0,0,0,0}); // cleared lazy node
tn oper(tn a, tn b){return {(a.hist+b.hist)%MOD,(a.sum+b.sum)%MOD,(a.sum2+b.sum2)%MOD};}
void acum(tl &old, tl now){
	old.c+=now.c;
	
	old.c+=now.b*old.x;
	old.b+=now.b;
	
	old.c+=old.x*old.x%MOD*now.a;
	old.b+=2*old.x*now.a;
	old.a+=now.a;
	
	old.a%=MOD;
	old.b%=MOD;
	old.c%=MOD;
	
	old.x=(old.x+now.x)%MOD;
}
tn calc(ll s, ll e, tn a, tl v){
	// assert(s|e|1);
	a.hist+=(e-s)*v.c + a.sum*v.b + a.sum2*v.a;
	a.sum2+= 2*a.sum*v.x + (e-s)*v.x%MOD*v.x;
	a.sum+=(e-s)*v.x;
	
	a.hist%=MOD;
	a.sum2%=MOD;
	a.sum%=MOD;
	
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
	void upd(int k, int s, int e, int a, int b, tl v){
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

int main(){
	JET
	ll n,m,q; cin>>n>>m>>q;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		if(a[i]<0)a[i]+=MOD;
	}
	m++;
	vector<array<ll,3>> ops(m);
	fore(i,1,m){
		ll l,r,x; cin>>l>>r>>x; l--;
		if(x<0)x+=MOD;
		ops[i]={l,r,x};
	}
	vector<vector<pair<ll*,ii>>> qs(m);
	vv suma(q),resta(q);
	fore(i,0,q){
		ll l,r,s,e; cin>>l>>r>>s>>e; s--; l--;
		if(s!=-1)qs[s].pb({&resta[i],{l,r}});
		qs[e].pb({&suma[i],{l,r}});
	}
	STree st(n);
	vector<tn> ini(n);
	fore(i,0,n){
		auto &e=ini[i];
		e.hist=0;
		e.sum2=a[i]*a[i]%MOD;
		e.sum=a[i];
	}
	st.init(ini);
	fore(t,0,m){
		auto [l,r,x]=ops[t];
		st.upd(l,r,{0,0,0,x});
		st.upd(0,n,{0,0,1,0});
		for(auto [ptr,snd]:qs[t]){
			auto [l,r]=snd;
			*ptr=st.query(l,r).hist;
		}
		// fore(i,0,n){
		// 	auto got=st.query(i,i+1);
		// 	cout<<got.sum<<","<<got.sum2<<","<<got.hist<<" ";
		// }
		// cout<<"\n";
	}
	fore(i,0,q){
		ll res=(suma[i]-resta[i]+MOD)%MOD;
		cout<<res<<"\n";
	}
	return 0;
}