#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pt> a(n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		reverse(ALL(a));
		ll r=n-1;
		ll res=0;
		for(ll i=n-3;i>=0;i--){
			pt p=a[i],q=a[i+1];
			if(!a[i+2].left(p,q))r=i+1;
			while(r-i+1>2&&!(a[r].left(p,q)&&p.left(a[r-1],a[r])))r--;
			ll cur=r-i+1;
			res=max(res,cur);
			// cerr<<i<<": "<<r<<": "<<cur<<"\n";
		}
		if(res<3)res=0;
		cout<<res<<"\n";
	}
	return 0;
}