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
typedef long long LL;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll ITER=30;
const ll MAXN=5e5+5;
ll ks[MAXN],oc[MAXN],a[MAXN];
ii qs[MAXN];
ll ans[MAXN],sum[MAXN];
LL h[2*MAXN];
const ll S=19,MK=(1<<S)-1;

inline LL cv(const LL &a, const LL &b){
	return (a<<S)|b;
}

int main(){
	JET
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qs[i]={l,r};
	}
	mset(ans,-1);
	fore(_,0,ITER){
		mset(sum,-1);
		mset(oc,0);
		ll cnt=0;
		fore(i,0,q){
			auto [l,r]=qs[i];
			// ran=(ran*mul+add)%MOD;
			ll p=rng()%(r-l)+l,k=a[p];
			ks[i]=k;
			h[cnt++]=cv(l,i);
			h[cnt++]=cv(r,i);
		}
		sort(h,h+cnt);
		ll po=0;
		fore(t,0,n+1){
			while(po<cnt&&(h[po]>>S)==t){
				auto i=h[po++]&MK;
				ll c=oc[ks[i]];
				if(sum[i]==-1)sum[i]=c;
				else {
					sum[i]=c-sum[i];
					if(sum[i]*2>qs[i].snd-qs[i].fst)ans[i]=ks[i];
				}
			}
			if(t<n)oc[a[t]]++;
		}
	}
	fore(i,0,q)cout<<ans[i]+1<<"\n";
	return 0;
}