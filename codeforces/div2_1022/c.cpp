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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		priority_queue<ii>pos,vec;
		vv vis(n);
		fore(i,0,n)cin>>a[i],pos.push({a[i],i});
		ll res=0;
		auto empty=[&](){
			while(SZ(pos)&&vis[pos.top().snd])pos.pop();
		};
		vv invec(n);
		while(SZ(pos)){
			empty();
			if(!SZ(pos))break;
			res++;
			auto [v,i]=pos.top();
			vec.push({v,i}); invec[i]=1;
			while(SZ(vec)){
				auto [v,i]=vec.top();
				empty();
				if(!SZ(pos)||v!=pos.top().fst)break;
				vis[i]=1; vec.pop();
				if(i&&!invec[i-1])vec.push({a[i-1],i-1}),invec[i-1]=1;
				if(i<n-1&&!invec[i+1])vec.push({a[i+1],i+1}),invec[i+1]=1;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
