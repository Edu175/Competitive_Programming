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
		ll res=0;
		fore(i,0,3){
			string s; cin>>s;
			vector<ll>c(3);
			for(auto i:s)if(i!='?')c[i-'A']++;
			fore(i,0,3)if(!c[i])res=i;
		}
		cout<<char('A'+res)<<"\n";
	}
	return 0;
}
