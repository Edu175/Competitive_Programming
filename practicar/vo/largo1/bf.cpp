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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ii mx={n+5,-1};
	ll mask=-1;
	fore(mk,0,1ll<<n){
		ll p=1,s=0,c=0;
		fore(i,0,n)if(mk>>i&1){
			p*=a[i];
			s+=a[i];
			c++;
		}
		ii now={c,s};
		if(p%k==0){
			if(mx>=now)mask=mk,mx=now;
		}
	}
	if(mask==-1){
		cout<<"-1\n";
		return 0;
	}
	cout<<__builtin_popcount(mask)<<"\n";
	fore(i,0,n)if(mask>>i&1)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}