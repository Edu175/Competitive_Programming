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
		ll n,m; cin>>n>>m;
		string s; cin>>s; s.pb('R');
		// casi le meto dinic
		// igual seguro da tle
		ll a[n][m];
		vv sf(n),sc(m);
		fore(i,0,n)fore(j,0,m)cin>>a[i][j],sf[i]+=a[i][j],sc[j]+=a[i][j];
		ll des=0;
		for(ll i=0,j=0,k=0;k<SZ(s)&&i<n&&j<m;k++){
			// cout<<i<<","<<j<<" "<<k<<"\n";
			ll sum=sf[i];
			if(s[k]=='R')sum=sc[j];
			a[i][j]=des-sum;
			sf[i]+=a[i][j],sc[j]+=a[i][j];
			if(s[k]=='R')j++;
			else i++;
		}
		// cout<<des<<"\n";
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
