#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		ll fg=count(ALL(s),'B')==0;
		while(q--){
			ll a; cin>>a;
			if(fg)cout<<a<<"\n";
			else {
				ll p=0,res=0;
				while(a){
					if(s[p]=='A')a--;
					else a/=2;
					res++;
					p=(p+1)%n;
				}
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}
