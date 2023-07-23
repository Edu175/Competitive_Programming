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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1505,MOD=1e9+7;

ll add(ll a, ll b){
	ll sum=a+b;
	return (sum>=MOD?sum-MOD:sum);
}
ll dp[2][MAXN][MAXN];

int main(){FIN;
	ll n,k; cin>>n>>k;
	bool a[n];
	vector<ll>p;
	fore(i,0,n){
		cin>>a[i];
		if(a[i])p.pb(i);
	}
	//imp(p);
	auto now=dp[0],prox=dp[1];
	fore(i,0,k+1)if(i%2==k%2)now[i][SZ(p)]=1;
	for(ll i=n-1;i>=0;i--){
		swap(now,prox);
		fore(s,0,k+1)fore(c,0,SZ(p)+1){
			//cout<<"\n";
			ll &res=now[s][c];
			res=prox[s][c];
			//cout<<i<<" "<<s<<" "<<c<<": "<<res<<"\n";
			if(c>=SZ(p))continue;
			ll si=abs(p[c]-i)+s;
			if(si<=k)res=add(res,prox[si][c+1]);
			//cout<<"("<<si<<","<<c+1<<") +"<<prox[si][c+1]<<" "<<res<<"\n";
		}
	}
	cout<<now[0][0]<<"\n";
	return 0;
}
