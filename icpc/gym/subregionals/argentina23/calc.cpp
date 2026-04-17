#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll dp[7][7];

ll f(ll s, ll i){
	if(s<0)return 0;
	ll &res=dp[s][i];
	if(res!=-1)return res;
	if(s==0)return res=1;
	return res=f(s,i+1)+f(s-i,i);
}

int main(){FIN;
	mset(dp,-1);
	cout<<f(5,1);
	return 0;
}
