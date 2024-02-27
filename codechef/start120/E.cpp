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
typedef __int128 bint;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		bint res=0;
		fore(i,0,n+1){
			//cout<<i<<": "<<(ll)res<<"\n";
			res+=bint(sp[i])*bint(min(i,k-1)-min(n-i,k-1));
		}
		//cout<<(ll)res<<"\n";
		vector<ii>s;
		fore(i,0,n-k+1)s.pb({sp[i+k]-sp[i],i});
		sort(ALL(s)); reverse(ALL(s));
		set<ll>st={-1,n-k+1};
		for(auto [sum,i]:s){
			auto lwb=st.lower_bound(i);
			ll r=*lwb,l=*(--lwb);
			bint resi=bint(i-l)*bint(r-i)*bint(sum);
			res+=resi;
			st.insert(i);
		}
		ll ans=res%MOD;
		cout<<ans<<"\n";
	}
	return 0;
}
