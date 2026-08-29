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

map<pair<ll,vv>,ll> dp;

ll f(vv a, ll p){ // is winning for p
	sort(ALL(a));
	pair<ll,vv> key={p,a};
	if(dp.count(key))return dp[key];
	auto &res=dp[key];
	fore(i,0,SZ(a))if(!i||a[i]!=a[i-1]){
		fore(c,1,a[i]+1){
			auto b=a;
			b[i]-=c;
			if(!b[i])b.erase(b.begin()+i);
			if(!SZ(b))return res=1;
			auto nxt=f(b,(p+1)%3);
			if(p==1&&nxt)return res=1;
			if(p!=1&&!nxt)return res=1;
		}
	}
	return res=0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		auto got=f(a,0);
		if(got)cout<<"Sprague\n";
		else cout<<"Grundy\n";
	}
	return 0;
}
