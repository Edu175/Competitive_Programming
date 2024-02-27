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
struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	ll norm2(){return x*x+y*y;}
};

const ll MAXN=1e5+5;
ll n;
pt a[MAXN];
bool b[MAXN];
const ll AC=1.5e6;
pt p;
void flip(ll i){
	if(b[i])p=p-a[i]-a[i];
	else p=p+a[i]+a[i];
	b[i]^=1;
}
void simul(){
	ll sd; srand((ll)&sd);
	fore(i,0,n){ // 0-> -  1-> +
		b[i]=rand()%2;
		if(b[i])p=p+a[i];
		else p=p-a[i];
	}
	//double t=1e9;
	ll now=p.norm2();
	while(now>AC*AC){
		ll old=now;
		ll i=rand()%n;
		flip(i);
		now=p.norm2();
		if(!(now<old/*||exp((old-now)/t)>=(double)rand()/RAND_MAX*/))flip(i);
		//t*=0.999999;
	}
	//cout<<t<<"\n";
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	simul();
	fore(i,0,n){
		if(b[i])cout<<"1 ";
		else cout<<"-1 ";
	}
	cout<<"\n";
	return 0;
}
