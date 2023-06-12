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
	ll t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<ll>v;
		ll sz=SZ(s);
		//ll ac=0;
		for(auto i:s)v.pb(i-'0');
		for(ll i=SZ(v)-1;i<0,i--){
			ll sum=v[i]+v[i-1];
		if(max(maxsum.fst,sum)==sum)maxsum.fst=sum,maxsum.snd=i;
		//ll sum=v[sz-2]+v[sz-1];
		v[sz-1]=sum%10;
		if(sum/10)v[sz-2]=1;
		else v.erase(v.begin()+(sz-2));
		for(auto i:v)cout<<i;
		cout<<"\n";
	}
	 return 0;
}
