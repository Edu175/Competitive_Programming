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
typedef float ld;
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
struct halfplane:public ln{
	ld angle;
	halfplane(){}
	halfplane(pt a, pt b){p=a; pq=b-a; angle=atan2(pq.y,pq.x);}
	bool operator<(halfplane b)const{return angle<b.angle;}
	bool out(pt q){return pq%(q-p)<-EPS;}
};

vector<pt> intersect(vector<halfplane> b){ // b sorted
	int n=SZ(b),q=1,h=0;
	vector<halfplane> c(SZ(b)+10);
	fore(i,0,n){
		while(q<h&&b[i].out(c[h]^c[h-1]))h--;
		while(q<h&&b[i].out(c[q]^c[q+1]))q++;
		c[++h]=b[i];
		if(q<h&&abs(c[h].pq%c[h-1].pq)<EPS){
			if(c[h].pq*c[h-1].pq<=0)return {};
			h--;
			if(b[i].out(c[h].p))c[h]=b[i];
		}
	}
	while(q<h-1&&c[q].out(c[h]^c[h-1]))h--;
	while(q<h-1&&c[h].out(c[q]^c[q+1]))q++;
	if(h-q<=1)return {};
	c[h+1]=c[q];
	vector<pt>s;
	fore(i,q,h+1)s.pb(c[i]^c[i+1]);
	return s;
}

vector<pt>a[MAXN];

ld mem[MAXN][MAXN];
ld cost(ll i, ll j){
	auto &res=mem[i][j];
	if(res>-0.5)return res;
	vector<pair<halfplane,bool>>b;
	auto add=[&](vector<pt>&a, bool fg){
		ll n=SZ(a);
		fore(i,0,n)b.pb({{a[i],a[(i+1)%n]},fg});
	};
	add(a[i],0);
	add(a[j],1);
	vector<pt> bx={{DINF,DINF},{-DINF,DINF},{-DINF,-DINF},{DINF,-DINF}};
	fore(i,0,4)b.pb({halfplane(bx[i],bx[(i+1)%4]),0});
	sort(ALL(b));
	auto choca=[&](ld d)->bool{
		vector<halfplane>h;
		for(auto [hp,fg]:b){
			if(fg)hp.p.x+=d;
			h.pb(hp);
		}
		return SZ(intersect(h));
	};
	ld l=0,r=3e8;
	// while(choca(r))r=r+r;
	ll it=50;
	while(it--){
		ld m=(l+r)/2;
		if(choca(m))l=m;
		else r=m;
	}
	res=l;
	// cout<<"cost "<<i<<","<<j<<": "<<res<<"\n";
	return res;
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
		fore(j,0,m)cin>>a[i][j].x>>a[i][j].y;
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