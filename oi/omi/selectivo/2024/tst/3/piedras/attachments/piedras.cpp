#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfgdfh:v)cout<<dfgdfh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll n,q;
ll a[MAXN];

unordered_map<int,ll>dp[MAXN];
// a<=b;
ll f(int i, int j){
	if(dp[i].count(j))return dp[i][j];
	ll &res=dp[i][j];
	ll p=max(i,j)+1;
	if(p==q+2)return res=0;
	if(a[p]<=a[i])return res=abs(a[p]-a[i])+f(p,j);
	if(a[p]>=a[j])return res=abs(a[p]-a[j])+f(i,p);
	return res=min(abs(a[p]-a[i])+f(p,j),abs(a[p]-a[j])+f(i,p));
}

long long int Piedras_Magicas(int N, int A, int B, int Q, vector<int> P) {
	n=N,q=Q;
	fore(i,0,q)
	if(A>B)swap(A,B);
	a[0]=A,a[1]=B;
	fore(i,0,q)a[i+2]=P[i];
	fore(i,0,q+2)dp[i].clear();
	return f(0,1);
}