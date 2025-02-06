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

ll dp[65][25][8];
ll a[65];
ll n;
ll f(ll i, ll v, ll l){
	ll &res=dp[i][v][l];
	if(res!=-1)return res;
	if(l==0)return res=1;
	if(i==n)return res=0;
	if(a[i]!=v)return res=f(i+1,v,l);
	res=0;
	fore(u,v+1,25){
		res+=f(i+1,u,l-1);
	}
	return res;
}

int main(){FIN;
	mset(dp,-1);
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll l; cin>>l;
	cout<<f(0,a[0],l)<<"\n";
	return 0;
}
