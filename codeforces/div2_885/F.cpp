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
typedef int ll;
typedef pair<ll,ll> ii;
//O(nlog^2)
const ll K=20,MAXN=1<<20;
ll a[MAXN];
ll n;
ll dp[2][MAXN];
void cv(ll &j){
	if(j>=n)j=0;
}
bool can(ll x){
	auto now=dp[0],prox=dp[1];
	fore(i,0,n)now[i]=a[i];
	for(ll k=K;k>=0;k--){
		if((1<<k)>x)continue;
		x-=1<<k;
		swap(now,prox);
		ll j=1<<k;	cv(j);
		for(ll i=0;i<n;i++,cv(++j))now[i]=prox[i]^prox[j];
	}
	ll flag=1;
	fore(i,0,n)if(now[i])flag=0;
	return flag;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
