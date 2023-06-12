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
		fore(i,0,n)cin>>x[i];
		vector<ll>v;
		fore(i,0,l){
			ll o=0;
			fore(j,0,n){
				if(((1ll<<i)&x[j])==1ll<<i)o++;
				else o--;
			}
			if(o<=0)o=0; else o=1;
			v.pb(o);
		}
		ll res=0;
		fore(i,0,l)res+=v[i]*(1ll<<i);
		cout<<res<<"\n";
		/*reverse(ALL(v));
		for(auto i:v)cout<<i;
		cout<<"\n";*/
	}
	 return 0;
}
