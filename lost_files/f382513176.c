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
		ll z=0;
		fore(i,0,n){
			cin>>a[i];
			if(!a[i])z++;
		}
		ll maxi=0;
		ll mi=1;
		ll xorp[n];
		ll res=0;
		xorp[0]=a[0];
		map<ll,ll>mp;
		fore(i,0,n){
			if(a[i]!=a[(i-1+n)%n])maxi=max(maxi,mi),mi=1;
			else mi++;
			if(i)xorp[i]=xorp[i-1]^a[i];
			if(!mp[xorp[i]])res++,mp[xorp[i]]=1;
		}
		if(maxi>1){
			if(maxi==2)if(a[0]!=a[1]&&a[0]!=a[n-1])res++;
			if(maxi>2&&res>1){
				if(a[0]!=a[1]&&a[0]!=a[n-1])res+=2;
				else if(a[0]!=a[1]||a[0]!=a[n-1])res++;
			}
		}
		else if(z&&a[0])res++;
		//cout<<maxi<<"\n";
		pres;
	}
	return 0;
}
