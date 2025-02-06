#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


const int maxn = 2e5+10;
ll n,k;
ll a[maxn];
ll dp[maxn][2];
set<ll> se[maxn];

ll f (ll i, ll b){
	ll &rta=dp[i][b];
	if(i==n){
		return 0;
	}
	if(rta!=-1) return rta;
	rta=f(i+1,0);
}




int main(){
	JET
	
}