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

map<vv,ll> dp;
ll n,m,k;
map<vv,vv> to;
ll f(vv a){
	if(dp.count(a))return dp[a];
	auto &res=dp[a];
	ll c=n-count(ALL(a),0);
	res=c;
	ll sum=accumulate(ALL(a),0ll);
	if(res==n||sum==m)return res;
	fore(i,0,n)fore(c,0,a[i]+1)fore(b,0,2){
		ll j=b?i-1:i+1;
		if(j<0||j>=n)continue;
		vv p=a;
		p[j]+=c; p[i]-=c;
		p[k]++;
		ll cur=f(p);
		res=max(res,cur);
		if(res==cur)to[a]=p;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k; k--;
		dp.clear();
		vv a(n);
		ll res=f(a);
		cout<<res<<"\n";
		imp(a)
		fore(_,0,min(m,n)){
			a=to[a];
			imp(a)
		}
		cout<<"\n\n";
	}
	return 0;
}
