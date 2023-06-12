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
	vector<ll>fact={6};
	fore(i,4,15)fact.pb(i*fact[i-4]);
	/*for(auto i:fact)cout<<i<<" ";
	cout<<"\n";*/
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=1000000000005;
		fore(i,0,1ll<<13){
			pair<ll,ll> m;
			m.fst=n;
			m.snd=0;
			fore(j,0,12){
				if(((1ll<<j)&i)==(1ll<<j))m.fst-=fact[j],m.snd++;
			}
			res=min(__builtin_popcountll(m.fst)+m.snd,res);
		}
		cout<<res<<"\n";
	}
	return 0;
}
