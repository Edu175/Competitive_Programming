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
	while(t--){
		ll n,l;cin>>n>>l;ll x[n];
		ll c=l;
		fore(i,0,n){
			cin>>x[n];
			fore(j,0,1ll<<l){
				ll d=l;
				fore(h,0,l)if(((1ll<<h)|(j&x[i]))==1ll<<h)d++;
				c=min(c,d);
			}
		}
		cout<<c;
	}
	 return 0;
}
