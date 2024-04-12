#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

ld fpow(ld b, ll e){
	ld ret=1;
	while(e){
		if(e&1)ret*=b;
		b*=b,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	ld sum=0,res=0;
	fore(i,1,k+1){
		ld resi=fpow(ld(i)/k,n)-sum;
		sum+=resi;
		res+=i*resi;
		//cout<<i<<": "<<resi<<" "<<i*resi<<"\n";
	}
	cout<<fixed<<setprecision(6)<<res<<"\n";
	return 0;
}
