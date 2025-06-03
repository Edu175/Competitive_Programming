#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n,m;
vv a;
vv b;
vv vis;
void f(){
	if(SZ(a)==n&&SZ(b)==m){
		cout<<"Yes\n";
		for(auto i:a)cout<<i<<" ";;cout<<"\n"; // NO es modular
		for(auto i:b)cout<<i<<" ";;cout<<"\n";
		exit(0);
	}
	ll w=SZ(a)==n;
	vv &v=(w?b:a);
	ll s=!SZ(v)?1:v.back()+1;
	// ll e=!SZ(a)||SZ(a)==n?1:n*m;
	fore(val,s,n*m+1){
		v.pb(val);
		if(SZ(b)){
			assert(w);
			ll fg=1;
			for(auto i:a){
				ll p=i*val%(n*m);
				fg&=vis[p]==0,vis[p]++;
			}
			if(fg)f();
			for(auto i:a){
				ll p=i*val%(n*m);
				vis[p]--;
			}
		}
		else f();
		v.pop_back();
	}
}

int main(){
	JET
	ll t; cin>>t;
	assert(t==1);
	while(t--){
		cin>>n>>m;
		vis.resize(n*m);
		f();
		cout<<"No\n";
	}
	return 0;
}