#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll N=21,MAXN=1ll<<N;

ll ppc(ll x){return __builtin_popcountll(x);}

int main(){FIN;
	ll n; cin>>n;
	ll m=1ll<<n;
	vector<ll>a(m); a[0]=1;
	fore(i,1,m){
		cin>>a[i];
	}
	fore(x,1,m){
		ll now=0;
		fore(i,0,n+5)if(x>>i&1){
			if(a[1ll<<i]&1)now|=a[x^(1ll<<i)];
			if(a[1ll<<i]>>1&1)now|=a[x^(1ll<<i)]<<1;
		}
		a[x]&=now;
	}
	vector<ll>c(n+1);
	fore(i,0,m)c[ppc(i)]++;
	ll res=0;
	fore(i,0,n+1)if(a[m-1]>>i&1)res+=c[i];
	cout<<res<<"\n";
	return 0;
}
