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
		ll a[n][m];
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		fore(i,0,n)fore(j,0,m){
			vector<ll>v;
			if(i)v.pb(a[i-1][j]);
			if(j)v.pb(a[i][j-1]);
			if(i<n-1)v.pb(a[i+1][j]);
			if(j<m-1)v.pb(a[i][j+1]);
			sort(ALL(v));
			if(a[i][j]>v.back())a[i][j]=v.back();
		}
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
