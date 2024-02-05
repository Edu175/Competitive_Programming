#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

map<vector<ll>,ll> dp[MAXN];
ll n;
ll A[MAXN];
ll f(ll i, vector<ll>a){
	if(dp[i].count(a))return dp[i][a];
	ll& res=dp[i][a];
	if(i==n)return res=0;
	res=n;
	fore(j,0,SZ(a)){
		vector<ll>ai=a; ai[j]=A[i];
		res=min(res,(a[j]!=ai[j])+f(i+1,ai));
	}
	return res;
}

int main(){FIN;
	ll k,c; cin>>n>>k>>c;
	fore(i,0,n)cin>>A[i];
	vector<ll>a;
	fore(i,0,k)a.pb(A[i]);
	cout<<f(k,a)*c<<"\n";
	return 0;
}
