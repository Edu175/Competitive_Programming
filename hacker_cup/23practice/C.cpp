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
	fore(_,1,t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		vector<ll>a(2*n-1),s;
		map<ll,ll>mp;
		fore(i,0,SZ(a))cin>>a[i],mp[a[i]]++;
		sort(ALL(a));
		if(SZ(mp)==1){
			cout<<mp.begin()->fst<<"\n";
			continue;
		}
		s={a[0]+a[SZ(a)-1],a[0]+a[SZ(a)-2],a[1]+a[SZ(a)-1]};
		vector<ll>res;
		//imp(s);
		for(auto sum:s){
			ll x=-1,flag=1;
			for(auto i:mp){
				ll c=i.snd,q=mp[sum-i.fst];
				if(c<=q)continue;
				if(c==q+1){
					if(x!=-1)flag=0;
					else {
						x=sum-i.fst;
					}
				}
				else flag=0;
			}
			if(flag&&x>0)res.pb(x);
		}
		sort(ALL(res));
		if(SZ(res))cout<<res[0]<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
