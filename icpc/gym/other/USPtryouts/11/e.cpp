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
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// const ld EPS=1e-8;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
};

int main(){FIN;
	// ll t; cin>>t;
	// while(t--){
		ll n; cin>>n;
		vector<pt> a(n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		ld area=0;
		fore(i,0,n){
			area+=a[i]%a[(i+1)%n];
		}
		if(area<0)reverse(ALL(a));
		ll res=0;
		fore(i,0,n){
			ll j=(i+1)%n,k=(i+2)%n;
			res+=!a[k].left(a[i],a[j]);
		}
		cout<<res<<"\n";
	// }
	return 0;
}
