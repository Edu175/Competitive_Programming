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

map<vv,ll>dp;
vv A;
ll n;
ll f(vv a){
	ll bad=1;
	fore(i,0,n)bad&=a[i]!=A[i];
	if(bad)return 0;
	if(dp.count(a))return dp[a];
	auto &res=dp[a];
	fore(i,0,n)if(a[i]){
		auto ai=a;
		ai[i]--;
		if(!f(ai))return res=1;
	}
	return res=0;
}

void solve(vv a){
	A=a;
	if(f(a))cout<<"Fennec\n";
	else cout<<"Snuke\n";
}

vv reduce(vv &a, ll l, ll r){
	if(r-l<7){
		vv b;
		fore(i,l,r)b.pb(a[i]);
		return b;
	}
	if(a[l+1]==1&&a[r-2]==2)return reduce(a,l+2,r-2);
	if(a[l+1]==1)return reduce(a,l+2,r);
	return reduce(a,l,r-2);
}

int main(){FIN;
	cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]=a[i]&1?1:2;
	sort(ALL(a));
	a=reduce(a,0,n);
	n=SZ(a);
	solve(a);
	return 0;
}
