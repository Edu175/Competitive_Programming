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
const ll MAXN=105,MOD=1e9+7;

ll dp[MAXN][MAXN][MAXN*10];

int main(){FIN;
	cin>>n;
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i],b[i]=SZ(to_string(a[i]));
	ll pot=1,res=0;
	fore(id,0,11){
		vector<ll>c,sum=0;
		fore(i,0,n){
			if(b[i])
		}
		fore(d,0,10*n){
			mset(dp,0);
			res=(res+f(i,0,d)*pot%MOD*a[i])%MOD;
			pot=pot*10%MOD;
		}
		
	}
	cout<<res<<"\n";
	return 0;
}
