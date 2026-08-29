#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<ii> ed;
		fore(i,0,n)cout<<i<<" ";;cout<<"\n";
		show(a)
		fore(i,0,m){
			ll x,y,z; cin>>x>>y>>z; x--,y--,z--;
			cerr<<i<<": "<<x<<","<<y<<","<<z<<"\n"; 
			vv nod={x,y,z};
			fore(i,0,3)fore(j,i+1,3)ed.pb({nod[i],nod[j]});
			vv per(3); iota(ALL(per),0);
			sort(ALL(per),[&](ll i, ll j){
				return a[nod[i]]<a[nod[j]];
			});
			vv agr={1,3,2};
			vv ans(3);
			fore(pos,0,3){
				ll i=per[pos],j=per[(pos+1)%3];
				ll w=agr[pos];
				if((i+1)%3!=j)swap(i,j);
				ans[i]=w;
				a[nod[i]]+=w;
				a[nod[j]]+=w;
			}
			show(ans);
			show(a);
		}
		cout<<endl;
		for(auto [i,j]:ed)assert(a[i]!=a[j]);
	}
    return 0;
}
