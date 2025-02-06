#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll MAXN=1e6+10;
ll cr[MAXN];
vi d[MAXN];
bool vis[MAXN];
void init(){
	fore(i,2,MAXN){if(!cr[i])for(long long j=(1LL*i)*i; j<MAXN; j+=i)cr[j]=i;}
}
vi fact(ll n){
	vi r;
	while(cr[n]){
		ll p=cr[n];
		r.pb({p,0});
		while(n%p==0){n/=p; r.back().snd++;}
	}
	if(n>1)r.pb({n,1});
	return r;
}
const ll INF=1e15;
int main(){
	JET
	init();
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n) cin>>a[i];
	vi f[n]; fore(i,0,n) f[i]=fact(a[i]);
	/*fore(i,0,n) {
		cout<<i<<" ";
		for(auto [p,k]: f[i]){cout<<p<<"^"<<k<<" ";}
		cout<<"\n";
	}*/
	vi div[n];
	fore(i,0,n){
			div[i].pb({a[i],0});
			fore(j,0,SZ(f[i])){
				ll p=f[i][j].fst;
				fore(k,0,SZ(div[i])*f[i][j].snd){
					div[i].pb({div[i][k].fst/p,div[i][k].snd+1});
				}
			}
	}
	
	fore(i,0,n){
		//	cout<<i<<" ";
			for(auto [di,dst]:div[i]){
		//cout<<di<<" ";
		vis[di]=1;
		d[di].pb({dst,i});
		}
	//	cout<<"\n";
	}
	fore(i,0,MAXN)if(vis[i])sort(ALL(d[i]));
	vi res(n,(ii){INF,INF});
	fore(i,0,n){
		ll M=INF;
		ll r=INF;
		for(auto [di,dst]:div[i]){
			ll j=d[di][0].snd;
			ll pos=0;
			if(j==i){if(SZ(d[di])>1){j=d[di][1].snd; pos=1;} else continue;}
			if(M==d[di][pos].fst+dst) {r=min(r,j);}
			else if(M>d[di][pos].fst+dst){M=d[di][pos].fst+dst;r=j;}
			//cout<<"M"<<M<<"r"<<r<<"\n";
			//cout<<dst<<" "<<di<<" "<<i<<"\n";
		}
		res[i]=ii({M,r});
	}
	fore(i,0,n){
		cout<<res[i].snd+1<<"\n";
	}
	return 0;
}