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
vector<node> a;	// SZ(a) <= 4000
node b[2][MAXN];
ll dp[MAXN][MAXN];
ll f(ll i, ll r){
	ll &res=dp[i][r];
	if(res!=-1)return res;
	if(i==n){
		//cout<<i<<" "<<r<<": 0\n";
		return res=0;
	}
	//vector<ll>db;
	res=f(i+1,r);
	//db.pb(res);
	if(r==MAXN-1||a[r].r<a[i].l||a[r].t==a[i].t){
		ll ri=r; if(r==MAXN-1||a[i].r>a[r].r)ri=i;
		res=max(res,1+f(i+1,ri));//,db.pb(1+f(i+1,ri));
	}
	/*cout<<i<<" "<<r<<": "<<(r==MAXN-1);
	if(!(r==MAXN-1))cout<<" "<<(a[r].r<a[i].l)<<" "<<(a[r].t==a[i].t);
	cout<<": ";
	for(auto i:db)cout<<i<<" ";
	cout<<"= "<<res<<"\n";*/
	return res;
}
vector<ll>ans[2];
void build(ll i, ll r){
	ll &res=dp[i][r];
	if(i==n)return;
	if(res==f(i+1,r))build(i+1,r);
	else {
		ll ri=r; if(r==MAXN-1||a[i].r>a[r].r)ri=i;
		assert(res==1+f(i+1,ri));
		ans[a[i].t].pb(a[i].idx),build(i+1,ri);
	}
}
int main(){FIN;
	ifstream cin; cin.open("mercachifle.in", ios::in);
	ofstream cout; cout.open("mercachifle.out", ios::out);
	ll m;
	fore(i,0,2){
		cin>>m;
		n+=m;
		fore(j,0,m){
			ll l,r; cin>>l>>r;
			a.pb(node(l,r,i,j));
			b[i][j]=node(l,r,i,j);
		}
	}
	sort(ALL(a));
	/*for(auto i:a)cout<<"["<<i.l<<","<<i.r<<"]"<<i.t<<" ";
	cout<<"\n";*/
	mset(dp,-1);
	ll res=f(0,MAXN-1);
	cout<<res<<"\n";
	build(0,MAXN-1);
//	CHECK VALID ANSWER
	vector<node>ch;
	fore(i,0,2)for(auto j:ans[i])ch.pb(b[i][j]);
	sort(ALL(ch));
	ll r=-1,t=-1,flag=1;
	for(auto i:ch){
		//cout<<"["<<i.l<<","<<i.r<<"]"<<i.t<<" "<<r<<","<<t<<" ";
		if(r>=i.l&&t!=i.t)flag=0;//,cout<<".";
		if(i.r>r)r=i.r,t=i.t;
	}
	assert(flag); assert(SZ(ch)==res);
//	======================
	fore(i,0,2){
		//sort(ALL(ans[i]));
		for(auto j:ans[i])cout<<j+1<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

