#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
const ll PRES=55;
const ld EPS=1e-7;

struct pt{
	ld x,y;
	pt(){}
	pt(ld x, ld y):x(x),y(y){}
	ld norm2(){return x*x+y*y;}
	ld norm(){
		//cout<<" norm "<<x<<","<<y<<": "<<sqrtl(norm2())<<"\n";
		return sqrtl(norm2());
	}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator/(ld d){return pt(x/d,y/d);}
	pt operator*(ld d){return pt(x*d,y*d);}
	pt rot90(){return pt(-y,x);}
};
/*struct ln{
	pt p,q;
	ln(pt a, pt b):p(a),q(b-a){}
	ln(){}
	
};*/
ll n,k;
const ll MAXN=705;
pt a[MAXN];

bool can(ld d, pt p){
	ll c=0;
	//cout<<"can "<<d<<" "<<p.x<<" "<<p.y<<":\n";
	fore(i,0,n){
		c+=(a[i]-p).norm()<=d+EPS;
		if(c>=k)return 1;
	}
	//,cout<<a[i].x<<","<<a[i].y<<": "<<(a[i]-p).x<<","<<(a[i]-p).y<<" "<<(a[i]-p).norm()<<"<="<<d+EPS<<"\n";
	//cout<<c<<">="<<k<<"\n\n";
	return 0;
}
int main(){FIN;
	ll s,t; srand(175); cin>>k>>n>>s>>t;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	random_shuffle(a,a+n);
	cout<<fixed<<setprecision(15);
	if(k==1){
		cout<<0.0<<"\n";
		return 0;
	}
	/*if(k==2){
		ld res=1e9+5;
		fore(i,0,n)fore(j,i+1,n)res=min(res,(a[i]-a[j]).norm()/2.0);
		cout<<res<<"\n";
		return 0;
	}*/
	vector<ii>pares;
	fore(i,0,n)fore(j,0,n)if(i!=j)pares.pb({i,j});
	random_shuffle(ALL(pares));
	ld res=(2e9+5);
	for(auto [i,j]:pares){
		pt mid=(a[i]+a[j])/2.0;
		pt q=a[j]-mid;
		q=q.rot90();
		q=q/q.norm();
		pt p=mid+q*res;
		ld d=(a[j]-p).norm();
		if(!can(d,p))continue;
		ld l=0,r=2e9+5;
		ll it=PRES;
		while(it--){
			//cout<<l<<","<<r<<": "<<r-l<<endl;
			ld m=(l+r)/2.0;
			pt p=mid+q*m;
			if(can((a[j]-p).norm(),p))r=m;
			else l=m;
		}
		p=mid+q*r;
		d=(a[j]-p).norm();
		if(can(d,p))res=min(res,d);
	}
	cout<<res*t<<"\n";
	return 0;
}
