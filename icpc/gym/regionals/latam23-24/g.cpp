#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e8;
ll n;
vector<ii>a,xr,yr;
set<ii>ret;
ii operator&(ii a, ii b){
		return {max(a.fst,b.fst),min(a.snd,b.snd)};
}

const ll MAXN=1e5+5;
set<pair<ii,ii>> st[MAXN];

void f(ll i, ii xs, ii ys){
	if(xs.fst>xs.snd||ys.fst>ys.snd)return;
	if(st[i].count({xs,ys}))return;
	st[i].insert({xs,ys});
	// cout<<i<<": "<<xs.fst<<","<<xs.snd<<" "<<ys.fst<<","<<ys.snd<<endl;
	if(i==n){
		fore(a,xs.fst,xs.snd+1)fore(b,ys.fst,ys.snd+1)
			if(!((a+b)&1))ret.insert({(b-a)/2,(a+b)/2});
		return;
	}
	auto [l,r]=xr[i];
	auto [d,u]=yr[i];
	f(i+1, xs & ii({l,l}), ys & yr[i]);
	f(i+1, xs & ii({r,r}), ys & yr[i]);
	f(i+1, xs & xr[i], ys & ii({d,d}));
	f(i+1, xs & xr[i], ys & ii({u,u}));
}

int main(){
	ET;
	cin>>n;
	fore(i,0,n){
		ll x,y,d; cin>>x>>y>>d;
		a.pb({y-x,x+y});
		x=a.back().fst,y=a.back().snd;
		xr.pb({x-d,x+d});
		yr.pb({y-d,y+d});
	}
	f(0,{-INF,INF},{-INF,INF});
	vector<ii>res;
	for(auto [x,y]:ret){
		cout<<x<<" "<<y<<"\n";
	}
}