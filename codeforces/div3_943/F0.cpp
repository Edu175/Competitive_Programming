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
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll>a(n),x(n+1);
		fore(i,0,n)cin>>a[i],x[i+1]=x[i]^a[i];
		map<ll,vector<ll>>mp;
		fore(i,0,n+1)mp[x[i]].pb(i);
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll p=x[r]^x[l];
			if(p==0){
				cout<<"YES\n";
				continue;
			}
			if(r-l<=2){
				cout<<"NO\n";
				continue;
			}
			auto v=mp[p^x[l]];
			auto pos=upper_bound(ALL(v),l)-v.begin();
			if(pos>=SZ(v)){
				cout<<"NO\n";
				continue;
			}
			auto u=mp[x[l]];
			ll q=upper_bound(ALL(u),v[pos])-u.begin();
			if(q>=SZ(u)||u[q]>r){
				cout<<"NO\n";
			}
			else cout<<"YES\n";
		}
	}
	return 0;
}
