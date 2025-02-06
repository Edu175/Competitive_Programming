#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105;
ll cnt=98;

ii g[MAXN];

ll add(ll x, ll y){
	ll r=cnt--;
	// cout<<"add "<<r<<": "<<x<<" "<<y<<endl;
	assert(r>=0);
	g[r]={x,y};
	return r;
}

ll cv(ll n){return n==-1?n:n+1;}

int main(){
	JET
	fore(i,0,MAXN)g[i]={-1,-1};
	vv pot;
	pot.pb(add(99,-1));
	pot.pb(add(99,-1));
	fore(i,1,30){
		auto y0=pot.back(); pot.pop_back();
		auto y1=pot.back();
		pot.pb(add(y0,y1));
		pot.pb(add(y0,y1));
	}
	pot.pop_back();
	// cout<<SZ(pot)<<endl;
	vv nod;
	ll k; cin>>k;
	fore(i,0,30)if(k>>i&1)nod.pb(pot[i]);
	while(SZ(nod)>1){
		auto y0=nod.back(); nod.pop_back();
		auto y1=nod.back(); nod.pop_back();
		nod.pb(add(y0,y1));
	}
	g[0]={nod[0],-1};
	vv dp(100);
	dp[99]=1;
	for(ll i=98;i>=0;i--){
		if(g[i].fst!=-1)dp[i]+=dp[g[i].fst];
		if(g[i].snd!=-1)dp[i]+=dp[g[i].snd];
	}
	// fore(i,0,100)cout<<i<<": "<<dp[i]<<"\n";
	// cout<<dp[0]<<endl;
	assert(dp[0]==k);
	cout<<"100\n";
	fore(i,0,100){
		cout<<cv(g[i].fst)<<" "<<cv(g[i].snd)<<"\n";
	}
	return 0;
}