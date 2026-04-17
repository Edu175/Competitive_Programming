#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	ll a[n][m];
	fore(i,0,n)fore(j,0,m) cin>>a[i][j];
	ll rta = 0;
	fore(j,0,m){
		ll loc = 0;
		fore(i,0,n) loc = max(loc,a[i][j]);
		rta+=loc;
	}
	cout<<rta<<"\n";
	return 0;
}