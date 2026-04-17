#include<bits/stdc++.h>
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
const ll MAXN=4005,INF=MAXN*1e10;

ll dp[MAXN][MAXN];
ll n,m;
ll a[MAXN],b[MAXN],d[MAXN],ch[MAXN];

ll f(ll i, ll j){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(i==n)return res=j==m?0:INF;
	res=d[i]+f(i+1,j);
	if(j<m){
		res=min(res,abs(a[i]-b[j])+f(i+1,j+1));
	}
	return res;
}
ll ans[MAXN];
void build(ll i, ll j){
	if(i==n)return;
	ll res=f(i,j);
	if(res==d[i]+f(i+1,j)){
		ans[i]=ch[i];
		build(i+1,j);
	}
	else {
		ans[i]=j;
		build(i+1,j+1);
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("evacuation.in","r",stdin);     freopen("evacuation.out","w",stdout);
	#endif
	JET
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cin>>m;
	fore(i,0,m)cin>>b[i];
	vv per(m); iota(ALL(per),0);
	vv pera(n); iota(ALL(pera),0);
	sort(ALL(pera),[&](ll i, ll j){return a[i]<a[j];});
	sort(ALL(per),[&](ll i, ll j){return b[i]<b[j];});
	sort(a,a+n);
	sort(b,b+m);
	mset(dp,-1);
	fore(i,0,n){
		d[i]=INF;
		fore(j,0,m){
			d[i]=min(d[i],abs(a[i]-b[j]));
			if(d[i]==abs(a[i]-b[j]))ch[i]=j;
		}
	}
	cout<<f(0,0)<<"\n";
	build(0,0);
	vv res(n);
	fore(i,0,n){
		ll x=pera[i];
		res[x]=per[ans[i]];
	}
	fore(i,0,n)cout<<res[i]+1<<" ";;cout<<"\n";
	return 0;
}