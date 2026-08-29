#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto a:x)cout<<a<<" ";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;
const ll MAXV=2e5+1;
// const ll MAXV=10005;

vv divs[MAXV];
ll isc[MAXV];
void init_divisores(){
	isc[0]=isc[1]=1;
	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i){
		divs[j].pb(i);
		isc[j]|=!isc[i]&&j>i;
	}
}

int main(){
	JET
	init_divisores();
	vv dp(MAXV); dp[1]=1;
	fore(i,2,MAXV){
		auto &res=dp[i];
		for(auto d:divs[i])if(d>1&&!isc[d])res+=dp[i/d];
	}
	show(dp)
	ll sum=accumulate(ALL(dp),0ll);
	cout<<"suma "<<sum<<"\n";
	return 0;
}