#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll ar = 0, de =  0;
		fore(i,0,n){
			char s;
			int x; cin>>s>>x;
			if(s=='N') ar +=x;
			else if(s=='S') ar -=x;
			else if(s=='E') de+=x;
			else de-=x;
		}
		vector<pair<char,ll>> rta;
		if(ar>=0){
			rta.pb({'N',-1});
			if(ar>0) rta.pb({'Z',ar});
			if(de>=0){
				rta.pb({'R',-1});
				if(de>0) rta.pb({'Z',de});
			}
			else{
				rta.pb({'L',-1});
				rta.pb({'Z',-de});
			}
		}
		else{
			rta.pb({'S',-1});
			rta.pb({'Z',-ar});
			if(de>=0){
				rta.pb({'L',-1});
				if(de>0) rta.pb({'Z',de});
			}
			else{
				rta.pb({'R',-1});
				rta.pb({'Z',-de});
			}
		}
		cout<<SZ(rta) -1<<"\n";
		for(auto[x,y]:rta){
			cout<<x<<" ";
			if(y>0) cout<<y<<" ";
			cout<<"\n";
		}	
	}
	return 0;
}