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
typedef long long ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct pt{
	ld x,y;
	pt(ld x, ld y) :x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	pt operator+(pt p){return pt(x-p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
};


const ll MAXN=1005,INF=9e18;
ll tag[MAXN],k,n,flag=1,dbg=0;
pt a[MAXN],o(0,0);
int cuad(ll x){return a[x].x>0;}
bool valid(ll x, ll y){return (a[x]-a[y]).norm2()<=k;}
void dfs(ll x, ll t){
	// if(dbg)cout<<"dfs "<<x<<" "<<t<<"\n";
	if(tag[x]==t)return;
	if(tag[x]!=INF&&tag[x]!=t){flag=1;return;}
	tag[x]=t;
	fore(y,0,n)if(valid(x,y)){
		ll t2=t;
		if(cuad(x)!=cuad(y))t2+=o.left(a[x],a[y])?1:-1;
		dfs(y,t2);
	}
}

bool can(ll _k, ll _dbg=0){
	k=_k; flag=0; dbg=_dbg;
	// if(dbg)cout<<"can "<<k<<"\n";
	fore(i,0,MAXN)tag[i]=INF;
	fore(i,0,n)if(tag[i]==INF)dfs(i,0);
	return flag;
}

int main(){
	cin>>n;
	if(n<3){cout<<"-1\n";return 0;}
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ll l=1,r=INF;
	while(l<=r){
		ll m=(__int128(l)+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	if(l>=INF)l=-1;
	// can(7,1);
	cout<<l<<"\n";
}