#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		// if(n==1){
		// 	cout<<"-1\n";
		// 	continue;
		// }
		ll p=-1;
		fore(i,0,n-1)if(s[i]==s[i+1])p=i;
		if(p!=-1){
			cout<<s.substr(p,2)<<"\n";
			continue;
		}
		fore(i,0,n-2){
			if(s[i]!=s[i+2])p=i;
		}
		if(p!=-1){
			cout<<s.substr(p,3)<<"\n";
			continue;
		}
		cout<<"-1\n";
		
	}
	return 0;
}
