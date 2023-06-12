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
const ll MAXK=1e5+5;//😀️

ll dp[4][MAXK];
ll n; ll a[105];

ll f(ll p, ll k){
	ll &res=dp[p][k];
	if(res>=0)return res;
	if(!k)return res=0;
	res=1;
	fore(i,0,n){
		if(k-a[i]>=0)res=min(res,f(p^1,k-a[i]));
	}
	res^=1;
	return res;
}

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	if(f(0,k))cout<<"First\n";
	else cout<<"Second\n";
	return 0;
}
