#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
    JET
	ll N,M,K,W; cin>>N>>M>>K>>W;
	ll n=N,m=M;
	cout<<n<<" "<<m<<"\n";
	vector<ii> ed;
	fore(i,1,n)ed.pb({rng()%i,i});
	shuffle(ALL(ed),rng);
	for(auto &i:ed)if(rng()&1)swap(i.fst,i.snd);
	vv per(n); iota(ALL(per),0); shuffle(ALL(per),rng);
    for(auto [u,v]:ed){
		u=per[u]+1;
		v=per[v]+1;
		ll w=rng()%W+1;
		cout<<u<<" "<<v<<" "<<w<<"\n";
	}
	fore(i,0,m){
		// ll k=rng()%K+1;
		ll k=K;
		cout<<k<<" ";
		fore(i,0,k){
			cout<<rng()%(n-1)+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}