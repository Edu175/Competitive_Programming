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
		ll n; cin>>n;
		if(n<3){
			if(n==1)cout<<"1\n";
			if(n==2)cout<<"1 2\n";
			continue;
		}
		vector<ll>res(n);
		res[0]=3; res[n-1]=2;
		res[n/2]=1;
		ll j=4;
		fore(i,0,n){
			if(res[i])continue;
			res[i]=j++;
		}
		imp(res);
	}
	return 0;
}
