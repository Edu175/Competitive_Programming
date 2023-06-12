#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a; cin>>a;
		string b; cin>>b;
		ll un=0;
		ll tw=0;
		ll flag=1;
		fore(i,0,n){
			if(a[i]=='1')un++;
			if(i)if(b[i]==b[i-1])tw++;
		}
		if(un&&tw)cout<<"YES\n";
		else if(a==b)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
