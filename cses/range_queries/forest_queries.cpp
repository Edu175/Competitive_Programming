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
const ll MAXN=1005;

ll ft[MAXN+1][MAXN+1];

void upd(int i0, int j0, ll v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)
		ft[i][j]+=v;
}

ll get(int i0, int j0){
	ll res=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		res+=ft[i][j];
	return res;
}

ll get_sum(int i0, int i1, int j0, int j1){
	return get(i1,j1)-get(i0,j1)-get(i1,j0)+get(i0,j0);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		upd(i,j,(c=='*'));
	}
	while(q--){
		ll i0,i1,j0,j1; cin>>i0>>j0>>i1>>j1; i0--,j0--;
		cout<<get_sum(i0,i1,j0,j1)<<"\n";
	}
	return 0;
}
