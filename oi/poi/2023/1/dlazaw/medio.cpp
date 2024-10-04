#include "skolib.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szokput=b;i<szokput;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e4;

ll n;
ll cv(ii a){return n*a.fst+a.snd;}
ii cv(ll a){return {a/n,a%n};}
ll getN(){return daj_n();}
ll dis(ll x, ll y){return pytanie(x+1,y+1);}
ll dis(ll a){auto [x,y]=cv(a); return dis(x,y);}
void answer(ll x, ll y){odpowiedz(x+1,y+1);}
void answer(ll a){auto [x,y]=cv(a); answer(x,y);}
short di[MAXN][MAXN];
bool valid(ii a){
	auto [i,j]=a;
	return 0<=i&&i<n&&0<=j&&j<n;
}
vector<ll> g(ll _x){
	ii x=cv(_x);
	vector<ll>ret;
	fore(i,0,2)fore(j,0,2)fore(k,1,3){
		ll i2=2*i-1,j2=2*j-1,k2=k^3;
		ii x2={x.fst+i2*k,x.snd+j2*k2};
		if(valid(x2))ret.pb(cv(x2));
	}
	// cout<<"g "<<_x<<": "; imp(ret);
	return ret;
}

void bfs(ll x){
	// auto &D=di[x];
	// D=vector<short>(N,-1);
	auto D=di[x];
	D[x]=0;
	queue<ll>q;
	q.push(x);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g(x))if(D[y]==-1){
			D[y]=D[x]+1;
			q.push(y);
		}
	}
}
short d(ll x, ll y){
	// if(SZ(di[x]))return di[x][y];
	// if(SZ(di[x]))return di[x][y];
	if(di[x][y]!=-1)return di[x][y];
	if(di[y][x]!=-1)return di[y][x];
	
	bfs(x);
	return di[x][y];
}
// random_device rd;
mt19937 rng(175);

ll N;
int main() {
    n = getN();
	N=n*n;
	mset(di,-1);
	vector<ll>h(N);
	iota(ALL(h),0);
	short D=68;
	// fore(i,0,N)D=max(D,d(0,i));
	// D+=100;
	// fore(i,0,N)fore(j,0,N)D=max(D,d(i,j));
	// cout<<"D "<<D<<"\n"; // 67
	// D++;
	// ll iter=0;
	while(SZ(h)>1){
		ll val=N+5,best=0;
		if(SZ(h)==N){
			best=N/2;
		}
		/*else if(n>100&&iter<5){
			best=rng()%N;
		}*/
		else {
			fore(c,0,N){
				vector<ll>oc(D);
				ll resi=0;
				for(auto i:h)resi=max(resi,++oc[d(i,c)]);
				if(resi<val)best=c,val=resi;
			}
		}
		// imp(h);
		// cout<<best<<endl;
		// exit(0);
		ll nd=dis(best);
		vector<ll>hi;
		for(auto i:h)if(d(best,i)==nd)hi.pb(i);
		swap(h,hi);
		// iter++;
	}
	// cerr<<iter<<" operations\n";
	answer(h[0]);
}