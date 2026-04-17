#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=101;

typedef bitset<MAXN> mask;

int main(){
	ET
	ll m,n; cin>>m>>n;
	if(m!=1){cout<<"*\n"; return 0;}
	queue<pair<mask,ll>>q;
	mask s; s[1]=1; q.push({s,1});
	unordered_set<mask>st;
	mask res;
	while(SZ(q)){
		auto [x,last]=q.front(); q.pop();
		if(x[n]){
			res=x;
			break;
		}
		for(ll i=x._Find_first();i<MAXN;i=x._Find_next(i)){
			for(ll j=x._Find_next(i-1);j<MAXN;j=x._Find_next(j)){
				if(i+j<=n&&i+j>last){
					auto y=x;
					y[i+j]=1;
					if(y[n]==1){
						res=y;
						goto afuera;
					}
					if(!st.count(y)){
						st.insert(y);
						q.push({y,i+j});
					}
				}
			}
		}
	}
	afuera:
	mask x; x[1]=1;
	auto go=[&](ll a, ll b){
		assert(x[a]&&x[b]);
		cout<<"1 "<<a<<"\n";
		cout<<"1 "<<b<<"\n";
		x[a+b]=1;
	};
	while(!x[n]){
		for(ll i=x._Find_first();i<MAXN;i=x._Find_next(i)){
			for(ll j=x._Find_next(i-1);j<MAXN;j=x._Find_next(j)){
				if(i+j<=n&&!x[i+j]&&res[i+j]){
					go(i,j);
					goto arafue;
				}
			}
		}
		arafue:
		assert(1);
	}
	// cout<<res<<"\n";
	return 0;
}