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

ll dp[45][45];

ll f(ll s, ll i){
	ll &res=dp[s][i];
	if(res!=-1)return res;
	if(s+i==41)return res=1;
	if(s+i>41)return res=0;
	return res=f(s,i+1)+f(s+i,i);
}

int main(){FIN;
	mset(dp,-1);
	cout<<f(0,1)<<"\n";
	/*ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		
	}*/
	return 0;
}
