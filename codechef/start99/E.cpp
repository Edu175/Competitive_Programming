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
		string s; cin>>s;
		ll a[n];
		fore(i,0,n)a[i]=s[i]-'0';
		ll flag=0;
		fore(i,1,n-1){
			if((a[i-1]^a[i+1])!=a[i])flag=1;
		}
		if(!flag)cout<<s<<"\n";
		else {
			string res;
			res.pb(s[0]);
			fore(i,0,n-2)res.pb('1');
			res.pb(s[n-1]);
			ll z=0;
			fore(i,0,n)if(!a[i])z=1;
			/*cout<<s<<"\n";
			imp(a);
			cout<<z<<"\n";*/
			if(z&&s[0]=='1'&&s[n-1]=='1'&&n>2)res[1]='0';
			cout<<res<<"\n";
			//cout<<"\n";
		}
	}
	return 0;
}
