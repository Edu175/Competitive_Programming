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
		pair<ll,ll>maxsum;maxsum.fst=0;
		ll ac=0;
		for(auto i:s)v.pb(i-'0');
		ll sz=SZ(v);
		for(ll i=sz-1;i>0;i--){
			ll sum=v[i]+v[i-1];
			if(sum>=10){
				ac=1;
				//cout<<ac<<"\n";
				maxsum.fst=sum;
				maxsum.snd=i-1;
				break;
			}
		}
		if(ac==0){
			maxsum.fst=v[0]+v[1];
			maxsum.snd=0;
		}
		//cout<<ac<<" "<<maxsum.fst<<" "<<maxsum.snd<<"\n";
		v[maxsum.snd+1]=(maxsum.fst%10);
		if(maxsum.fst/10)v[maxsum.snd]=1;
		else v.erase(v.begin()+(maxsum.snd));
		for(auto i:v)cout<<i;
		cout<<"\n";
	}
	 return 0;
}
