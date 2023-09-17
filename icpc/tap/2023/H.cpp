#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ii p[n*n];
	ll a[n][n];
	fore(i,0,n)fore(j,0,n){
		cin>>a[i][j]; a[i][j]--;
		p[a[i][j]]={i,j};
	}
	//ll dp[2][n][n];
	ll mx[2][n]={};
	ll res=0;
	for(ll x=n*n-1;x>=0;x--){
		ll i=p[x].fst,j=p[x].snd;
		ll my[2]={};
		my[0]=mx[1][j]+1;
		my[1]=mx[0][i]+1;
		mx[0][i]=max(mx[0][i],my[0]);
		mx[1][j]=max(mx[1][j],my[1]);
		res=max({res,my[0],my[1]});
		//cout<<x<<": "<<my[0]<<" "<<my[1]<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
