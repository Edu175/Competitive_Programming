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
		ll n,k; cin>>n>>k;
		map<char,ll>mp;
		string s; cin>>s;
		for(auto i:s)mp[i]++;
		ll res=0;
		for(auto i:mp)if(i.snd&1)res++;
		if((n-k)&1)res--;
		//cout<<res<<": ";
		if(k>=res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
