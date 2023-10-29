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
		ll n; cin>>n;
		string s; cin>>s;
		ll mod=1000000007;
		ll res=0;
		fore(i,0,n){
			if(s[i]=='c')res++;
			if(s[i]=='g')res++;
			if(s[i]=='l')res++;
			if(s[i]=='r')res++;
		}
		ll fres=1;
		fore(i,0,res)fres=(2*fres)%mod;
		cout<<fres<<"\n";
	}
	return 0;
}
