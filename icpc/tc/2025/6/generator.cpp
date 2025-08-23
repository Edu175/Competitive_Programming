#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long long ld;
random_device rd;
mt19937 rng(rd());
ii operator-(ii q,ii p){return (ii){q.fst-p.fst,q.snd-p.snd};}
ld operator%(ii q,ii p){return q.fst*p.snd-q.snd*p.fst;}
int main(){
	cout<<1<<"\n";
	ll maxn,maxc;
	cin>>maxn>>maxc;
	ll n=rng()%maxn;
	cout<<n<<"\n";
	vector<ii> v;
	while(SZ(v)<n){
		ii a=(ii){(ll(rng())%(maxc*2)-maxc),(ll(rng())%(maxc*2)-maxc)};
		ll f=1;
		fore(i,0,SZ(v)){
			fore(j,0,SZ(v)){
				if(i!=j && (v[i]-a)%(v[j]-a)==0) {f=0; break;}
			}
			if(!f) break;
		}
		if(f) v.pb(a);
	}
	for(auto [x,y]: v){
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}