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
const ll MAXN=2e5+5;

pair<ii,ll> a[MAXN];
ll dp[MAXN];
int main(){FIN;
	ll n,k,A; cin>>n>>k>>A;
	fore(i,0,n){
		ll x,y,c; cin>>x>>y>>c;
		a[i]={{x,y,c}}
	}
	sort(a,a+n);
	dp[n]=0;
	ll minr
	for(ll i=n-1;i>=0;i--){
		ll &res=dp[i];
		res=min(a[i].snd+dp[i+1],);
	}
	return 0;
}
