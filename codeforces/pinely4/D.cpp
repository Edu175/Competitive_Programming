#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<ll>>ans={
	
	{1},
	{1,2},
	{1,2,2},
	{1,2,2,3},
	{1,2,2,3,3},
	{1,2,2,3,3,4}
};


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n<6){
			ll mx=0;
			auto res=ans[n-1];
			for(auto i:res)mx=max(mx,i);
			cout<<mx<<"\n";
			imp(res);
			continue;
		}
		cout<<"4\n";
		vector<ll>res(n+1);
		fore(i,1,n+1)if(!res[i]){
			res[i]=2*(i&1)+1;
			if((i^2)<=n)res[i^2]=res[i]+1;
		}
		fore(i,1,n+1)cout<<res[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
