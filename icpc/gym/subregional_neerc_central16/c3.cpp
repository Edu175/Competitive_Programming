#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<ii> solve(ll n, ll m){
	if(n==1||m==1)return {};
	vector<ii>ret;
	if(m&1){
		fore(i,0,n-1)if(i%2==0)ret.pb({i,m-2});
	}
	fore(i,0,n-1)fore(j,0,m-1)if(j%2==0){
		ret.pb({i,j});
	}
	return ret;
}
 
int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m; cin>>n>>m;
	if(n==1||m==1){cout<<"0\n";return 0;}
	vector<ii> res;
	fore(i,0,n-1)res.pb({i,0});
	fore(i,0,n-1)fore(j,1,m-1)if(i%2==0)res.pb({i,j});
	if(n&1){
		fore(j,2,m-1)if(j%2==0)res.pb({n-2,j});
	}
	reverse(ALL(res));
	cout<<SZ(res)<<"\n";
	for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
	return 0;
 }