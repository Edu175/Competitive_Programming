#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

ll fst1(ll x){
	return (ll(log2(x)));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b;
		ll x=(a|b)^((1ll<<n)-1);
		ll xori=a^b;
		ll flag=1;
		ll dif=abs(a-b)/2;
		while(fst1(dif)==fst1(xori)){
			if(dif==0){
				flag=0;
				break;
			}
			x+=1ll<<fst1(dif);
			dif-=1ll<<fst1(dif);
			xori-=1ll<<fst1(dif);
		}
		if(flag&&dif){
			ll big;
			fore(i,fst1(dif)+1,fst1(xori)+1){
				if(xori&(1ll<<i)){
					big=1ll<<i;
					break;
				}
			}
			ll fstp1=(1ll<<(fst1(dif)+1));
			if(big-dif>=dif-(xori&(fstp1-1)))x+=big;
			else x+=(xori&(fstp1-1));
		}
		cout<<x<<"\n";
	}
	return 0;
}
