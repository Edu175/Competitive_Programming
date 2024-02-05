#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

//binary gcd (already implemented in std::gcd but not in __gcd)
inline ll remtz(ll a){
	return a>>__builtin_ctz(a);
}

ll gcd_odd(ll a, ll b){
	while(a!=b){
		if(a<b)swap(a,b);
		a=remtz(a-b);
	}
	return a;
}
ll gcd(ll a, ll b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd_odd(remtz(a),remtz(b))<<min(__builtin_ctz(a),__builtin_ctz(b));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		vector<ii>v;
		for(ll i=n-1;i>=0;i--){
			vector<ii>vi;
			v.pb({a[i],i});
			for(auto [g,e]:v){
				g=gcd(g,a[i]);
				if(!SZ(vi)||g!=vi.back().fst)vi.pb({g,e});
			}
			v=vi;
			//cout<<i<<": ";;for(auto [i,j]:v)cout<<i<<","<<j<<" ";;cout<<"\n";
			for(auto [g,e]:v)res=max(res,g*(e-i+1));
		}
		cout<<res<<"\n";
	}
	return 0;
}
