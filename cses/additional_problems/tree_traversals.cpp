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
const ll MAXN=1e5+5;
const ll K=17;//K such that 2^k>n
ll pre[MAXN],in[MAXN],val[MAXN];
ll oper(ll i, ll j){
	if(val[in[i]]<val[in[j]])return i;
	return j;
}
ll st[K][1ll<<K];
void st_init(ll n){
	fore(i,0,n)st[0][i]=i;
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
vector<ll>post;
void f(ll l, ll r){
	ll k=st_query(l,r);
	if(k-l)f(l,k);
	if(r-(k+1))f(k+1,r);
	post.pb(in[k]);
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>pre[i],pre[i]--;
	fore(i,0,n)cin>>in[i],in[i]--;
	fore(i,0,n)val[pre[i]]=i;
	st_init(n);
	f(0,n);
	for(auto i:post)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
