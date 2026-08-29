#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e6+100;
ll h[maxn];
ll dp[maxn][3][3];
ll n,m;

const ll inf  = 1e16;

ll f(int p, int a1, int a2){
	if(p > m) return a1+a2 ? -inf : 0; 
	ll &r = dp[p][a1][a2];
	if(r!=-1) return r;
	ll auxh = h[p] - a1-a2;
	if(auxh < 0){
		r = -inf;
		return r;
	}
	r=-inf;
	fore(i,0,3) if(auxh >= i)r = max(r,f(p+1,a2,i) + i +(auxh-i)/3);

	return r;
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n){
		ll x; cin>>x;
		h[x]++;
	}
	mset(dp,-1);
	cout<<f(0,0,0)<<"\n";
	// fore(i,1,m+1){
		// fore(j,0,3)fore(k,0,3){
			// cout<<"dp "<<i<<" "<<j<<" "<<k<<" es "<<dp[i][j][k]<<"\n";
		// }
	// }
	return 0;
}

