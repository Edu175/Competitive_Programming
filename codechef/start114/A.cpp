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

ll rps(char a, char b){
	if(a==b)return 0;
	if(a=='S'&&b=='P')return 1;
	if(a=='P'&&b=='S')return 0;
	return a<b;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a; cin>>a;
		ll d=n/2+1;
		string as="PRS";
		string b;
		fore(i,0,n){
			fore(j,0,3){
				//cout<<i<<" "<<d<<" "<<j<<": "<<rps(as[j],a[i])<<"\n";
				if(d-rps(as[j],a[i])<=n-1-i){
					d-=rps(as[j],a[i]);
					b.pb(as[j]);
					break;
				}
			}
		}
		cout<<b<<"\n";
	}
	return 0;
}
