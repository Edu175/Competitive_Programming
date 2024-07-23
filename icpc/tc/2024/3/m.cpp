#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll uf[MAXN];
ll find(ll x){ return uf[x]<0?x:uf[x]=find(uf[x]);}
bool join(ll x, ll y){
	x=find(x); y=find(y);
	if(x==y) return false;
	// cout<<"joined "<<x<<" "<<y<<"\n";
	if(uf[x]>uf[y]) swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return true;
}
int main(){
	JET
	mset(uf,-1);
	ll n,m,d; cin>>n>>m>>d;
	vector <ii> ed;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--,b--;
		if(a>b)swap(a,b);
		ed.pb({a,b});
	}
	ll q=n;
	for(auto [x,y]:ed){
		if(x!=0)q-=join(x,y);
	}
	if(q-1>d){
		cout<<"NO\n";
		return 0;
	}
	set<ii>res;
	//start
	ll di=0;
	for(auto [x,y]:ed){
		if(x==0&&find(x)!=find(y))di++,q-=join(x,y),res.insert({x,y});
	}
	mset(uf,-1);
	for(auto [x,y]:res)join(x,y);
	
	//a 0
	for(auto [x,y]:ed){
		if(x==0&&di<d&&!res.count({x,y}))di++,q-=join(x,y),res.insert({x,y});
	}
	
	if(di<d){
		cout<<"NO\n";
		return 0;
	}
	for(auto [x,y]:ed){
		if(x!=0)if(join(x,y))res.insert({x,y});
	}
	cout<<"YES\n";
	for(auto [x,y]:res)cout<<x+1<<" "<<y+1<<"\n";
	return 0;
}