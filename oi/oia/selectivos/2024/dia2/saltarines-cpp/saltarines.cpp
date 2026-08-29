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
const ll INF=1e15;
ll n,k,C,tot;
vector<ll>a,is;
vector<vector<vector<ll>>>dp;
ll lim;

long long saltarines(int K, vector<int> &val, vector<int> &p) {
	k=K;
	n=SZ(val);
	ll sum=0;
	a.pb(0);
	fore(i,0,SZ(val)){
		sum+=val[i];
		a.pb(sum);
	}
	is.resize(n+5);
	ll res=0;
	for(auto i:p)is[i]=1,tot+=i,res-=a[i];
	C=SZ(p);
	lim=k+tot;
//	cout<<lim<<"\n";
//	imp(is);
	dp.resize(2,vector<vector<ll>>(C+5,vector<ll>(lim+5,-1)));
	for(ll i=n+1;i>=0;i--)fore(_c,0,C+5)fore(s,0,lim+5){
		auto &res=dp[i&1][_c][s];
		if(i==n+1){res=(_c==0&&s<=lim)?0:-INF;continue;}
		ll c=_c+is[i];
		if(c>=C+5)continue;
		res=dp[(i+1)&1][c][s];
		if(c&&s+i<=lim)res=max(res,a[i]+dp[(i+1)&1][c-1][s+i]);
	}
	res+=dp[0][0][0];
	return res;
}
