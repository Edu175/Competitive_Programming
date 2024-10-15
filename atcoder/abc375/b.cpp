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
ld dis(ii a, ii b){
	// cout<<"dis "<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<"\n";
	return sqrtl(sq(a.fst-b.fst)+sq(a.snd-b.snd));
}

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n+1,{0,0});
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd;
	ld res=0;
	fore(i,0,n+1)res+=dis(a[i],a[(i+1)%(n+1)]);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
