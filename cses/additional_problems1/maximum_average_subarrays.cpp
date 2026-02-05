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
#define impt(v) {for(auto i:v)cout<<i.x<<","<<i.y<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<pt> v;
	ll s=0;
	auto vacia=[&](pt p){
		while(SZ(v)>=2&&!v.back().left(v.end()[-2],p))v.pop_back();
	};
	vv ans(n);
	fore(i,0,n){
		ll x; cin>>x;
		pt p={i,s};
		// vacia(p);
		v.pb(p);
		s-=x;
		pt r={i+1,s};
		vacia(r);
		ans[i]=i+1-v.back().x;
	}
	imp(ans)
	return 0;
}
