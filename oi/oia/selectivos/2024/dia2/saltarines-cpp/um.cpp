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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll INF=1e15;
ll n,k,C,tot;
vector<ll>a,is;

vector<vector<unordered_map<int,ll>>>dp;
ll lim;
ll f(ll i, ll _c, ll s){
	//cout<<"call "<<i<<" "<<_c<<" "<<s<<"\n";
	if(dp[i][_c].count(s))return dp[i][_c][s];
	ll &res=dp[i][_c][s];
	if(i==n+1)return res=(_c==0&&s<=lim)?0:-INF;
	ll c=_c+is[i];
	res=f(i+1,c,s);
	if(c&&s+i<=lim)res=max(res,a[i]+f(i+1,c-1,s+i));
//	cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
	return res;
}
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
	//dp.resize(n+5,vector<vector<ll>>(C+5,vector<ll>(lim+5,-1)));
	dp.resize(n+5,vector<unordered_map<int,ll>>(C+5));
	//for(auto i:dp)for(auto j:i)for(auto k:j)cout<<k<<" ";;cout<<"\n";
	res+=f(0,0,0);
	return res;
}
