#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e9;
int main(){
	JET
	ll n; cin>>n;
	ll a[2][2];
	fore(i,0,2)fore(j,0,2)cin>>a[i][j];
	swap(a[1][0],a[0][1]);
	ll det=abs(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	// cout<<"determinante "<<det<<"\n";
	ll g=gcd(a[0][0],a[0][1]);
	if(n!=det){
		cout<<"NO\n";
		return 0;
	}
	vector<ii>ret;
	fore(i,0,g)fore(j,0,det/g)ret.pb({i,j});
	cout<<"YES\n";
	for(auto [i,j]:ret){
		// i-=INF,j-=INF;
		cout<<i<<" "<<j<<"\n";
	}
	return 0;
}