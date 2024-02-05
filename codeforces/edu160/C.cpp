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

ll B=32;

int main(){FIN;
	ll q; cin>>q;
	vector<ll>a(B);
	while(q--){
		ll t,x; cin>>t>>x;
		if(t==1)a[x]++;
		else {
			vector<ll>b=a;
			ll flag=1;
			fore(i,0,B){
				if(x&(1ll<<i)){
					if(!b[i])flag=0;
					else b[i]--;
				}
				if(i+1<SZ(b))b[i+1]+=b[i]/2;
			}
			if(flag)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
