#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("avx2,bmi,bmi2,popcnt,lzcnt")
ll B=60;
ll prox(ll x){
	fore(j,0,B){
		if(!(x>>j&1)&&!(x>>(j+1)&1)){
			ll pot=1<<j;
			if(pot>x)return -1;
			return x-pot;
		}
	}
	return -1;
}
const ll MAXN=205,INF=61*1e15;
ll a[MAXN],n;
unordered_set<ll>st;

ll f(ll m, ll i){
	if(i==-1)return 0;
	if(m<0)return -INF;
	// if(st.count(m))return -INF;
	ll res=-INF;
	while(m!=-1&&!st.count(m)){
		st.insert(m);
		res=max(res,a[i]*__builtin_popcountll(m)+f(m-1,i-1));
		m=prox(m);
		
	}
	return res;
}

int main(){
	JET
	ll m; cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	cout<<f(m,n-1)<<"\n";
	return 0;
}