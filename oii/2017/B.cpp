#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	bool operator>>(pt p){ // >= in both coords
		return x>=p.x&&y>=p.y;
	}
	bool operator<<(pt p){return p<<(*this);}
}
struct zon{
	pt s,e;
	zon(pt s, pt e):s(s),e(e){}
	zon(){}
	bool in(zon a){ // this in a ?
		return (a.s<<s)&&(e<<a.e);
	}
	bool is_in(pt p){ // is point p in this?
		return (s<<p)&&(p<<e);
	}
	ll operator%(zon a){ // 0 if disjoint, 1 if partial, 2 if complete
		if(in(a)||a.in(*this))return 2;
		
	}
	
}

int main(){FIN;
	ll n[3],X,Y; cin>>n[0]>>n[1]>>n[2]>>X>>Y; // { F , P , H }
	vector<ll>a[3];
	fore(i,0,3){
		a[i].resize(n[i]);
		fore(j,0,n[i])cin>>a[i][j];
	}
	return 0;
}
