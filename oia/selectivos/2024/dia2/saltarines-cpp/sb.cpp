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
	ll cot=0;
	fore(i,0,C)cot+=n-i;
	ll ans=min(tot+k,cot);
	return ans-tot;
}
