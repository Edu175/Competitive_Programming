#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b; i<edu;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) mset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll K=18;
#define oper min
ll st[K][1ll<<K];ll n;
void st_init(ll *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s,ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}
int main(){FIN;
	ll q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	st_init(a);
	while(q--){
		ll s,e; cin>>s>>e; s--;
		cout<<st_query(s,e)<<"\n";
	}
	return 0;
}
