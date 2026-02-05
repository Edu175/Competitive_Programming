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

ll rnd(ll lg){
	ll pot=1ll<<lg;
	ll x=rng()%(pot-1)+1;
	ll k=__lg(x);
	// cerr<<x<<","<<k<<" ";
	k=lg-1-k;
	return k/1.3;
}

int main(){FIN;
	cout<<"1\n";
	ll V; cin>>V;
	vv a;
	fore(i,0,9)a.pb(rnd(V));
	// cerr<<"\n";
	imp(a)
	return 0;
}
