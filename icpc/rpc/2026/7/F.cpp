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

vector<string> pingo={"pickup","dropoff"};

ll get(string s){return find(ALL(pingo),s)-pingo.begin();}

int main(){FIN;
	ll n; cin>>n;
	map<string,vector<ll>> mp;
	fore(i,0,n){
		string pi,me; cin>>pi>>me;
		mp[me].pb(get(pi));
	}
	ll good=1;
	for(auto [asd,v]:mp){
		good&=v==vv({0,1});
	}
	if(good)cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}
