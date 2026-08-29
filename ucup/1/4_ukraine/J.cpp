#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main(){
	JET
	ll n,q; cin>>n>>q;
	ll tot = 0, ord = 0, imp = 0;
	vv a(n), aux(n);
	indexed_set in,out;
	fore(i,0,n) out.insert(i);
	fore(i,0,n){
		ll x; cin>>x;x--;
		if(x == i)ord++;
		aux[i] = x;
		out.erase(x);
		a[i] = out.order_of_key(x) + SZ(in) - in.order_of_key(x);
		in.insert(x);
		tot+=a[i];
		a[i]&=1;
		if(a[i])imp++;
	}
	// show(a);cout<<endl;
	// cout<<tot<<endl;
	tot/=2;
	bool pp = tot&1;
	fore(i,0,q){
		ll x,y; cin>>x>>y;x--,y--;
		fore(_,0,2){
			imp-=a[x];
			ord-=(aux[x] == x);
			swap(x,y);
		}
		swap(a[x],a[y]);swap(aux[x],aux[y]);
		fore(_,0,2){
			a[x]+=abs(x-y);
			a[x]&=1;
			imp+=a[x];
			ord+=(aux[x]==x);
			swap(x,y);
		}
		assert(!(pp == (i&1) && ord == n));
		// show(a);cout<<endl;
		if(pp == (i&1))cout<<n<<"\n";
		else if(ord == n)cout<<-1<<"\n";
		else if(imp) cout<<n-1<<"\n";
		else cout<<n-2<<"\n";
		
	}
	
	
	
	
	return 0;
}