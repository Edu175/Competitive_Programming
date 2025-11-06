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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y+1<<" ";
    out<<"}";
    return out;
}

map<vv,vv> dp;
ll n;
vv f(vv a){
	if(dp.count(a))return dp[a];
	auto &res=dp[a];
	res=a;
	fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
		if(a[i]==max(a[j],a[k])+1&&a[i]==min(a[j],a[k])+2){
			auto b=a;
			b[i]-=2,b[j]++,b[k]++;
			res=min(res,f(b));
			cout<<a<<" -> "<<b<<"\n";
			
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		auto res=f(a);
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
