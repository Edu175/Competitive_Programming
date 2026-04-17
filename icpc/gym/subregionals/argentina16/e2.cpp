#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto jsdh:v)cout<<jsdh<<" ";cout<<endl;}
using namespace std;
typedef int_fast16_t ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
random_device rd;
mt19937 rng(rd());
const ll MAXN=1000;

vector<ll>g[MAXN];
vector<ll>h;
ll a[MAXN][MAXN];
ll n,m;
void filter(){
	auto hi=h;
	sort(ALL(hi));
	h.clear();
	for(auto i:hi)if(!SZ(h)||h.back()!=i)h.pb(i);
}
void go(ll j){
	vector<ll>hi;
	for(auto i:h)hi.pb(a[i][j]);
	h=hi;
}
vector<ll>p;
bool done=0,flag=0;
bool vis[MAXN][MAXN];
bool cond(ll x, ll y){
	if(flag)return x==0;
	return x==y;
}
void dfs(ll x, ll y, ll c=-1){
	if(done||vis[x][y])return;
	// cout<<"dfs "<<x<<" "<<y<<" "<<c<<"\n";
	vis[x][y]=1;
	if(c!=-1)p.pb(c);
	if(cond(x,y)){
		done=1;
		return;
	}
	fore(j,0,m)if(!done){
		ll x2=a[x][j],y2=a[y][j];
		dfs(x2,y2,j);
	}
}
int main(){JET
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j],a[i][j]--;
	fore(i,0,n)h.pb(i);
	while(h!=vv({0})){
		// imp(h);
		done=0;
		//fore(i,0,n)fore(j,0,n)vis[i][j]=0;
		mset(vis,0);
		p.clear();
		
		ll x,y;
		if(SZ(h)==1)flag=1,x=y=h[0];
		else {
			ll i=rng()%SZ(h),j=rng()%(SZ(h)-1);
			if(j>=i)j++;
			x=h[i],y=h[j];
		}
		dfs(x,y);
		if(!done){
			cout<<"N\n";
			exit(0);
		}
		// imp(p);
		// cout<<endl;
		for(auto c:p)go(c);
		filter();
	}
	cout<<"S\n";
	return 0;
}