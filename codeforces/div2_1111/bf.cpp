#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=50,INF=1e18;
vv g[MAXN];
ll dfs(ll x, ll fa, ll to){
	if(x==to)return 0;
	ll res=INF;
	for(auto y:g[x])if(y!=fa)res=min(res,dfs(y,x,to)+1);
	return res;
}

ll n;
vv per;
ll fg;
vector<set<ll>> st(2);
void f(ll i){
	if(i==n){
		ll res=0;
		fore(i,0,n)res+=dfs(i,-1,(i+1)%n);
		st[fg].insert(res);
		return;
	}
	ll x=per[i];
	fore(j,(fg?i-1:0),i){
		ll p=per[j];
		g[x].pb(p);
		g[p].pb(x);
		f(i+1);
		g[x].pop_back();
		g[p].pop_back();
	}
}

int main(){FIN;
	cin>>n;
	per=vv(n); iota(ALL(per),0);
	fore(i,0,n)cin>>per[i],per[i]--;
	fg=1;
	f(1);
	ll res=*st[1].begin();
	cout<<res<<"\n";
	cout<<"max "<<n*n/2<<"\n";
	// show(st[1])
	// do{
	// 	// fg=0; f(1);
	// 	fg=1; f(1);
	// }while(next_permutation(ALL(per)));
	// cout<<"arboles: "; show(st[0]);
	// cout<<"lineas : "; show(st[1]);
	// assert(*prev(st[1].end())==n*n/2);
	return 0;
}
