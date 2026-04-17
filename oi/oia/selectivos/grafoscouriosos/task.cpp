#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
// given permutation, create curious graph or report that it is impossible

const ll MAXN=1e6+5;
vector<ii>g[MAXN];
ll vis[MAXN],c[MAXN];
ll n,flag;
ll cv(ll i, ll j){return n*i+j;};
void dfs(ll x, ll d){
	//cout<<"dfs "<<x<<" "<<d<<"\n";
	if(vis[x]){
		flag&=(d==c[x]);
		//cout<<"return\n";
		return;
	}
	c[x]=d;
	vis[x]=1;
	//for(auto [y,w]:g[x])cout<<y<<","<<w<<" ";;cout<<"\n";
	for(auto [y,w]:g[x])dfs(y,d^w);
}
int main(){
	ll t; cin>>t;
	cout<<t<<"\n";
	while(t--){
		cin>>n;
		cout<<n<<"\n";
		if(n%4>1){cout<<"0\n";continue;}
		fore(i,0,n*n)g[i].clear(),vis[i]=c[i]=0;
		vector<ll>a(n);
		fore(i,0,n)a[i]=i+1;
		if(n&1)a[n-2]=0,a[n-1]=n-1;
		else a[n-1]=0;
		//auto cv=[&](ll x){return ii({n/i,n%i});};
		fore(i,0,n)fore(j,0,n)if(i!=j){
			g[cv(i,j)].pb({cv(a[i],a[j]),1});
			g[cv(i,j)].pb({cv(j,i),0});
		}
		/*fore(i,0,n)fore(j,0,n){
			cout<<cv(i,j)<<": ";
			for(auto [y,w]:g[cv(i,j)])cout<<y<<","<<w<<" ";
			cout<<"\n";
		}*/
		ll flag=1;
		fore(i,0,n)fore(j,0,n)if(i!=j){
			//cout<<"new root "<<cv(i,j)<<"\n";
			dfs(cv(i,j),c[cv(i,j)]);
		}
		if(!flag){
			cout<<"NOT POSSIBLE\n";
			continue;
		}
		//cout<<"1\n"<<n<<"\n1\n";
		cout<<"1\n";
		imp(a);
		fore(i,0,n){
			fore(j,0,n)cout<<c[cv(i,j)];
			cout<<"\n";
		}
	}
	return 0;
}
