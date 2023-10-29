#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	vector<ii>b;
	fore(i,0,n)cin>>a[i],b.pb({a[i],i});
	vector<ll> cd(n+1);
	sort(ALL(b));
	ll c=0,res=0;
	for(auto [v,i]:b){
		c++;
		for(ll j=i+1;j<=n;j+=i+1)cd[j-1]++;
		ll resi=(v*(fpow(2,cd[i])-1+MOD))%MOD*fpow(2,c-cd[i])%MOD;
		cout<<v<<" "<<i<<": "; imp(cd);
		cout<<resi*fpow(v,MOD-2)%MOD<<"\n";
		res=(res+resi)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
