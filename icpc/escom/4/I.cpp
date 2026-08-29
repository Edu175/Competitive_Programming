#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x; x--;
		vv deg(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			deg[u]++,deg[v]++;
		}
		ll w;
		if(deg[x]<=1)w=0;
		else w=n&1;
		vector<string> pla={"Ayush","Ashish"};
		cout<<pla[w]<<"\n";
	}
    return 0;
}
