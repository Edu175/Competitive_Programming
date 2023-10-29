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
		ll l,r; cin>>l>>r;
		ll ra=-1,rb=-1;
		fore(n,l,r+1){
			if(ra!=-1)break;
			for(ll d=2;ra==-1&&d*d<=n;d++){
				if(n%d==0){
					ll a=d,b=n-d;
					if(a>0&&b>0&&gcd(a,b)!=1)ra=a,rb=b;
				}
			}
		}
		if(ra==-1)cout<<ra<<"\n";
		else cout<<ra<<" "<<rb<<"\n";
	}
	return 0;
}
