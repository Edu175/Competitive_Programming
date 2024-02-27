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
const ll MAXN=2e5+5;
const ll K=18;
ll st[K][1ll<<K];
ll a[MAXN];
ll n;
ll oper(ll i, ll j){
	//if(i==-1)return j;
	//if(j==-1)return i;
	if(a[i]>a[j])return i;
	return j;
}
void st_init(){
	fore(i,0,n)st[0][i]=i;
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1){
		//if(i+(1ll<<k-1)>=n)break;
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
	}
}

ll st_query(ll s, ll e){
	if(e-s==0)return -1;
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}

ll dp[MAXN];
ll f(ll l, ll r){
	ll k=st_query(l,r);
	ll &res=dp[k];
	if(res!=-1)return res;
	if(r-l==0)return res=1;
	ll k1=st_query(l,k),k2=st_query(k+1,r);
	res=0;
	if(k-l)res=max(res,abs(k1-k)+f(l,k));
	if(r-k-1)res=max(res,abs(k2-k)+f(k+1,r));
	//cout<<l<<","<<r<<" "<<k<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	st_init();
	mset(dp,-1);
	cout<<f(0,n)<<"\n";
	return 0;
}
