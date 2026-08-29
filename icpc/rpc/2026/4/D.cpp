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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

ii a[MAXN];
ll sq(ll a){return a*a;}
ll dis2(ll i, ll j){
	return sq(a[i].fst-a[j].fst)+sq(a[i].snd-a[j].snd);
}
ld dis(ll i, ll j){return sqrtl(dis2(i,j));}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	deque<ll> ord;
	ll l=0,r=0;
	ord.pb(r);
	vv per(n-1); iota(ALL(per),1);
	sort(ALL(per),[&](ll i, ll j){return dis2(0,i)<dis2(0,j);});
	for(auto i:per){
		if(dis2(r,i)<dis2(l,i))ord.pb(i),r=i;
		else ord.push_front(i),l=i;
	}
	// for(auto i:ord)cerr<<i+1<<" ";;cerr<<"\n";
	ld res=0;
	fore(i,0,n-1){
		res+=dis(ord[i],ord[i+1]);
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
