#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skjdhf:v)cout<<skjdhf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//passed (1 2) 3 4 5 8 10 11 12
int main(){FIN;
	ll n; srand((ll)&n); cin>>n;
	vector<ll>a;
	set<ll>st;
	fore(i,0,n){
		ll x; cin>>x;
		if(!st.count(x))a.pb(x);
		st.insert(x);
	}
	n=SZ(a);
	ll C=*st.begin()/4+1;
	//cout<<C<<"\n";
	if(n<=3){
		cout<<C*(C-1)/2<<"\n";
		return 0;
	}
	random_shuffle(ALL(a));
	ll res=0,mx=*prev(st.end());
	fore(l,1,C){
		if(n>3*((mx+l-1)/l))break;
		set<ll>st;
		fore(i,0,n){
			st.insert(a[i]%l);
			if(SZ(st)>3)break;
		}
		if(SZ(st)<=3)res+=l;
	}
	cout<<res<<"\n";
	return 0;
}
