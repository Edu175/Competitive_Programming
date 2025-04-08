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

ll sq(ll n){return n*n;}
ll dis2(ii a, ii b){return sq(a.fst-b.fst)+sq(a.snd-b.snd);}
ld dis(ii a, ii b){return sqrt(dis2(a,b));}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	sort(ALL(a));
	ld res=dis(a[0],a.back());
	fore(i,0,n)if(i+k<=n)res=min(res,dis(a[i],a[i+k-1]));
	res=(res/2)*(res/2)*acos(-1);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
