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
const ld INF=1e18;
const ld EPS=1e-12;

enum {SWAP,CH,QUERY};
struct event{
	ld t;
	ll ty,wh;
	bool operator<(const event &rhs) const {return t<rhs.t;}
};
int main(){FIN;
	ll n,C,L; cin>>n>>C>>L;
	vector<ii> a(n+2);
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd;
	a[0]={0,0};
	a[n+1]={L,0};
	n=SZ(a);
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){return a[i].fst<a[j].fst;});
	set<array<ll,3>> ev;
	ld t=0;
	ll cant=0;
	auto eval=[&](ll i, ll t){return a[i].fst+a[i].snd*t;};
	auto agr=[&](ll i, ll j){ // j is on top of i
		ll p=INF;
		ld c=eval(j,t)-eval(i,t);
		assert(c>=-EPS);
		ll m=a[j].snd-a[i].snd;
		if(m){
			p=c/ld(-m)+t;
			if(p<-EPS)p=INF;
		}
		
	};
	ll q; cin>>q;
	fore(i,0,q){
		ll t; cin>>t;
		ev.insert({t,QUERY,i});
	}
	for(ll done=0;done<q;){
		auto [_t,ty,wh]=*ev.begin();
		t=_t;
		if(ty==QUERY){
			
		}
	}
	return 0;
}