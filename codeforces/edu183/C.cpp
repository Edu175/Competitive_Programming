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
		ll n; cin>>n;
		string s; cin>>s;
		ll so=0;
		for(auto i:s)so+=(i=='a'?1:-1);
		map<ll,ll> mp;
		mp[0]=-1;
		ll dif=0;
		ll res=n+5;
		fore(i,0,SZ(s)){
			dif+=(s[i]=='a'?1:-1);
			if(mp.count(dif-so))res=min(res,i-mp[dif-so]);
			mp[dif]=i;
		}
		if(res==n)res=-1;
		if(so==0)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
