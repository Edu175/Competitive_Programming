#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll K=19;
vv big(vv a){
	ll n=SZ(a);
	vv r(n);
	for(ll i=n-1;i>=0;i--){
		for(r[i]=i+1;r[i]!=n&&a[i]>=a[r[i]];r[i]=r[r[i]]);
	}
	return r;
}
struct STable{
	// ll st[K][1ll<<K];
	// ll ty,n;
	// ll oper(ll a, ll b){
		// 	if(ty)return max(a,b);
		// 	return min(a,b);
		// }
	vector<vv>st;
	#define oper min
	ll n;
	void init(vv &a){
		n=SZ(a);
		st=vector<vv>(K,vv(n));
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n){
			ll mid=1ll<<(k-1);
			if(i+mid>=n)continue;
			st[k][i]=oper(st[k-1][i],st[k-1][i+mid]);
		}
	}
	ll get(ll s, ll e){
		assert(s>=0&&e<=n);
		ll k=__lg(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}
};

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*(n+1)+5),n(n+1){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	void upd(ll l, ll r, ll v){
		// cout<<"upd "<<l<<" "<<r<<" "<<v<<"\n";
		upd(l,v);
		upd(r,-v);
	}
	ll query(ll p){
		return query(0,p+1);
	}
};

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<vector<ii>> qs(n+1);
	ll q; cin>>q;
	vv ans(q);
	fore(_,0,q){
		ll l,r; cin>>l>>r; l--;
		qs[l].pb({r,_});
	}
	vv ri=big(a);
	
	reverse(ALL(a));
	vv le=big(a);
	reverse(ALL(a));
	reverse(ALL(le));
	for(auto &i:le)i=n-1-i;
	
	// for(auto i:le)cout<<i<<" ";;cout<<"\n";
	// for(auto i:ri)cout<<i<<" ";;cout<<"\n";
	
	STable tab; tab.init(a);
	
	vector<vector<array<ll,3>>> h(n+3);
	fore(i,0,n){
		ll ls=le[i]+1;
		ll lE=ri[i];
		ll rs=ri[i]+1;
		
		ll l=rs,r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(tab.get(rs,m+1)<a[i])r=m-1;
			else l=m+1;
		}
		ll re=l+1;
		
		// cout<<i<<": "<<ls<<","<<lE<<" "<<rs<<" "<<re<<"\n";
		
		h[ls].pb({+1,rs,re});
		h[lE].pb({-1,rs,re});
	}
	
	STree st(n+3);
	fore(i,0,n){
		for(auto [v,s,e]:h[i]){
			st.upd(s,e,v);
		}
		// fore(i,0,n+3)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
		// fore(i,0,n+3)cout<<st.query(i)<<" ";;cout<<"\n";
		for(auto [r,idx]:qs[i]){
			ans[idx]=(st.query(r)>0);
		}
	}
	for(auto i:ans){
		if(i)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}