#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n";
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		if(n&1){
			cout<<"-1\n";
			continue;
		}
		vector<ll>c(30);
		for(auto i:s)c[i-'a']++;
		//imp(c);
		ll flag=1;
		for(auto i:c)if(i>n/2)flag=0;
		if(!flag){
			cout<<"-1\n";
			continue;
		}
		vector<ll> q(30);
		fore(i,0,n/2)q[s[i]-'a']+=(s[i]==s[n-1-i]);
		ll mx=0,sm=0;
		for(auto i:q)mx=max(mx,i),sm+=i;
		ll res=0;
		if(mx>sm-mx)res=mx;
		else res=(sm+1)/2;
		cout<<res<<"\n";
	}
	return 0;
}
