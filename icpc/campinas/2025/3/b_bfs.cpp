#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("avx2,bmi,bmi2,popcnt,lzcnt")
ll B=60;
const ll MAXN=205,INF=61*1e15;
ll a[MAXN],n;
unordered_set<ll>st;

ll clz(ll n){return __builtin_clzll(n);}
ll ctz(ll n){return __builtin_ctzll(n);}
ll ppc(ll n){return __builtin_popcountll(n);}

ll bfs(ll m){
	unordered_set<ll>vis;
	unordered_map<ll,ll> now,prox; // layers
	now[m]=0; vis.insert(m);
	for(ll i=n-1;i>=0;i--){
		cout<<"layer "<<i<<"\n";
		for(auto [m,fij]:now){
			fore(k,0,64-clz(m)){
				ll num=-1,cnt=0,acum=0;
				for(ll j=B-1;j>=0;j--)if(m>>j&1){
					ll c=k-cnt,ones=(1ll<<c)-1;
					if(j-c<0)break;
					ll n=acum|(ones<<(j-c));
					num=max(num,n);
					acum|=1ll<<j; cnt++;
				}
				if(num==-1)break;
				
				// arista con num
				cout<<"arista "<<m<<" -> "<<num<<"\n";
				
				if((!i||num>=0)){
					cout<<"entro\n";
					ll val=a[i]*__builtin_popcountll(num)+fij;
					if(!prox.count(num)||val>prox[num])
						prox[num]=val;
				}
				
			}
		}
		
		for(auto [m,dkfjhg]:now)vis.insert(m);
		swap(now,prox); prox.clear();
		
	}
	ll res=-INF;
	for(auto [m,val]:now)res=max(res,val);
	return res;
}

int main(){
	JET
	ll m; cin>>n>>m; m++;
	fore(i,0,n)cin>>a[i];
	cout<<bfs(m)<<"\n";
	return 0;
}