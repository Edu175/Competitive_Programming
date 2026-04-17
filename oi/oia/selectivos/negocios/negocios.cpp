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
const ll MAXN=2e3+5;

struct node{
	ll x,y,h,w;
	node(ll x, ll y, ll h, ll w):x(x),y(y),h(h),w(w){};
	node(){};
};
ll dis(node a, node b){return abs(a.x-b.x)+abs(a.y-b.y);}

ll n;
node a[MAXN];
ll dp[MAXN];
ll f(ll i){
	ll &res=dp[i];
	if(res!=-1)return res;
	res=a[i].w;
	fore(j,0,n){
		if(a[i].h+(i==n?0:3)+dis(a[i],a[j])<=a[j].h)res=max(res,a[i].w+f(j));
	}
	return res;
}
vector<ll>ans;
void build(ll i){
	ll &res=dp[i];
	ll maxi=-1;
	fore(j,0,n){
		if(a[i].h+(i==n?0:3)+dis(a[i],a[j])<=a[j].h&&res==a[i].w+f(j))maxi=j;
	}
	if(maxi==-1)return;
	ans.pb(maxi);
	build(maxi);
}
int main(){FIN;
	ifstream cin; cin.open("negocios.in", ios::in);
	ofstream cout; cout.open("negocios.out", ios::out);
	cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y>>a[i].h>>a[i].w;
	a[n]=node(0,0,0,0);
	mset(dp,-1);
	cout<<f(n)<<"\n";
	build(n);
	for(auto i:ans)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
