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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		ll res=0;
		fore(i,0,n)res+=(s[i]=='A');
		ll q=0,mn=n;
		fore(i,0,n){
			if(s[i]=='A')q++;
			else mn=min(mn,q),q=0;
		}
		mn=min(mn,q);
		cout<<res-mn<<"\n";
	}
	return 0;
}
