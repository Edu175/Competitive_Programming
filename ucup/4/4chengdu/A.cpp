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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		ll dif=abs(sum-100);
		if(sum>100){
			ll c=count(ALL(a),0);
			n-=c;
			if(!(dif<=n/2)){
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
			for(auto &i:a)if(i)i=i*n-dif;
		}
		else {
			if(!(dif<(n+1)/2)){
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
			for(auto &i:a)i=i*n+dif;
			
		}
		imp(a)
	}
	return 0;
}
