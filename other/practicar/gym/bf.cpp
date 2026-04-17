#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct pt {
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	__int128 norm2(){return *this**this;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	pt operator/(ll t){return pt(x/t,y/t);}
	__int128 operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (q-p)%(*this-p)>0;}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
};


int main(){FIN;
	pt s,t; cin>>s.x>>s.y>>t.x>>t.y;
	ll n; cin>>n;
	vector<pt> a(n),b(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y>>b[i].y,b[i].x=a[i].x;
	ll pot=1;
	fore(_,0,n)pot*=3;
	ld res=1e18;
	fore(_mk,0,pot){
		ll mk=_mk;
		vv ty(n);
		fore(i,0,n)ty[i]=mk%3,mk/=3;
		pt p=s;
		ll po=0,bad=0;
		ld len=0;
		fore(i,0,n){
			if(!ty[i]){
				po=max(po,i+1);
				while(po<n&&!ty[po])po++;
				pt q=po==n?t:ty[po]==1?a[po]:b[po];
				bad|=a[i].left(p,q);
				bad|=b[i].left(q,p);
			}
			else {
				pt np=ty[i]==1?a[i]:b[i];
				len+=sqrtl((p-np).norm2());
				p=np;
			}
		}
		len+=sqrtl((p-t).norm2());
		if(!bad)res=min(res,len);
	}
	cout<<fixed<<setprecision(10)<<res<<"\n";
}