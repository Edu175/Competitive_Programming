#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
ll tle;
ll count(vector<ll> &v, ll x){
	ll upp=upper_bound(ALL(v),x)-v.begin();
	ll low=lower_bound(ALL(v),x)-v.begin();
	tle+=log2(SZ(v));
	return upp-low;
}

vector<ll> res[22][22];
ll a[22][22];
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		fore(j,0,n)cin>>a[i][j];
	}
	res[0][0]={a[0][0]};
	res[n-1][n-1]={a[n-1][n-1]};
	fore(i,0,n-1){
		for(int j=0; i+j<n-1;j++){
			if(i){
				for(auto k:res[i-1][j]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(j){
				for(auto k:res[i][j-1]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(i+j==n-2)sort(ALL(res[i][j])),tle+=SZ(res[i][j])*log2(SZ(res[i][j]));
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=n-1;i+j>n-1;j--){
			if(i<n-1){
				for(auto k:res[i+1][j]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(j<n-1){
				for(auto k:res[i][j+1]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(i+j==n)sort(ALL(res[i][j]));
		}
	}
	ll sum=0;
	for(int i=0,j=n-1;i<n&&j>=0;i++,j--){
		if(i){
			for(auto k:res[i-1][j]){
				if(i<n-1)sum+=count(res[i+1][j],k^a[i][j]);
				if(j<n-1)sum+=count(res[i][j+1],k^a[i][j]);
			}
		}
		if(j){
			for(auto k:res[i][j-1]){
				if(i<n-1)sum+=count(res[i+1][j],k^a[i][j]);
				if(j<n-1)sum+=count(res[i][j+1],k^a[i][j]);
			}
		}
	}
	cout<<sum<<"\n";
	//cout<<"operations: "<<tle<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
