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
		vector<ll>v(n);
		fore(i,0,n){
			cin>>v[i];
			v[i]=abs(v[i]);
		}
		ll x=0;
		fore(i,1,101){
			if(count(ALL(v),i)<=2)x+=count(ALL(v),i);else x+=2;
		}
		if(count(ALL(v),0))x+=1;
		cout<<x<<"\n";
	}
	 return 0;
}
