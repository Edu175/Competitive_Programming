#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v){cout<<messi<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator%(pt p){return x*p.y-p.x*y;}
	bool left(pt p, pt q){return ((q-p)%(*this-p)>0);}
	bool operator<(pt p){
		pair<ll,ll>a={x,y},b={p.x,p.y};
		return a<b;
	}
};
vector<pt> chull(vector<pt>a){
	vector<pt>r;
	sort(ALL(a));
	fore(i,0,SZ(a)){ //bottom hull
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],a[i]))
			r.pop_back();
		r.pb(a[i]);
	}
	r.pop_back(); ll k=SZ(r);
	for(ll i=SZ(a)-1;i>=0;i--){ //top hull
		while(SZ(r)>=k+2&&r.back().left(r[SZ(r)-2],a[i]))
			r.pop_back();
		r.pb(a[i]);
	}
	r.pop_back();
	return r;
}
int main(){FIN;
	ll n; cin>>n;
	vector<pt>a(n);
	//cout<<"scan\n";
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	//cout<<"chull\n";
	vector<pt>res=chull(a);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.x<<" "<<i.y<<"\n";
	return 0;
}

