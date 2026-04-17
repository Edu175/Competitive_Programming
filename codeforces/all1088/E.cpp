#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct node{
	ll mn;
	vv vals;
};

node merge(ll x, vector<node> a){
	ll sum=0;
	for(auto e:a)sum+=e.mn;
	node ret;
	auto &vals=ret.vals;
	vals={x};
	auto &mn=ret.mn;
	mn=sum+1;
	ll m=1;
	for(auto e:a)for(auto v:e.vals){
		ll g=gcd(x,v);
		if(g==1)continue;
		if(sum<mn){
			vals={g};
			mn=sum;
			m=g;
		}
		else {
			ll v=g;
			ll d=gcd(v,m);
			v/=d;
			if(v!=1)vals.pb(v),m*=v;
		}
	}
	return ret;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		// cerr<<"testcase\n";
		ll n; cin>>n;
		vector<node> dp(n);
		for(ll x=n-1;x>=0;x--){
			ll val,k;
			cin>>val>>k;
			vector<node> a(k);
			fore(i,0,k){
				ll y; cin>>y; y--;
				a[i]=dp[y];
			}
			dp[x]=merge(val,a);
			cout<<dp[x].mn<<endl;
		}
	}
	return 0;
}
