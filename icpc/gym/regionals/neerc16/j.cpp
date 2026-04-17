#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=1e-10;

struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
};
typedef pair<pt,ld> cm;

// cm oper(cm a, cm b){
// 	auto nm=a.snd+b.snd;
// 	a.fst=(a.fst*a.snd+b.fst*b.snd)/nm;
// 	a.snd=nm;
// 	return a;
// }
const ll MAXN=1e4+5;
int main(){
    JET
    #ifdef ONLINE_JUDGE
    freopen("jenga.in","r",stdin);     freopen("jenga.out","w",stdout);
    #endif
	ll n,w,h,m; cin>>n>>w>>h>>m;
	ll largo=n*w;
	vv ls(h,0),rs(h,n),qs(h,n);
	vector<pt>cs(h,pt(largo,largo)/2);
	vector<bitset<MAXN>>out(h);
	auto recalc=[&](ll i){
		ll q=0; ld sum=0;
		ls[i]=rs[i]=-1;
		fore(j,0,n)if(!out[i][j]){
			ld xc=w*j+w/2;
			sum+=xc; q++;
			if(ls[i]==-1)ls[i]=j;
			rs[i]=j+1;
		}
		pt p(sum/q,largo/2);
		if(i&1){
			p=pt(-p.y,p.x); // rot90 antihorario
			p.x+=largo;
		}
		cs[i]=p;
		qs[i]=q;
	};
	
	auto good=[&](pt p, ll i)->bool{
		if(!qs[i])return 0;
		if(i&1){
			// rotar horario
			p=pt(p.y,-p.x);
			p.y+=largo;
		}
		if(ls[i]*w+EPS<p.x&&p.x+EPS<rs[i]*w)return 1;
		return 0;
	};
	fore(_,0,m){
		ll x,y; cin>>x>>y; x--,y--;
		out[x][y]=1;
		recalc(x);
		pt arr(0,0);
		ll q=0;
		// fore(i,x+1,h)arr=arr+cs[i]*qs[i],q+=qs[i];
		for(ll i=h-1;i>=0;i--){
			if(q&&!good(arr/q,i)){ // esto va a dar false si i>x
				cout<<"yes\n"<<_+1<<"\n";
				exit(0);
			}
			arr=arr+cs[i]*qs[i],q+=qs[i];
		}
	}
	cout<<"no\n";
    return 0;
}