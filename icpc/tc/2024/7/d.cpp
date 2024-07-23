#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main(){JET
	ll w,n,q; cin>>w>>n>>q;
	vector<ll>oc(n);
	fore(i,0,w){
		ll x; cin>>x; x--;
		oc[x]++;
	}
	vector<ll> bu[w+5];
	fore(i,0,n)bu[oc[i]].pb(i);
	indexed_set st;
	priority_queue<ii>pq;
	vector<ll>ans(q);
	fore(_,0,q){
		ll k; cin>>k; k-=(w+1);
		pq.push({-k,_});
	}
	ll t=0;
	fore(i,0,w+5){
		for(auto j:bu[i])st.insert(j);
		while(SZ(pq)&&-pq.top().fst<t+SZ(st)){
			auto [k,idx]=pq.top(); k=-k;
			ans[idx]=*st.find_by_order((k-t)%SZ(st));
			pq.pop();
		}
		t+=SZ(st);
	}
	while(SZ(pq)){
		auto [k,idx]=pq.top(); k=-k;
		ans[idx]=*st.find_by_order((k-t)%SZ(st));
		pq.pop();
	}
	for(auto i:ans)cout<<i+1<<"\n";
	return 0;
}