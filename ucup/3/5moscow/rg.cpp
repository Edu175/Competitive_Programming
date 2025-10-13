#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
    JET
	ll N,M,K,V,W; cin>>N>>M>>K>>V>>W;
	double C; cin>>C;
	ll n=rng()%(N-1)+2,m=rng()%M+1; cout<<n<<" "<<m<<"\n";
	vector<ii> ed;
	vv per(n); iota(ALL(per),0); shuffle(ALL(per),rng);
	fore(i,1,n){
		ll u=rng()%i,v=i;
		if(rng()&1)swap(u,v);
		u=per[u]; v=per[v];
		ed.emplace_back(u,v);
	}
	shuffle(ALL(ed),rng);
	for(auto [u,v]:ed){
		cout<<u+1<<" "<<v+1<<" "<<rng()%V+1<<"\n";
	}
	fore(i,0,m){
		ll k=rng()%K+1; cout<<k<<" "<<rng()%n+1<<"\n"; // k,s
		fore(i,0,k)cout<<rng()%W+1<<" ";;cout<<"\n"; // vals
		fore(i,0,k)cout<<rng()%ll(max(C*V,1.))+1<<" ";;cout<<"\n"; // lens
	}
	return 0;
}
