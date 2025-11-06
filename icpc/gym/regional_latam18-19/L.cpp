#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int  maxn = 1e5+100;
ll p[maxn];


int main(){
	JET
	mset(p,-1);
	fore(i,2,maxn)if(p[i] == -1)for(ll j = i; j<maxn;j+=i) p[j] = i;
	ordered_set os;
	ll q; cin>>q;
	vector<pair<ii,ll>> qu;
	fore(i,0,q){
		ll n,k; cin>>n>>k;
		qu.pb({{n,k},i});
	}
	sort(ALL(qu));
	vv rta(q);
	ll j = 0, i = 2;
	while(j<q){
		auto[n,k] = qu[j].fst;
		while(i<=n){
			os.insert({p[i],i});
			i++;
		}
		rta[qu[j].snd] = os.order_of_key({k + 1,-1});
		j++;
	}
	for(auto x:rta) cout<<x<<"\n";
	return 0;
}