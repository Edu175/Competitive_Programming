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

ll c0,c1;
bool can(ll x, ll m){return c0<=x+m&&x+m<c1;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,k; cin>>a>>b>>c>>k;
		ll a1=1; fore(i,0,a)a1*=10; ll a0=a1/10; // [a0,a1)
		ll b0,b1=1; fore(i,0,b)b1*=10; b0=b1/10;
		c1=1; fore(i,0,c)c1*=10; c0=c1/10;
		//cout<<a0<<","<<a1<<" "<<b0<<","<<b1<<" "<<c0<<","<<c1<<"\n";
		ll A=-1,B=-1;
		fore(x,a0,a1){
			ll l=b0,r=b1-1;
			ll s,e; //[s,e)
			if(!can(x,l)){ //0001111
				while(l<=r){ 
					ll m=(l+r)/2;
					if(can(x,m))r=m-1;
					else l=m+1;
				}
				s=l,e=b1;
			}
			else {
				while(l<=r){ //1111000
					ll m=(l+r)/2;
					if(can(x,m))l=m+1;
					else r=m-1;
					s=b0,e=l;
				}
			}
			//cout<<x<<": "<<s<<","<<e<<"\n";
			if(k<=e-s){
				A=x;
				B=s+k-1;
				k=0;
				break;
			}
			else k-=(e-s);
		}
		if(k==0)cout<<A<<" + "<<B<<" = "<<A+B<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
