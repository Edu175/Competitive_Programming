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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ld sq(ld a){return a*a;}
ld dis(ii a, ii b){
	return sqrtl(sq(a.fst-b.fst)+sq(a.snd-b.snd));
}

int main(){FIN;
	ll n,k,m; cin>>n>>k>>m;
	vector<ii> pts(n);
	fore(i,0,n)cin>>pts[i].fst>>pts[i].snd;
	vector<array<ll,3>> ed;
	return 0;
}
