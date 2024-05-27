#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,0,n)res=(res+a[i]*i)%MOD;
	ll sum=0;
	fore(i,0,n)sum=(sum+fpow(10,SZ(to_string(a[i]))))%MOD;
//	cout<<res<<"\n";
	fore(i,0,n){
		ll sz=fpow(10,SZ(to_string(a[i])));
		sum=(sum-sz+MOD)%MOD;
//		cout<<sum<<" ";
		res=(res+a[i]*sum)%MOD;
	}
//	cout<<"\n";
	cout<<res<<"\n";
	return 0;
}
