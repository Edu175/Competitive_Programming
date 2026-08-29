#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const ll MAXN=1502;

ld dp[2][MAXN][MAXN];
int main(){
    JET
    ll n,k; cin>>n>>k;
	vv oc(4);
	fore(i,0,k+1)cin>>oc[i];
	ld coef=1;
	ll tot=0;
	fore(i,0,4)tot+=oc[i]*(i-1);
	if(tot<-1){
		cout<<"0\n";
		return 0;
	}
	if(tot==-1){
		coef=ld(oc[0])/n; // prob de que el ult sea un 0
		oc[0]--;
		n--;
	}
	n-=oc[1];
	dp[0][0][0]=1;
	fore(i,0,n)fore(a,0,min(i,oc[0])+1)fore(b,max(i-a-oc[3],0ll),min(i-a,oc[2])+1){
		ll c=i-a-b;
		ll s=-a+b+(c<<1);
		if(s<0)break; // only last loop
		ll me=i&1,otr=me^1;
		auto &now=dp[me][a][b];
		// assert(now);
		ll que=n-a-b-c;
		if(s)dp[otr][a+1][b]+=(now*(oc[0]-a))/que;
		dp[otr][a][b+1]+=(now*(oc[2]-b))/que;
		dp[otr][a][b]+=(now*(oc[3]-c))/que;
		now=0;
	}
	ld res=dp[n&1][oc[0]][oc[2]];
	// cerr<<"res inicial "<<res<<"\n";
	// cout<<"res 1 "<<res<<"\n";
	res*=coef;
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}
