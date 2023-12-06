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
		ll n,p,l,k; cin>>n>>p>>l>>k;
		ll q=(n+6)/7;
		ll d=q/2;
		ll res=0;
		ll cnt=d*(2*k+l)+(k+l)*(q%2);
		//cout<<q<<" "<<d<<" "<<cnt<<"\n";
		if(cnt>=p){
			res=(p+2*k+l-1)/(2*k+l);
		}
		else {
			p-=cnt;
			res=d+q%2+(p+l-1)/l;
		}
		cout<<n-res<<"\n";
	}
	return 0;
}
