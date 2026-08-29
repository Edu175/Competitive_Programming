#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b;
		ll ref=0;
		if(a<b)swap(a,b),ref=1;
		if(b<a-1||a+b>n-2){
			cout<<"-1\n";
			continue;
		}
		vv res(n); iota(ALL(res),0);
		fore(i,0,a){
			ll p=2*i+1;
			swap(res[p],res[p+1]);
		}
		if(a>b){
			sort(res.begin()+2*a-1,res.end());
			swap(res[n-2],res[n-1]);
		}
		if(ref){
			for(auto &i:res)i=n-1-i;
		}
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
