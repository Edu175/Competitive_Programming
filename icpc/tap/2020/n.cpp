#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef __int128 xl;

vector<ll> g[1005];
int main(){
	JET
	ll m,n,k; cin>>m>>n>>k;
	ll c[n]; fore(i,0,n) cin>>c[i];
	fore(i,0,k){
		ll a,b,d;
		cin>>a>>b>>d; a--,b--;
		g[a].pb(b);
	}
	ll rta[m];
	ll u=2;
	fore(i,0,m){
		// cout<<c[g[i][0]]<<"d"<<endl;
		for(;u*u<=c[g[i][0]]; u++){
			if(!(c[g[i][0]]%u)) break;
		}
		if((c[g[i][0]]%u)) u=c[g[i][0]];
		// cout<<u<<endl;
		cout<<i<<endl;
		rta[i]=u;
		for(auto j:g[i]){
			while(!(c[j]%u))c[j]/=u;
		}
	}
	fore(i,0,m)cout<<rta[i]<<" ";;cout<<"\n";
	return 0;
}