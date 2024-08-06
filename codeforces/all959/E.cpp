#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll B=25;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,sjkgbg; cin>>n;
		vector<ll>a(n),c(B);
		fore(i,0,n){
			cin>>a[i];
			fore(j,0,B)c[j]+=a[i]>>j&1;
			fore(j,0,a[i]-1)cin>>sjkgbg;
		}
		ll res=0,did=0;
		for(ll j=B-1;j>=0;j--){
			if(c[j]||did)res|=1ll<<j;
			did|=c[j]>1;
		}
		cout<<res<<"\n";
	}
	return 0;
}
