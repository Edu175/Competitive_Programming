#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define bint __int128

const bint MOD=212345678987654321LL;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vi a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	map<ll,ll>mp;
	fore(mk,1,1ll<<n){
		bint p=1;
		fore(i,0,n)if((1ll<<i)&mk)p=p*a[i]%MOD;
		mp[p]=mk;
	}
	ii res={-1,-1};
	fore(mk,1,1ll<<m){
		bint p=1;
		fore(i,0,m)if((1ll<<i)&mk)p=p*b[i]%MOD;
		if(mp.count(p))res={mp[p],mk};
	}
	if(res.fst==-1)cout<<"N\n";
	else {
		cout<<"Y\n";
		vector<ll>sa,sb;
		fore(i,0,n)if((1ll<<i)&res.fst)sa.pb(a[i]);
		fore(i,0,m)if((1ll<<i)&res.snd)sb.pb(b[i]);
		cout<<SZ(sa)<<" "<<SZ(sb)<<"\n";
		imp(sa);
		imp(sb);
	}
	return 0;
}
