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
		ll a[n];
		map<ll,ll>mp;
		fore(i,0,n)cin>>a[i], mp[a[i]]++;
		ll sad=0;
		ll maxi=0;
		ll last=0;
		for(auto i:mp){
			if(i.snd==1)sad++;
			maxi=max(maxi,i.snd);
			last=max(last,i.fst);
		}
		ll res=(sad+1)/2;
		if((maxi==2&&sad==1)&&mp[last]==1)res++;
		cout<</*last<<" "<<mp[last]<<" "<<*/res<<"\n";
	}
	return 0;
}
