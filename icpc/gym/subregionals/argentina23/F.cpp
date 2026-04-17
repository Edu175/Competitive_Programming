#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
};
pt t;

ll dis(pt a, pt b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(pair<ll,pt> a, pair<ll,pt> b){
	return dis(a.snd,t)<dis(b.snd,t);
}

int main(){FIN;
	ll n; cin>>n;
	ll w,l; cin>>w>>l;
	cin>>t.x>>t.y;
	vector<pair<ll,pt>>a;
	fore(i,0,2){
		fore(j,0,n){
			ll x,y; cin>>x>>y;
			a.pb({i,pt(x,y)});
		}
	}
	sort(ALL(a),cmp);
	ll g=a[0].fst,res=0;
	fore(i,0,SZ(a)){
		if(a[i].fst!=g)break;
		res++;
	}
	if(g)cout<<"R ";
	else cout<<"A ";
	cout<<res<<"\n";
	return 0;
}
