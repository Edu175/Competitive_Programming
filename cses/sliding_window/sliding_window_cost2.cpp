#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)

ll k;
ll mid;
ll sl=0,sr=0;
ii v;
ll calc(){
	return mid*v.fst-sl+sr-(k-mid)*v.fst;
}

int main(){FIN;
	ll n; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	if(k==1){
		fore(i,0,n)cout<<"0 ";
		cout<<"\n";
		return 0;
	}
	indexed_set st;
	fore(i,0,k)st.insert({a[i],i});
	mid=(k+1)/2-1;
	fore(i,0,k){
		ll v=st.find_by_order(i)->fst;
		if(i<mid)sl+=v;
		else sr+=v;
	}
	v=*st.find_by_order(mid);
	cout<<calc()<<" ";
	fore(i,k,n){
		ii h={a[i],i};
		st.insert(h);
		if(st.order_of_key(h)<st.order_of_key(v))sl+=h.fst;
		else sr+=h.fst;
		h={a[i-k],i-k};
		if(st.order_of_key(h)<st.order_of_key(v))sl-=h.fst;
		else sr-=h.fst;
		
		st.erase({a[i-k],i-k});
		if(v.snd==i-k)v=*st.find_by_order(st.order_of_key(v));
		if(st.order_of_key(v)<mid){
			sl+=v.fst;
			sr-=v.fst;
			v=*st.find_by_order(mid);
		}
		if(st.order_of_key(v)>mid){
			v=*st.find_by_order(mid);
			sl-=v.fst;
			sr+=v.fst;
		}
		//cout<<st.find_by_order(mid)->fst<<","<<st.find_by_order(mid)->snd<<"\n";
		//cout<<i<<": "<<v.fst<<","<<v.snd<<" "<<sl<<" "<<sr<<" {";
		//for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";;cout<<"} ";
		cout<<calc()<<" ";
		//cout<<"\n";
	}
	cout<<"\n";
	return 0;
}

