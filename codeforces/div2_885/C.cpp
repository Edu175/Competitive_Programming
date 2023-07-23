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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ll> d;
		fore(i,0,n){
			if(!a[i]&&!b[i])continue;
			ll p=0;
			while(a[i]){
				//cout<<a[i]<<" "<<b[i]<<"\n";
				if(b[i]==0||b[i]>a[i]){
					ll c=abs(a[i]-b[i]);
					a[i]=b[i],b[i]=c;
					p++;
					//cout<<"+1\n";
					continue;
				}
				//cout<<"mod "<<a[i]<<" "<<b[i]<<"\n";
				ll pi=a[i]/b[i]; 
				ll bi=b[i];
				b[i]=a[i]%bi;
				if(pi%2==0)a[i]=b[i]+bi;
				else a[i]=bi;
				pi+=(pi+1)/2-1;
				p+=pi;
				//cout<<"+"<<pi<<"\n";
			}
			d.pb(p);
			//cout<<i<<": "<<p<<"\n\n";
		}
		//imp(d);
		/*ll r=-1;
		fore(i,0,n)if(!fl[i]&&r==-1)r=d[i];*/
		ll flag=1;
		fore(i,1,SZ(d))if(d[i]%3!=d[i-1]%3)flag=0;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
