#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
const ll MAXV=1000;
ll cr[MAXV];

void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
int main(){
	JET
	init_sieve();
	ll N,V; cin>>N>>V;
	vv av;
	fore(i,2,V+1)if(cr[i]==-1)av.pb(i);
	ll n=rng()%N+1; cout<<n<<"\n";
	fore(i,0,n)cout<<av[rng()%SZ(av)]<<" ";;cout<<"\n";
	return 0;
}
