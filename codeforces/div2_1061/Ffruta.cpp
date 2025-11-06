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
		fore(i,0,n)cin>>a[i],a[i]--;
		
		auto relabel=[&](ll l, ll r, ll from, ll to){
			fore(i,l,r){
				if(to<=a[i]&&a[i]<from)a[i]++;
			}
		};
		
		for(ll i=n-1;i>=0;i--){
			vv vis(n);
			fore(j,i+1,n)vis[a[j]]=1;
			ll v=a[i];
			while(v>=2&&vis[v-1]&&vis[v-2])v-=2;
			relabel(i+1,n,a[i],v);
			a[i]=v;
		}
		
		ll v=0;
		fore(i,0,n)if(a[i]>=v){
			if(a[i]%2!=v%2)v++;
			relabel(i+1,n,a[i],v);
			a[i]=v;
			v++;
		}
		
		for(auto i:a)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
