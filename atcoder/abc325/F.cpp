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
const ll MAXN=105,MAXQ=1005;

ll n;
ll d[MAXN];
ll l[2],c[2],k[2];

ll dp[MAXN][MAXQ];
ll f(ll i, ll q){
	ll &res=dp[i][q];
	if(res!=-1)return res;
	if(i==n)return res=0;
	fore(qi,0,q+1){
		ll x=d[i]-qi*l[0];
		ll cu=max((ll)0,(x+l[1]-1)/l[1]);
		ll resi=cu+f(i+1,q-qi);
		if(res==-1)res=resi;
		res=min(res,resi);
	}
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>d[i];
	cin>>l[0]>>c[0]>>k[0];
	cin>>l[1]>>c[1]>>k[1];
	mset(dp,-1);
	ll res=-1;
	fore(i,0,k[0]+1){
		ll cu=f(0,i);
		if(cu<=k[1]){
			ll resi=i*c[0]+cu*c[1];
			if(res==-1)res=resi;
			res=min(res,resi);
		}
	}
	cout<<res<<"\n";
	return 0;
}
