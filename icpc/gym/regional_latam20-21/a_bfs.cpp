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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=105;

typedef vector<int> vvi;
typedef bitset<MAXN> mask;

int main(){
	ET
	ll m,n; cin>>m>>n;
	if(m!=1){cout<<"*\n"; return 0;}
	queue<pair<vvi,mask>>q;
	vvi s={1};
	mask mk; mk[1]=1;
	q.push({s,mk});
	unordered_set<mask>st;
	mask res;
	while(SZ(q)){
		auto [x,mk]=q.front(); q.pop();
		if(x.back()==n){
			res=mk;
			break;
		}
		fore(i,0,SZ(x))fore(j,i,SZ(x)){
			ll s=x[i]+x[j];
			if(s<=n&&s>x.back()){
				auto y=x;
				y.pb(s);
				auto mki=mk;
				mki[s]=1;
				if(!st.count(mki)){
					st.insert(mki);
					q.push({y,mki});
				}
			}
		}
	}
	vvi x={1};
	auto go=[&](ll a, ll b){
		// assert(x[a]&&x[b]);
		cout<<"1 "<<a<<"\n";
		cout<<"1 "<<b<<"\n";
		x.pb(a+b);
	};
	while(x.back()!=n){
		fore(i,0,SZ(x))fore(j,i,SZ(x)){
			ll s=x[i]+x[j];
			if(s<=n&&s>x.back()&&res[s]){
				go(x[i],x[j]);
				goto arafue;
			}
		}
		arafue:
		assert(1);
	}
	// cout<<res<<"\n";
	return 0;
}