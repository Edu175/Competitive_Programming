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
		ll n,k; cin>>n>>k;
		ll a[n];
		map<ll,ll>o;
		vector<ll>v;
		fore(i,0,n){
			cin>>a[i];
			o[a[i]]++;
			if(o[a[i]]==k)v.pb(a[i]);
		}
		//for(auto i:v)cout<<i<<" ";
		//cout<<"\n";
		sort(ALL(v));
		ll res=0;
		ll l=0;
		ll r=0;
		ll maxi=0;
		ll li=0;
		ll ri=0;
		bool flag=0;
		fore(i,0,SZ(v)){
			flag=1;
			if(i==0||v[i]-v[i-1]!=1){
				if(maxi>res)res=maxi,l=li,r=ri;
				maxi=1,li=v[i],ri=v[i];
			}
			else maxi++,ri=v[i];
			if(i==SZ(v)-1){
				if(maxi>res)res=maxi,l=li,r=ri;
			}
			//cout<<maxi<<" ";
		}
		//cout<<"\n";
		if(flag)cout<<l<<" "<<r<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}
