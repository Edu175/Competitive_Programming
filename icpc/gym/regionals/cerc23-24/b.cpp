#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll sq(ll n){return n*n;}
ld dis(ii a, ii b){
	return sqrtl(sq(a.fst-b.fst)+sq(a.snd-b.snd));
}

int main(){JET
	ll n; cin>>n;
	string s; cin>>s;
	vector<ii>p(n),a,b;
	fore(i,0,n){
		cin>>p[i].fst>>p[i].snd;
		if(s[i]=='G')a.pb(p[i]);
		else b.pb(p[i]);
	}
	auto solve=[&](vector<ii>a){
		ld res=0;
		ll n=SZ(a);
		fore(i,0,n/2)res+=dis(a[i],a[i+n/2]);
		return res;
	};
	ld res=solve(a)+solve(b);
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
    return 0;
}