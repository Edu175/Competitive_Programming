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
		ll n; cin>>n;
		string s[3];
		fore(h,0,3)cin>>s[h];
		ll flag=0;
		fore(i,0,n){
			if(s[0][i]!=s[2][i]&&s[1][i]!=s[2][i])flag=1;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
