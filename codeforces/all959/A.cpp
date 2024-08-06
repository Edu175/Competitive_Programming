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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n*m);
		fore(i,0,n*m)cin>>a[(i+1)%(n*m)];
		if(n*m==1){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,n){
			fore(j,0,m)cout<<a[i*m+j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
