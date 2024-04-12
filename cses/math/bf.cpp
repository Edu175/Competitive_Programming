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

int main(){FIN;
	ll n; cin>>n;
	vector<ll>num(n+1);
	fore(i,1,n+1){
		vector<ll>vis(n+5);
		fore(j,1,i)if(j!=i-j)vis[num[j]^num[i-j]]=1;
		fore(j,0,SZ(vis))if(!vis[j]){num[i]=j;break;}
	}
	ll mx=0;
	fore(i,1,n+1)cout<<i<<": "<<num[i]<<"\n",mx=max(mx,num[i]);
	cout<<mx<<"\n";
	fore(i,1,n+1)if(!num[i])cout<<i<<",";;cout<<"\n";
	/*ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		
	}*/
	return 0;
}
