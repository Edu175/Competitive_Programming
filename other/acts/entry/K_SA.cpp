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
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=25;

vector<ll>g[MAXN];
ll n,s=0;
ll a[MAXN];
double t=1e9;

void sw(ll i, ll j){
	//fore(k,0,n)if(g[i][k])s-=abs(a[i]-a[k]);
	//fore(k,0,n)if(g[j][k])s-=abs(a[j]-a[k]);
	for(auto k:g[i])s-=abs(a[i]-a[k]);
	for(auto k:g[j])s-=abs(a[j]-a[k]);
	//if(g[i][j])s+=abs(a[i]-a[j]);
	swap(a[i],a[j]);
	//fore(k,0,n)if(g[i][k])s+=abs(a[i]-a[k]);
	//fore(k,0,n)if(g[j][k])s+=abs(a[j]-a[k]);
	for(auto k:g[i])s+=abs(a[i]-a[k]);
	for(auto k:g[j])s+=abs(a[j]-a[k]);
	//if(g[i][j])s-=abs(a[i]-a[j]);
}
ll SA(){
	fore(i,0,n)a[i]=i;
	srand(175);
	random_shuffle(a,a+n);
	fore(i,0,n)for(auto j:g[i])s+=abs(a[i]-a[j]);
	s/=2;
	ll best=s;
	do{
		ll i=rand()%(n-1),j=rand()%(n-1);
		if(j>=i)j++;
		ll old=s;
		sw(i,j);
		best=min(best,s);
		if(!(s<old||exp((old-s)/t)>=(double)rand()/RAND_MAX))sw(i,j);
		t*=0.99999;
	}
	while(clock()<1.9*CLOCKS_PER_SEC);
	cerr<<t<<"\n";
	//fore(i,0,n)cerr<<a[i]<<" ";;cout<<"\n";
	//cerr<<s<<"\n";
	return best;
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	cout<<SA()<<"\n";
	return 0;
}
