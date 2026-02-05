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
		string s,t; cin>>s>>t;
		vv os(26),ot(26);
		for(auto i:s)os[i-'a']++;
		for(auto i:t)ot[i-'a']++;
		ll fg=1;
		fore(i,0,26)fg&=os[i]<=ot[i];
		if(!fg){
			cout<<"Impossible\n";
			continue;
		}
		string ans;
		ll po=0;
		fore(_,0,SZ(t)){
			ll did=0;
			fore(c,0,26)if(ot[c]){
				ot[c]--;
				if(po<SZ(s)&&s[po]=='a'+c)os[c]--,po++;
				if(ot[c]<os[c]){ot[c]++;continue;}
				ans.pb('a'+c);
				did=1;
				break;
			}
			assert(did);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
