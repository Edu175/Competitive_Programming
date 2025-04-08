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
const ll MAXN=1e6+5;

bitset<MAXN> shi(bitset<MAXN> &a, ll x, ll sig){
	if(sig)return a<<x;
	return a>>x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll s,k; cin>>s>>k;
		if(s>=k*k){
			if(s%k==0)cout<<k<<"\n";
			else cout<<k-2<<"\n";
			continue;
		}
		bitset<MAXN>b,all;
		fore(i,0,s+1)all[i]=1;
		b[0]=1; ll sig=1,res=-1;
		while(!b[s]){
			// cout<<b<<"\n";
			auto bi=shi(b,k,sig);
			fore(i,1,s+1)if(k*i<=s)bi|=shi(b,k*i,sig);
			b=bi&all;
			if(b[s])res=k;
			k=max(k-1,1ll);
			sig^=1;
		}
		// cout<<b<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
