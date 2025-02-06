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
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll ITER=35;

int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n);
	vector<vv> pos(n);
	fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]].pb(i);
	auto get=[&](ll k, ll l, ll r){
		auto &v=pos[k];
		return lower_bound(ALL(v),r)-lower_bound(ALL(v),l);
	};
	vector<bool> vis(n);
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=-1;
		vv nod;
		fore(_,0,ITER){
			ll p=rng()%(r-l)+l,k=a[p];
			if(vis[k])continue;
			vis[k]=1; nod.pb(k);
			ll q=get(k,l,r);
			if(q*2>r-l){
				res=k;
				break;
			}
		}
		for(auto i:nod)vis[i]=0;
		cout<<res+1<<"\n";
	}
	return 0;
}