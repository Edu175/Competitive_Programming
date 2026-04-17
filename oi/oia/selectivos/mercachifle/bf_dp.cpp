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
const ll MAXN=4005;

struct node{
	ll l,r,t,idx;
	node(ll l,ll r,ll t,ll idx):l(l),r(r),t(t),idx(idx){};
	node(){};
};
bool operator<(node a,node b){
	pair<ll,ll>c={a.l,a.r},d={b.l,b.r};
	return c<d;
}
ll n=0;
vector<node> a;
map<pair<ll,ii>,ll> dp;
set<pair<ll,ii>> vis;
ll f(ll i, ll r, ll b){
	ll &res=dp[{i,{r,b}}];
	if(vis.count({i,{r,b}}))return res;
	vis.insert({i,{r,b}});
	if(i==n){
//		cout<<i<<" "<<r<<": 0\n";
		return res=0;
	}
	//vector<ll>db;
	res=f(i+1,r,b);
	//db.pb(res);
	if(r<a[i].l||b==a[i].t){
		res=max(res,1+f(i+1,max(r,a[i].r),a[i].t));
//		      db.pb(1+f(i+1,max(r,a[i].r),a[i].t));
	}
/*	cout<<i<<" "<<r<<": "<<(r<a[i].l)<<" "<<(b==a[i].t)<<": ";
	for(auto i:db)cout<<i<<" ";
	cout<<"= "<<res<<"\n";*/
	return res;
}
vector<ll>ans[2];
void build(ll i, ll r,ll b){
	ll &res=dp[{i,{r,b}}];
	if(i==n)return;
	if(res==f(i+1,r,b))build(i+1,r,b);
	else ans[a[i].t].pb(a[i].idx),build(i+1,max(r,a[i].r),a[i].t);
}
int main(){FIN;
	//ifstream cin; cin.open("mercachifle.in", ios::in);
	//ofstream cout; cout.open("mercachifle.out", ios::out);
	ll m;
	fore(i,0,2){
		cin>>m;
		n+=m;
		fore(j,0,m){
			ll l,r; cin>>l>>r;
			a.pb(node(l,r,i,j));
		}
	}
	sort(ALL(a));
//	for(auto i:a)cout<<"["<<i.l<<","<<i.r<<"]"<<i.t<<" ";
//	cout<<"\n";
	cout<<f(0,-1,-1)<<"\n";
	build(0,-1,-1);
	/*fore(i,0,2){
		//sort(ALL(ans[i]));
		for(auto j:ans[i])cout<<j+1<<" ";
		cout<<"\n";
	}*/
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

