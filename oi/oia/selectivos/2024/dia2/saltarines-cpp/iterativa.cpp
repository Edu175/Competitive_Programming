#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e15,MAXN=305,MAXK=2005;
ll dp[2][MAXN][MAXK];
long long saltarines(int K, vector<int> &val, vector<int> &p) {
	ll k=K;
	ll n=SZ(val);
	ll sum=0;
	vector<ll>a={0};
	fore(i,0,SZ(val)){
		sum+=val[i];
		a.pb(sum);
	}
	//vector<ll>is(n+5);
	//for(auto i:p)is[i]=1,tot+=i,res-=a[i];
//	vector<ll>sp(n+5);
//	fore(i,0,n+5)sp[i]=(i?sp[i-1]:0)+(is[i]?i:0);
	sort(ALL(p));
	ll C=SZ(p);
//	dp.resize(n+5,vector<vector<ll>>(C+5,vector<ll>(k+5)));
	
	for(ll i=n+1;i>=0;i--)fore(c,0,C+1)fore(s,0,k+1){
		ll &res=dp[i&1][c][s];
		if(i==n+1){
			res=(c==C&&s<=k)?0:-INF;
			continue;
		}
		res=dp[(i&1)^1][c][s];
		if(c<C&&p[c]<=i&&s+i-p[c]<=k)
			res=max(res,a[i]-a[p[c]]+dp[(i&1)^1][c+1][s+i-p[c]]);
//		cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
	}
	ll res=dp[0][0][0];
	return res;
}
