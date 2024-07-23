#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> 
indexed_set;


int main(){
	JET
	indexed_set ss[26];
	int n,m; cin>>n>>m;
	string s; cin>>s;
	fore(i,0,SZ(s)){
		ss[(s[i]-'a')].insert(i);
	}	
	fore(i,0,m){
		int x,y,l; cin>>x>>y>>l;
		x--;
		y--;
		vv a,b;
		fore(j,0,26){
			a.pb(ss[j].order_of_key(x+l)-ss[j].order_of_key(x));
			b.pb(ss[j].order_of_key(y+l)-ss[j].order_of_key(y));
		}
		sort(ALL(a));
		sort(ALL(b));
		(a==b) ? cout<<"YES\n" : cout<<"NO\n";
	}
	return 0;
}