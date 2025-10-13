#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXA=105,MAXN=12,MAXS=53;
const ld INF=MAXN + 10;
ll n;
ll v[MAXN];
ll A,V;
vv ps[MAXN];
ld dp[MAXN][MAXS][MAXA];
ll cdp[MAXN][MAXS][MAXA];
ll bdp[MAXN][MAXS][MAXA];
ld f(ll i, ll s, ll Ap){
	// cerr<<A<<"\n";
	// cerr<<i<<" "<<s<<" "<<Ap<<"\n";
	auto &res=dp[i][s][Ap];
	auto &cu=cdp[i][s][Ap];
	auto &bu=bdp[i][s][Ap];
	if(cu!=-1)return res;
	if(i==n)return res=Ap==0&&s==0?0:INF;
	ll po=0;
	res=INF;
	cu=-2;
	fore(c,0,Ap+1){
		while(po<SZ(ps[i])&&ps[i][po]==c-1)po++;
		ll b=c-po;
		if(b>s)break;
		ld cur=abs(ld(c)/A-ld(v[i])/V)+f(i+1,s-b,Ap-c);
		if(cur<res){
			res=cur;
			cu=c;
			bu=b;
		}
	}
	return res;
}
vv used;
void build(ll i, ll s, ll Ap){
	// cerr<<"build "<<i<<" "<<s<<" "<<Ap<<endl;
	// cerr<<A<<"\n";
	if(i==n){
		assert(Ap==0&&s==0);
		return;
	}
	auto &c=cdp[i][s][Ap];
	auto &b=bdp[i][s][Ap];
	if(c==-2)return;
	used[i]=c;
	build(i+1,s-b,Ap-c);
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("elections.in","r",stdin);
	freopen("elections.out","w",stdout);
	#endif
	JET
	ll s; cin>>n>>s;
	fore(i,0,n){
		cin>>v[i];
		V+=v[i];
		ll sz; cin>>sz;
		ps[i].resize(sz);
		fore(j,0,sz)cin>>ps[i][j],ps[i][j]--;
	}
	ld ans=INF;
	vv res(n);
	used=vv(n);
	fore(_A,0,MAXA){
		// fore(i,0,MAXN)fore(j,0,MAXS)fore(k,0,MAXS)dp[i][j][k]=-1;
		mset(cdp,-1);
		A=_A;
		auto cur=f(0,s,A);
		// cerr<<"A: "<<A<<" "<<cur<<endl;
		if(cur>=INF-5)continue; // -EPS
		if(cur<ans){
			build(0,s,A);
			ans=cur;
			res=used;
		}
	}
	fore(i,0,n)cout<<res[i]<<"\n";
	return 0;
}