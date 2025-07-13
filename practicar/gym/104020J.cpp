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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

bool ask(ll x, ll y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	string ret; cin>>ret;
	return ret=="building";
}

int main(){FIN;
	ll w,h; cin>>w>>h;
	vv per(w); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	ll x=0,y=-1;
	for(auto i:per)if(y<h-1){
		if(!ask(i,y+1))continue;
		ll l=y+1,r=h;
		while(r-l>1){
			ll m=(l+r)/2;
			if(ask(i,m))l=m;
			else r=m;
		}
		x=i,y=l;
	}
	cout<<"! "<<x+1<<" "<<y+1<<"\n";
	return 0;
}