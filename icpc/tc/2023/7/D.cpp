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
const ll MAXM=105,MAXN=MAXM;

ll dp[MAXM][MAXM];

ll n,m;
ll ls[MAXN][MAXM],rs[MAXN][MAXM]; // [,]

ll f(ll l, ll r){ // hubo en l y r
	auto &res=dp[l][r];
	if(res!=-1)return res;
	res=0;
	fore(m,l+1,r){
		ll q=0;
		fore(i,0,n)q+=l<ls[i][m]&&rs[i][m]<r;
		// cout<<l<<","<<r<<" "<<m<<": "<<q<<"\n";
		ll cur=q*q+f(l,m)+f(m,r);
		res=max(res,cur);
	}
	// cout<<l<<","<<r<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n){
		ll k; cin>>k;
		auto &le=ls[i];
		auto &re=rs[i];
		fore(_,0,k){
			ll l,r; cin>>l>>r;
			fore(j,l,r+1)le[j]=l,re[j]=r;
		}
	}
	mset(dp,-1);
	ll res=f(0,m+1);
	cout<<res<<"\n";
	return 0;
}
