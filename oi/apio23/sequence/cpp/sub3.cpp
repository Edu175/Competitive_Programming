#include "sequence.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	ll res=0;
	fore(i,0,n){
		ll q=SZ(pos[i]),m=0;
		fore(j,0,SZ(pos[i])-1){
			ll l=pos[i][j],r=pos[i][j+1];
			if(l+1!=r){
				m=r-l-1;
				res=max({res,l-pos[i][0]+1,pos[i].back()-r+1});
			}
		}
		if(m==0){
			res=max(res,q);
			continue;
		}
		if(n-m>=m)res=max(res,q);
	}
	return res;
}
