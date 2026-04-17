#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=15;
const ld INF=1e9*15,EPS=1e-5,DINF=1e15;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
};
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){
	//	assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};

vector<pt>a[MAXN];

ld mem[MAXN][MAXN];
ld h;
ld cost(ll i, ll j){
	auto &res=mem[i][j];
	if(res>-0.5)return res;
	auto pingo=[&](vector<pt>a, vector<pt>b){
		// cout<<"pingo {";
		// for(auto i:a)cout<<i.x<<","<<i.y<<" ";
		// cout<<"} {";
		// for(auto i:b)cout<<i.x<<","<<i.y<<" ";
		// cout<<"}"<<endl;
		ll j=0,n=SZ(a),m=SZ(b);
		ld res=0;
		fore(i,0,m){ // b points
			ll x=b[i].x,y=b[i].y;
			while(a[j].y<y)j++;
			pt p;
			if(a[j].y==y)p=a[j];
			else p=ln(pt(0,y),pt(1,y))^ln(a[j-1],a[j]);
			res=max(res,p.x-x);
		}
		j=0;
		fore(i,0,n){// a points
			ll x=a[i].x,y=a[i].y;
			while(b[j].y<y)j++;
			pt p;
			if(b[j].y==y)p=b[j];
			else p=ln(pt(0,y),pt(1,y))^ln(b[j-1],b[j]);
			res=max(res,x-p.x);
		}
		return res;
	};
	vector<pt>l,r;
	fore(j,0,SZ(a[i])){
		l.pb(a[i][j]);
		if(l.back().y==h)break;
	}
	ll did=0;
	fore(k,0,SZ(a[j])){
		if(did)r.pb(a[j][k]);
		did|=a[j][k].y==h;
	}
	r.pb(a[j][0]);
	reverse(ALL(r));
	return res=pingo(l,r);
}
ld mem2[MAXN],mem3[MAXN];
ld costl(ll i){
	auto &res=mem2[i];
	if(res>-0.5)return res;
	res=0;
	for(auto p:a[i])res=min(res,p.x);
	res=-res;
	// cout<<"costl "<<i<<": "<<res<<"\n";
	return res;
}
ld costr(ll i){
	auto &res=mem3[i];
	if(res>-0.5)return res;
	res=0;
	for(auto p:a[i])res=max(res,p.x);
	// cout<<"costr "<<i<<": "<<res<<"\n";
	return res;
}
int main(){ET;
	ll n; cin>>n;
	fore(i,0,n){
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j].x>>a[i][j].y,h=max(h,a[i][j].y);
		// reverse(ALL(a[i]));
	}
	fore(i,0,n){
		mem2[i]=mem3[i]=-1;
		fore(j,0,n)mem[i][j]=-1;
	}
	vector<vector<ld>> dp(1ll<<n,vector<ld>(n));
	fore(x,0,n)dp[(1<<n)-1][x]=costr(x);
	for(ll mk=(1<<n)-2;mk>=0;mk--)fore(x,0,n)if(mk>>x&1){
		auto &res=dp[mk][x];
		res=INF;
		fore(y,0,n)if(!(mk>>y&1)){
			res=min(res,dp[mk|(1ll<<y)][y]+cost(x,y));
		}
		// cout<<mk<<" "<<x<<": "<<res<<" dp\n";
	}
	ld res=INF;
	fore(i,0,n)res=min(res,costl(i)+dp[(1<<i)][i]);
	// cout<<"INF "<<INF<<"\n";
	cout<<fixed<<setprecision(3)<<res<<"\n";
}

/*

costr 0: 1
costr 1: 2
costr 2: 3
cost 1,0: 3
6 1: 4 dp
cost 2,0: 3
6 2: 4 dp
cost 0,1: 1
5 0: 3 dp
cost 2,1: 3
5 2: 5 dp
4 2: 6 dp
cost 0,2: 1
3 0: 4 dp
cost 1,2: 1
3 1: 4 dp
2 1: 5 dp
1 0: 5 dp
costl 0: 1
costl 1: -0
costl 2: -0
INF 1.5e+10




*/