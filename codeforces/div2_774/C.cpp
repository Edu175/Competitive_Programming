#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	vector<ll>fact={1};
	fore(i,2,15)fact.pb(i*fact[i-2]);
	for(auto i:fact)cout<<i<<" ";
	cout<<"\n";
	vector<ll>pot2={2};
	fore(i,1,39){
		pot2.pb(2*pot2[i-1]);
	}
	for(auto i:pot2)cout<<i<<" ";
	cout<<"\n";
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n;
	}
	 return 0;
}
