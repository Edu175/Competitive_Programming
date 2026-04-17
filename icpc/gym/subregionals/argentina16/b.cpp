#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

ll sq(ll x){return x*x;}

int main(){JET
    ll n,s,e; cin>>n>>s>>e; s--,e--;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	auto dis=[&](ll i, ll j){
		auto x=a[i],y=a[j];
		return sqrt(sq(x.fst-y.fst)+sq(x.snd-y.snd));
	};
	ld sum=0;
	fore(i,0,n){
		sum+=dis(i,(i+1)%n);
	}
	vector<ld>sa={},ea;
	ll i=(s-1+n)%n,j=(e-1+n)%n;
	ld res=sum-dis(i,s)-dis(j,e)+dis(i,j);
	
	i=(s+1+n)%n,j=(e+1+n)%n;
	res=min(res,sum-dis(i,s)-dis(j,e)+dis(i,j));
	cout<<fixed<<setprecision(6);
	cout<<res<<"\n";
    return 0;
}