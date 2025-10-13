#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// const ll MOD=
// int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
// ll mul(ll a, ll b){return a*b%MOD;}
// xd
#define ppc __builtin_popcountll
int dp[22][1ll<<6][1ll<<6];
string bin(ll x){
	string s;
	fore(i,0,6)s.pb((x>>i&1)+'0');
	return s;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		ll n=6; ll N=1ll<<n;
		vector<ii> a;
		vector<vv> g(n,vv(n));
		vv ig(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			if(u==v)ig[u]++;
			else a.pb({u,v}),g[u][v]=g[v][u]=1;
		}
		m=SZ(a);
		fore(i,0,m+1)fore(us,0,N){
			dp[i][us][0]=0;
			for(ll mk=0;mk=mk-us&us;)dp[i][us][mk]=0;
		}
		dp[0][0][0]=1;
		// for(ll s=0;s=s-m&m;)
		auto inner=[&](ll i, ll us, ll mk){
			// cout<<bin(us)<<","<<bin(mk)<<"\n";
			auto &now=dp[i][us][mk];
			dp[i+1][us][mk]+=now;
			auto [u,v]=a[i];
			dp[i+1][us|(1<<u)|(1<<v)][mk^(1<<u)^(1<<v)]+=now;
			// if(now)cout<<i<<": "<<bin(us)<<" "<<bin(mk)<<": "<<now<<"\n";
		};
		fore(i,0,m)fore(us,0,N){
			inner(i,us,0);
			for(ll mk=0;mk=mk-us&us;)inner(i,us,mk);
		}
		vector<ll> got(N);
		fore(us,0,N)fore(mk,0,N)if(ppc(mk)<=2){
			ll cur=dp[m][us][mk];
			// if(cur)cout<<bin(us)<<" "<<bin(mk)<<": "<<cur<<"\n";
			got[us]+=cur;
		}
		// fore(i,0,N)if(got[i]){
		// 	cout<<bin(i)<<": "<<got[i]<<"\n";
		// }
		ll repe=0;
		vv bad(N);
		vv es(6); fore(i,3,6)es[i]=1;
		do{
			ll fg=1,good=1;
			vector<vv> col(2);
			fore(i,0,n)col[es[i]].pb(i);
			fore(w,0,2){
				auto &v=(col[w]);
				ll cur=1;
				fore(i,0,SZ(v))cur&=g[v[i]][v[(i+1)%SZ(v)]];
				fg&=cur;
				if(w)good=cur;
			}
			if(!good)continue;
			repe+=fg;
			ll us=0;
			fore(i,0,n)us|=es[i]<<i;
			// cout<<"good "<<bin(us)<<"\n";
			fore(mk,0,N)if((mk&us)==us){ // us <= mk
				ll otr=mk^us;
				if(otr)bad[mk]+=got[otr];
			}
		}while(next_permutation(ALL(es)));
		assert(repe%2==0); repe/=2;
		// cerr<<"repe "<<repe<<"\n";
		ll all=N-1;
		bad[all]-=repe;
		// cerr<<"bad\n";
		// fore(i,0,N)if(bad[i]){
		// 	cout<<bin(i)<<": "<<bad[i]<<"\n";
		// }
		ll res=0;
		// cerr<<"curs:\n";
		fore(mk,0,N){
			ll cur=got[mk]-bad[mk];
			// if(cur)cout<<bin(mk)<<": "<<cur<<"\n";
			ll cant=0;
			fore(x,0,n)if(ig[x])cant+=mk>>x&1;
			cur<<=cant;
			res+=cur;
		}
		ll cig=0; fore(i,0,n)cig+=ig[i];
		res+=cig;
		res--; // el vacio
		cout<<res<<"\n";
	}
	return 0;
}