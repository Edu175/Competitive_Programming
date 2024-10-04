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
const ll MAXN=5105;

vector<ll>divs[MAXN];
ll dp[MAXN][MAXN];

ll f(ll n, ll d){
	ll &res=dp[n][d];
	if(res!=-1)return res;
	if(d==0)return res=1;
	res=0;
	for(auto v:divs[n])res+=f(v,d-1);
	return res;
}

int main(){FIN;
	mset(dp,-1);
	fore(i,1,MAXN)for(ll j=i;j<MAXN;j+=i)divs[j].pb(i);
	ll n,d; cin>>n>>d;
	cout<<f(n,d)<<"\n";
	ll m; cin>>m;
	cout<<f(m,d)<<"\n";
	cout<<f(n,d)*f(m,d)<<" "<<f(n*m,d)<<"\n";
	return 0;
}
