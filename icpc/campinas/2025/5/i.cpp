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
const ll ITER=30;
const ll MAXN=5e5+5;

ll sum[MAXN][ITER];
ll ks[MAXN][ITER];
// vector<ii> h[MAXN]; // i,j,k,sig
long long ran=5,mul=1358765,add=3512031,MOD=1777771;
vector<ii> h[MAXN];
int main(){
	mset(sum,-1);
	JET
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<ii>qs(q);
	vv sz(n+1);
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qs[i]={l,r};
		sz[l]+=ITER;
		sz[r]+=ITER;
	}
	fore(i,0,n+1)h[i].resize(sz[i]),sz[i]=0;
	fore(i,0,q){
		auto [l,r]=qs[i];
		fore(j,0,ITER){
			ran=(ran*mul+add)%MOD;
			ll p=ran%(r-l)+l,k=a[p];
			h[l][sz[l]++]={i,j};
			h[r][sz[r]++]={i,j};
			ks[i][j]=k;
		}
	}
	vv oc(n);
	fore(t,0,n+1){
		for(auto [i,j]:h[t]){
			ll c=oc[ks[i][j]];
			if(sum[i][j]==-1)sum[i][j]=c;
			else sum[i][j]=c-sum[i][j];
		}
		if(t<n)oc[a[t]]++;
	}
	fore(i,0,q){
		ll res=-1;
		fore(j,0,ITER){
			if(sum[i][j]*2>qs[i].snd-qs[i].fst)res=ks[i][j];
		}
		cout<<res+1<<"\n";
	}
	return 0;
}