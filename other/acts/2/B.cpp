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
typedef long double ld;
typedef pair<ll,ll> ii;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (p-*this)%(q-*this)>0;}
};
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
bool cmp(pt a, pt b){
	return ii({a.x,a.y})<ii({b.x,b.y});
}
int main(){FIN;
	ll k; cin>>k;
	vector<pt>a;
	fore(i,0,k){
		ll n; cin>>n;
		fore(j,0,n+1){
			ll x,y; cin>>x>>y;
			x=abs(x);
			a.pb(pt(x,y));
		}
	}
	sort(ALL(a),cmp);
	vector<pt>b={a[0]};
	fore(i,1,SZ(a)){
		if(a[i].y<b.back().y){
			while(SZ(b)>=2&&!b.back().left(a[i],b.end()[-2]))b.pop_back();
			b.pb(a[i]);
		}
	}
	ld res=0;
	fore(i,0,SZ(b)-1){
		pt l=b[i],r=b[i+1];
		ld m=(l.y-r.y)/(l.x-r.x);
		ld c=l.y-m*l.x;
		ld resi=c*(-c/m);
		res=max(res,resi);
	}
	//cerr<<l<<"\n";
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
