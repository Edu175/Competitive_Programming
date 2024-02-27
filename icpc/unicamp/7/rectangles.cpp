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

struct rect{
	ll i0,j0,i1,j1;
	rect(){}
	rect(ll a, ll b, ll c, ll d):i0(a),j0(b),i1(c),j1(d){}
	ll area(){
		if(i0<i1&&j0<j1)return (i1-i0)*(j1-j0);
		return 0;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		rect a,b;
		cin>>a.i0>>a.j0>>a.i1>>a.j1;
		cin>>b.i0>>b.j0>>b.i1>>b.j1;
		ll res=max(a.area(),b.area());
		rect in(max(a.i0,b.i0),max(a.j0,b.j0),min(a.i1,b.i1),min(a.j1,b.j1));
		/*if(in.area()==0){
			cout<<res<<"\n";
			continue;
		}*/
		if(max(a.i0,b.i0)<=min(a.i1,b.i1)){
		rect c(min(a.i0,b.i0),max(a.j0,b.j0),max(a.i1,b.i1),min(a.j1,b.j1));
			res=max(res,c.area());
		}
		if(max(a.j0,b.j0)<=min(a.j1,b.j1)){
		rect d(max(a.i0,b.i0),min(a.j0,b.j0),min(a.i1,b.i1),max(a.j1,b.j1));
			res=max(res,d.area());
		}
		cout<<res<<"\n";
	}
	return 0;
}
