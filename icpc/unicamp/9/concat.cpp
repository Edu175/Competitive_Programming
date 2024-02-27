#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=105,MOD=1e9+7;

ll dp[MAXN][MAXN][MAXN*10];
ll dig[MAXN];
ll n;
ll f(ll x, ll i, ll d){
	ll &res=dp[x][i][d];
	if(res!=-1)return res;
	if(i==n){res=(d==0),
	cout<<"f("<<x<<","<<i<<","<<d<<") = "<<res<<"\n";
	return res=(d==0);
	}
	if(i==x){res=f(x,i+1,d),
	cout<<"f("<<x<<","<<i<<","<<d<<") = "<<res<<"\n";
	return res=f(x,i+1,d);
	}
	res=2*f(x,i+1,d)%MOD;
	if(d>=dig[i])res=(res+f(x,i+1,d-dig[i]))%MOD;
	cout<<"f("<<x<<","<<i<<","<<d<<") = "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],dig[i]=SZ(to_string(a[i]));
	mset(dp,-1);
	ll pot=1,res=0;
	fore(d,0,10*n){
		fore(i,0,n){
			res=(res+f(i,0,d)*pot%MOD*a[i])%MOD;
			cout<<i<<" ("<<a[i]<<") "<<d<<": "<<f(i,0,d)<<"*"<<pot*a[i]<<"\n";
		}
		pot=pot*10%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
