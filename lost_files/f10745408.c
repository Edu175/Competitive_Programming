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
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n;cin>>n;vector<ll>v(n);
		ll pos[n+1];
		ll res=0;
		fore(i,0,n)cin>>v[i],pos[v[i]]=i;
		
		vector<ll>ve;
		for(auto i:v)ve.pb(i);
		
		fore(i,1,n){
			for(ll j=pos[i];j>=0;j--)v[i-1+pos[i]-j]=ve[j],res++;
			/*if(i==4){
				cout<<"return";
				return 0;
			}*/
			vector<ll>ve(0);
			for(auto h:v)ve.pb(h);
		}
		cout<<res<<"\n";
	}
	return 0;
}
