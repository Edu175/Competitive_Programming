#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vector<ii> p;
const int maxn = 75, maxk = 75;
ll dp[maxn][maxk];
ii rec[maxn][maxk];
ll n,k;
const ll INF=1e18;
ll f(int i, int j){
	if(j<0) return 0;
	if(i<0) return -INF;
	ll &r = dp[i][j];
	if(r!=-1) return r;
	r = f(i-1,j);
	rec[i][j] = {i-1,j};
	if(f(i-1,j-1)+p[i].fst+p[i].snd*(j+1-k)>r){
		r = f(i-1,j-1)+p[i].fst+p[i].snd*(j+1-k);
		rec[i][j] = {i-1,j-1};
	}
	return r;
}

bool s(ii a, ii b){
	swap(a.fst,a.snd);
	swap(b.fst,b.snd);
	return a<b;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		p.resize(n);
		fore(i,0,n) cin>>p[i].fst>>p[i].snd;
		ll totb = 0;
		ll perm[n]; iota(perm,perm+n,0);
		sort(perm,perm+n,[&](ll i, ll j){
			return s(p[i],p[j]);
		});
		ll perm2[n];
		fore(i,0,n) perm2[perm[i]]=i;
		for(auto [x,y] : p) totb+=y;
		sort(ALL(p),s);
		// fore(i,0,n) cout<<p[i].fst<<" "<<p[i].snd<<" P";;cout<<"\n";
		// fore(i,0,n) cout<<perm[i]<<" ";;cout<<"PERM\n";
		// fore(i,0,n) cout<<perm2[i]<<" ";;cout<<"PERM2\n";
		mset(dp,-1);
		f(n-1,k-1);
		cout<<n+(n-k)<<"\n";
		vv metidos;
		bool vis[n]; mset(vis,0);
		ii ant = {n-1,k-1};
		while(ant.fst!=-1 && ant.snd!=-1){
			// cout<<ant.fst<<" "<<ant.snd<<"viendo\n";
			if(rec[ant.fst][ant.snd].snd<ant.snd) {
				// cout<<"mmeto "<<ant.fst<<"\n";
				metidos.pb(ant.fst); vis[ant.fst]=1;
			}
			ant=rec[ant.fst][ant.snd];
		}
		// fore(i,0,n){fore(j,0,k) cout<<dp[i][j]<<"DP ";; 
		// cout<<"\n";}
		// fore(i,0,n){fore(j,0,k) cout<<"("<<rec[i][j].fst<<","<<rec[i][j].snd<<") ";; cout<<"\n";}
		
		// cout<<SZ(metidos)<<" "<<k<<endl;
		// fore(i,0,k) cout<<p[metidos[i]].fst<<"MM\n";
		// fore(i,0,n) cout<<vis[i];;cout<<"\n";
		reverse(ALL(metidos));
		vv final;
		fore(i,0,n){
			if(!vis[i]) final.pb(i);
		}
		
		fore(i,0,k-1){
			cout<<perm[metidos[i]]+1<<" ";
		}
		fore(i,0,n-k){cout<<perm[final[i]]+1<<" -"<<perm[final[i]]+1<<" ";}
		cout<<perm[metidos.back()]+1<<"\n";
	}
	return 0;
}