#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll ans=16;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		
		vector<ii>ops;
		fore(i,0,n)fore(j,0,m)ops.pb({i,j});
		ll res=accumulate(ALL(a),0ll);
		vv does(SZ(ops)); fore(i,max(SZ(does)-k,0ll),SZ(does))does[i]=1;
		sort(ALL(ops));
		do{
			auto c=a;
			fore(i,0,SZ(ops))if(does[i])c[ops[i].fst]&=b[ops[i].snd];
			ll resi=accumulate(ALL(c),0ll);
			res=min(res,resi);
			if(resi==0){
				fore(i,0,SZ(ops))if(does[i]){
					cerr<<ops[i].fst<<","<<ops[i].snd<<" ";
				}cerr<<"\n";
				imp(c)
			}
		}while(next_permutation(ALL(does)));
		cout<<res<<"\n";
		
	}
	return 0;
}
