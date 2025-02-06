#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

int uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x); y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return 1;
}

vector<array<ll,3>>all,root;
ii mst(ll lam){
	vector<array<ll,4>>ed;
	for(auto [x,y,w]:all)ed.pb({w,0,x,y});
	for(auto [x,y,w]:root)ed.pb({w+lam,1,x,y});
	sort(ALL(ed));
	mset(uf,-1);
	ll res=0,cnt=0;
	// cout<<"mst "<<lam<<":\n";
	for(auto [w,is,x,y]:ed){
		if(uf_join(x,y))res+=w,cnt+=is;
		// ,cout<<"chosen "<<x<<","<<y<<" "<<w<<"\n";
	}
	// cout<<res<<" "<<cnt<<"\n";
	return {res,cnt};
}

const ll INF=2e9;
int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		if(!u||!v)root.pb({u,v,w});
		else all.pb({u,v,w});
	}
	// cout<<"all: ";;for(auto [x,y,w]:all)cout<<x<<","<<y<<","<<w<<" ";;cout<<"\n";
	// cout<<"root: ";;for(auto [x,y,w]:root)cout<<x<<","<<y<<","<<w<<" ";;cout<<"\n";
	ll l=-INF,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(mst(m).snd>k)l=m+1;
		else r=m-1;
	}
	ll lam=l;
	// cerr<<lam<<" lambda\n";
	if(lam>=INF){cout<<"-1\n";return 0;}
	auto [res,cnt]=mst(lam);
	// res+=(k-cnt)*lam;
	res-=k*lam;
	cout<<res<<"\n";
	return 0;
}