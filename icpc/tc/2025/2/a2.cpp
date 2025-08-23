#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vector<ii> p;
const int maxn = 75, maxk = 75;
ll dp[maxn][maxk];
ii rec[maxn][maxk];
ll n,k;
ll f(int i, int j){
	//caso base
	if(i<0 || j<0) return 0;
	//
	ll &r = dp[i][j];
	if(r!=-1) return r;
	r = max(f(i-1,j), f(i-1,j-1) + p[i].fst+p[i].snd*(j+1-k));
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		p.resize(n);
		fore(i,0,n) cin>>p[i].fst>>p[i].snd;
		ll totb = 0;
		for(auto [x,y] : p) totb+=y;
		f(0,0);
	}
	return 0;
}