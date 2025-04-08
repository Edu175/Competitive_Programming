#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll tn; // node type
typedef ll tl; // lazy type
#define NEUT 0
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
};
const ll MAXV=1e6+5;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		auto sa=a;
		sort(ALL(sa));
		reverse(ALL(sa));
		if(a==sa){
			cout<<"1\n";
			continue;
		}
		vv pre,suf;
		vv prey,sufy;
		ll mn=MAXV;
		fore(i,0,n)if(a[i]<mn)pre.pb(i),mn=a[i];
		ll mx=-1;
		for(ll i=n-1;i>=0;i--)if(a[i]>mx)suf.pb(i),mx=a[i];
		reverse(ALL(suf));
		for(auto i:pre)prey.pb(a[i]);
		for(auto i:suf)sufy.pb(a[i]);
		reverse(ALL(prey)); reverse(ALL(sufy));
		// imp(pre)
		// imp(suf)
		ll m=SZ(pre),k=SZ(suf);
		vector<array<ll,3>> h[m+1];
		fore(i,0,n){
			ll r=lower_bound(ALL(pre),i)-pre.begin();
			ll l=lower_bound(ALL(prey),a[i])-prey.begin();
			// cerr<<l<<" l\n" ;
			l=m-1-l; l++;
			
			ll s=upper_bound(ALL(suf),i)-suf.begin();
			ll e=upper_bound(ALL(sufy),a[i])-sufy.begin();
			e=k-1-e; e++;
			// cout<<i<<": "<<l<<","<<r<<" "<<s<<","<<e<<endl;
			if(l<r&&s<e){
				
				h[l].pb({s,e,1});
				h[r].pb({s,e,-1});
			}
		}
		STree st(k);
		ll res=0;
		fore(t,0,m){
			for(auto [s,e,v]:h[t])st.upd(s,e,v);
			res=max(res,st.query(0,st.n));
		}
		cout<<res+2<<"\n";
	}
	return 0;
}
