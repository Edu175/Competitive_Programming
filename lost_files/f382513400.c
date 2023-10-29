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
const ll MAXN=1e3+5,MAXS=4e4+5;

struct node{
	ll w=0,s=0,v=0;
	node(){};
};
bool operator<(node a, node b){
	return a.s+a.w>b.s+b.w;
}
ll n;
ll dp[MAXN][MAXS];
node a[MAXN];
ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res!=-1)return res;
	if(i==n)return res=0;
	res=f(i+1,s);
	if(a[i].w<=s)res=max(res,a[i].v+f(i+1,min(s-a[i].w,a[i].s)));
	return res;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a,a+n);
	mset(dp,-1);
	cout<<f(0,MAXS-1)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

