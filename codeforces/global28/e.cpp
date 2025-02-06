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
		ll n,m; cin>>n>>m;
		if(m>=2*n){cout<<"NO\n";continue;}
		cout<<"YES\n";
		vector<vv> res(2*n,vv(m,-1));
		vector<ii> rev[m];
		fore(c,0,n){
			fore(x,0,m){
				ll y=(x+1+2*c)%(2*n);
				rev[x].pb({y,c});
				rev[x].pb({(y+1)%(2*n),c});
			}
		}
		fore(x,0,m)for(auto [y,c]:rev[x]){
			// cout<<x<<": "<<y<<" "<<c<<endl;
			res[y][x]=c;
		}
		for(auto v:res){
			for(auto i:v)assert(i!=-1),cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
