#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	vector<ll> mz(n,m);
	fore(i,0,n){
		for(ll j=m-1;j>=0&&a[i][j]==0;j--)mz[i]=j;
	}
	vector<bint>s(n,0);
	vector<ll>res;
	fore(j,0,m){
		vector<ll>dont;
		fore(i,0,n)if(mz[i]<=j+1&&a[i][j]!=0&&s[i]%a[i][j]==0)
			dont.pb(-s[i]/a[i][j]);
		ll k=0;
		sort(ALL(dont));
		for(auto i:dont)if(i==k)k++;
		res.pb(k);
		fore(i,0,n)s[i]+=a[i][j]*k;
	}
	imp(res);
	return 0;
}

