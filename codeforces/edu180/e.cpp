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
const ll MAXN=30,LGMXM=20,INF=1e6;
ll n;
ll g[MAXN][MAXN];
ll cant(){ // dado n g
	ll dp[n];
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i]; res=1;
		fore(j,i+1,n)if(g[i][j])res=min(INF,res*(dp[j]+2));
		if(res>=INF)return INF;
	}
	return dp[0];
}
ll ans[INF];
ll acum=0;
ll prim=1;
bool doit(ll _n){
	n=_n;
	if(n==0)return 1;
	ll num=cant();
	if(num>=INF)return 0;
	// cerr<<n<<" "<<num<<"\n";
	if(n==13&&prim){
		prim=0;
		fore(i,0,n){
			fore(j,0,n)cerr<<g[i][j];
			cerr<<"\n";
		}
		cerr<<": "<<num<<'\n';
	}
	if(ans[num]==-1||n<ans[num]){
		if(ans[num]==-1){
			// cerr<<"encontre nuevo!!\n";
			// cerr<<"voy "<<++acum<<"\n";
		}
		ans[num]=n;
		// cerr<<"encontre num="<<num<<" con n="<<n<<"\n";
	}
	return 1;
}
void f(ll i){
	if(doit(i)){
		if(i>=11)return;
		fore(p,0,i){
			g[p][i]=1;
			f(i+1);
			g[p][i]=0;
		}
	}
}
int main(){FIN;
	mset(ans,-1);
	f(1);
	ll cant=0;
	ll mx=0;
	fore(i,0,5e5)if(i&1){
		if(ans[i]==-1){
			// cout<<"!! "<<i<<"\n";
			cant++;
		}
		else mx=max(mx,i);
	}
	fore(i,0,5e5+5)if(i&1){
		cout<<ans[i]<<", ";
	}cout<<"\n";
	cerr<<"no cubiertos "<<cant<<"\n";
	cerr<<"max cubierto "<<mx<<"\n";
	// ll t; cin>>t;
	// while(t--){
		
	// }
	return 0;
}
