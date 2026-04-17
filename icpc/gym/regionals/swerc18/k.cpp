#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=705;
ll memlcp[MAXN][MAXN];

string s;
ll n;

ll lcp(ll i, ll j){
	auto &res=memlcp[i][j];
	if(res!=-1)return res;
	if(i==n||j==n||s[i]!=s[j])return res=0;
	return res=1+lcp(i+1,j+1);
}

bool match(ll i, ll j, ll k){ // length k
	ll l=lcp(i,j);
	return k<=l;
}

ll dp[MAXN][MAXN];

int main(){
    JE
	mset(memlcp,-1);
	// mset(dp,-1);
	cin>>n;
	cin>>s;
	vector<vv> divs(n+1); // propios
	fore(z,1,n+1){
		fore(d,1,z)if(z%d==0)divs[z].pb(d);
	}
	for(ll l=n-1;l>=0;l--)fore(r,l+1,n+1){
		auto &res=dp[l][r];
		if(r-l==1){res=1;continue;}
		// cout<<l<<","<<r<<":\n";
		res=r-l+5;
		fore(m,l+1,r)res=min(res,dp[l][m]+dp[m][r]);
		// fore(d,1,r-l+1)if((r-l)%d==0){
		for(auto d:divs[r-l]){
			// cout<<d<<"?\n";
			if(match(l,l+d,r-l-d)){
				// cout<<"match "<<d<<": "<<l<<","<<l+d<<"\n";
				res=min(res,dp[l][l+d]);
			}
		}
		// cout<<" = "<<res<<"\n\n";
	}
	cout<<dp[0][n]<<"\n";
    return 0;
}