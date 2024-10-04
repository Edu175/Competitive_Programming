#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

#define NEUT 0
#define oper max
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){JET
	ll n,S; cin>>n>>S;
	vector<ll>l(n),r(n),c(n);
	fore(i,0,n)cin>>l[i]>>r[i]>>c[i],r[i]++;
	vector<ll>per(n);
	fore(i,0,n)per[i]=i;
	sort(ALL(per),[&](ll i, ll j){
		return l[i]<l[j];
	});
	auto comm=[&](vv &a){
		ll n=SZ(a);
		vv a2(n);
		fore(i,0,n)a2[i]=a[per[i]];
		a=a2;
	};
	comm(l); comm(r); comm(c);
	// for(auto i:l)cout<<i<<" ";;cout<<"\n";
	// for(auto i:r)cout<<i<<" ";;cout<<"\n";
	// for(auto i:c)cout<<i<<" ";;cout<<"\n";
	// vector<vv>dp(n+5,vv(2));
	STree st(n),st1(n);
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll e=lower_bound(ALL(l),r[i])-l.begin();
		ll dp1=st1.query(e,n)-c[i];
		ll dp0=-S*l[i]-c[i]+st.query(i,e);
		dp0=max(dp0,S*(r[i]-l[i])+dp1);
		st1.upd(i,dp0);
		st.upd(i,dp0+S*l[i]);
		// cout<<i<<": "<<e<<": "<<dp0<<","<<dp1<<"\n";
		ans=max(ans,dp0);
	}
	cout<<ans<<"\n";
	return 0;
}

/*
1 2 3 
2 4 4 
3 4 1 
2: 3: 4,-1
1: 3: 6,-4
0: 1: 11,3
11



*/
