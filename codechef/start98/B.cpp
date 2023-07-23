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
		char a[n];
		fore(i,0,n)cin>>a[i];
		ll k=(n%3+2)%3;
		if(k==0){
			cout<<"YES\n";
			continue;
		}
		vector<ll>oc(30);
		ll flag=0;
		fore(i,0,n){
			if(i%3==0)oc[a[i]-'a']++;
			if(i%3==k&&oc[a[i]-'a'])flag=1;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
