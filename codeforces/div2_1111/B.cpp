#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,m; cin>>n>>k>>m;
		if(k>m){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		vv sp(n+1);
		fore(i,0,SZ(sp))sp[i]=i%k;
		vv a(n);
		fore(i,0,n){
			a[i]=sp[i+1]-sp[i];
			if(a[i]<=0)a[i]+=m;
		}
		show(a)
	}
	return 0;
}
