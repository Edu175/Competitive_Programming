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
const ll MOD=1e9+7;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		for(ll i=n-1;i>=0;i--){
			ll ans=0;
			fore(mk,0,1ll<<(n-i-1)){
				vector<ll>s={a[i]};
				fore(j,0,n-i-1)if((1ll<<j)&mk)s.pb(a[i+1+j]);
				cout<<s<<" = ";
				if(SZ(s)==1){
					cout<<s[0]<<"\n";
					ans+=s[0];
					continue;
				}
				ll sum=s[0];
				ll mn=s[1];
				fore(i,1,SZ(s))mn=min(mn,s[i]),sum+=s[i];
				if(SZ(s)==2)mn=min(mn,s[0]);
				cout<<sum-mn<<"\n";
				ans+=sum-mn;
			}
			cout<<ans<<"\n\n";
			res+=ans;
		}
		cout<<res<<"\n";
	}
	return 0;
}
