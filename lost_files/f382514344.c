#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ordered_set s;
ll find(ll x){
	ll l=0,r=SZ(s)-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(s.order_of_key(m)>=x)r=m-1;
		else l=m+1;
	}
	return l;
}

long long plantas(vector<int> &a) {
    ll n=SZ(a);
    ll p[n];
    fore(i,0,n)a[i]--,p[a[i]]=i;
    //imp(a);
    //imp(p);
    ll res=0;
    fore(i,0,n){
    	//cout<<i<<":\n";
    	//imp(s);
    	ll lwb=find(p[i]);
    	//cout<<"lwb="<<lwb<<"\n";
    	res+=min(p[i]-lwb,n-1-p[i]-(SZ(s)-lwb));
    	s.insert(p[i]);
    	//cout<<"insert "<<p[i]<<"\n";
    }
    return res;
}
