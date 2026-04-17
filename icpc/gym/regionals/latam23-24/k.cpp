#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i+1<<" ";;cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=305,C=24;
ll n,k;

ll vis;
ll to[MAXN][MAXN];
vv a;
ll dp[1<<C];

// O(2**24 * O(confia))

void f(ll i){
	// cout<<"\n";
	// imp(a)
	// cout<<vis<<": "<<i<<"\n";
	if(i>n){
		fore(v,0,k)if(!(vis>>v&1))a.pb(v);
		for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
		exit(0);
	}
	auto &mx=dp[vis];
	if(mx>=i){
		// cout<<"podo\n";
		return;
	}
	mx=i;
	fore(v,0,k)if(!(vis>>v&1)){
		a.pb(v); vis^=1<<v;
		f(to[i][v]+1);
		a.pop_back(); vis^=1<<v;
	}
}

int main(){
	ET;
	cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,k)to[n][i]=to[n+1][i]=n+1;
	for(ll i=n-1;i>=0;i--){
		fore(v,0,k)to[i][v]=to[i+1][v];
		to[i][a[i]]=i;
	}
	if(1){
		vv vis(k);
		ll p=0;
		vv a;
		fore(_,0,k){
			ll mx=-1;
			fore(v,0,k)if(!vis[v]){
				if(mx==-1||to[p][v]>to[p][mx])mx=v;
			}
			// cout<<p<<": "<<mx<<"\n";
			a.pb(mx);
			vis[mx]=1;
			p=to[p][mx];
		}
		// cout<<p<<"\n";
		if(p>n){
			for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
			return 0;
		}
		assert(k<=C);
	}
	mset(dp,-1);
	a.reserve(k);
	f(0);
	cout<<"*\n";
}