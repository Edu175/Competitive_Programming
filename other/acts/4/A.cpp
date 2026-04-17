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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=505;
int main(){FIN;
	ll n; cin>>n;
	vector<ll> a[n];
	vector<ll>res1;
	fore(i,0,n){
		a[i].resize(n);
		fore(j,0,n)cin>>a[i][j],a[i][j]--;
		if(a[i][0]==i)res1.pb(i);
	}
	ll task; cin>>task;
	if(task==1){
		cout<<SZ(res1)<<"\n";
		for(auto i:res1)cout<<i+1<<" ";;cout<<"\n";
		return 0;
	}
	bitset<MAXN>pre[n]; // ,)
	fore(i,0,n)fore(j,0,n){
		if(a[i][j]==i)break;
		pre[i][a[i][j]]=1;
	}
	vector<ll>res;
	fore(x,0,n)fore(i,0,n){
		bitset<MAXN>bad;
		fore(j,0,n){
			if(a[i][j]==x)break;
			bad[a[i][j]]=1;
		}
		ll flag=1;
		fore(i2,0,n)if(bad[i2]){
			flag&=((pre[i2]|bad)!=bad);
		}
		if(flag){
			res.pb(x);
			break;
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
