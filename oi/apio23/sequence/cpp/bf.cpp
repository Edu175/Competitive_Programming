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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;

int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	ll res=0;
	fore(l,0,n){
		indexed_set st;
		vector<ll>c(n);
		fore(r,l,n){
			c[a[r]]++;
			st.insert({a[r],r});
			ll m0=st.find_by_order((SZ(st)-1)/2)->fst;
			ll m1=st.find_by_order((SZ(st))/2)->fst;
			//imp(st);
			//cout<<m0<<" "<<m1<<"\n";
			res=max({res,c[m0],c[m1]});
		}
	}
	return res;
}
