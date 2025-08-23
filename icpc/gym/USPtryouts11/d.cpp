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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-8;
ll sq(ll n){return n*n;}
ll dis2(ii a, ii b){return sq(a.fst-b.fst)+sq(a.snd-b.snd);}
ld dis(ii a, ii b){return sqrtl(dis2(a,b));}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		pair<ll,ii> c1,c2;
		cin>>c1.fst>>c1.snd.fst>>c1.snd.snd;
		cin>>c2.fst>>c2.snd.fst>>c2.snd.snd;
		if(dis(c1.snd,c2.snd)+c2.fst<=c1.fst+EPS)cout<<"Rich\n";
		else cout<<"Dead\n";
	}
	return 0;
}
