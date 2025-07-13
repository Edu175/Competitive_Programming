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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vv pera(n),perb(m); iota(ALL(pera),0); iota(ALL(perb),0);
	sort(ALL(pera),[&](ll i, ll j){return a[i]<a[j];});
	sort(ALL(perb),[&](ll i, ll j){return b[i]<b[j];});
	sort(ALL(a));
	sort(ALL(b));
	vector<vector<ii>> suf(m,vector<ii>(n+1));
	fore(j,0,m){
		auto &s=suf[j];
		vector<ii> r(n);
		fore(i,0,n)r[i]={min((b[j]+a[i]-1)/a[i]+i,n+1),i};
		s[n]={n+1,-1};
		for(ll i=n-1;i>=0;i--)s[i]=min(r[i],s[i+1]);
	}
	ll M=1ll<<m;
	vector<ll> dp(M,n+1); dp[0]=0;
	vv fat(M,-1);
	vector<ii>ran(M);
	fore(mk,0,M){
		ll i=dp[mk];
		if(i>n)continue;
		fore(j,0,m)if(!(mk>>j&1)){
			auto [r,l]=suf[j][i];
			ll mki=mk|(1ll<<j);
			auto &prox=dp[mki];
			prox=min(prox,r);
			if(prox==r){
				fat[mki]=mk;
				ran[mki]={l,r};
			}
		}
	}
	if(dp[M-1]>n){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	vector<vv> ans(m);
	auto add=[&](ll j, ll l, ll r){
		// cout<<"add "<<j<<" "<<l<<","<<r<<"\n";
		fore(i,l,r)ans[perb[j]].pb(pera[i]);
	};
	ll mk=M-1;
	while(mk!=-1){
		auto [l,r]=ran[mk];
		ll _mk=mk;
		mk=fat[mk];
		if(mk==-1)break;
		ll j=__lg(mk^_mk);
		add(j,l,r);
	}
	for(auto v:ans){
		cout<<SZ(v)<<" ";
		for(auto i:v)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
