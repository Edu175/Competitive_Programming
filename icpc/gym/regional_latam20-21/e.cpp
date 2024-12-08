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

int main(){
	ET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto solve=[&](vv a){
		vv r(n);
		for(ll i=n-1;i>=0;i--)
			for(r[i]=i+1;r[i]!=n&&a[r[i]]<=a[i];r[i]=r[r[i]]);
		vv es(n);
		fore(i,0,n){
			ll e=n;
			if(r[i]!=n){
				e=(i+r[i]+1)/2;
			}
			es[i]=e;
		}
		priority_queue<ll>pq;
		vv res(n);
		ll va=0;
		fore(i,0,n){
			pq.push(-es[i]);
			va++;
			while(SZ(pq)&&-pq.top()<=i)va--,pq.pop();
			res[i]=va;
		}
		// cout<<"solve\n";
		// for(auto i:a)cout<<i<<" ";;cout<<"\n";
		// for(auto i:es)cout<<i<<" ";;cout<<"\n";
		// for(auto i:res)cout<<i<<" ";;cout<<"\n\n";
		return res;
	};
	vv res=solve(a);
	reverse(ALL(a));
	auto res2=solve(a);
	reverse(ALL(res2));
	fore(i,0,n){
		res[i]+=res2[i]-2;
		cout<<res[i]<<" ";
	}
	cout<<"\n";
}

/*
input:
10
23 20 7 30 43 70 5 42 67 10


solve
23 20 7 30 43 70 5 42 67 10 
2 2 3 4 5 10 7 8 10 10 
1 2 1 1 1 1 2 2 2 3 

solve
10 67 42 5 70 43 30 7 20 23 
1 3 3 4 10 10 10 8 9 10 
1 1 2 1 1 2 3 4 4 4 

0 1 1 0 0 1 3 4 4 5 



output: 3 4 3 2 1 0 1 2 1 2




*/