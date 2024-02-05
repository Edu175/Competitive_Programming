#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
struct pt{
	ll x,y;
	pt(){}
};
ld dis(pt a, pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
const ld EPS=1e-9;

bool in(pair<pt,ll> a, pair<pt,ll> b){
	return a.snd<b.snd&&dis(a.fst,b.fst)<b.snd+EPS;
}
const ll MAXN=1005;
pair<pt,ll> a[MAXN];
ld area(ll i){
	return acos(-1)*a[i].snd*a[i].snd;
}
vector<ll>g[MAXN];
ld dp[MAXN][2][2];
bool vis[MAXN][2][2];
ld f(ll x, ll s0, ll s1){
	ld &res=dp[x][s0][s1];
	if(vis[x][s0][s1])return res;
	vis[x][s0][s1]=1;
	ld c0=0;
	if(!s0)c0=area(x);
	else c0=-area(x);
	for(auto y:g[x])c0+=f(y,s0^1,s1);
	
	ld c1=0;
	if(!s1)c1=area(x);
	else c1=-area(x);
	for(auto y:g[x])c1+=f(y,s0,s1^1);
	
	return res=max(c0,c1);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].fst.x>>a[i].fst.y>>a[i].snd;
	fore(i,0,n){
		pair<ld,ll> p={1e14,n};
		fore(j,0,n){
			//cout<<i<<" "
			if(in(a[i],a[j]))p=min(p,{area(j),j});
		}
		g[p.snd].pb(i);
	}
	/*fore(i,0,n+1){
		cout<<i<<": "; imp(g[i]);
	}*/
	//fore(i,0,n+3)fore(j,0,2)fore(k,0,2)dp[i][j][k]=-1;
	ld res=0;
	for(auto y:g[n])res+=f(y,0,0);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
