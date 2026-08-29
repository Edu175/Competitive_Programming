#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,cuca=b;i<cuca;i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	FIN;
	cout<<"1\n";
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2; cout<<n<<"\n";
	vector<ii> ed;
	fore(i,1,n){
		ll p=rng()%i;
		ed.pb({p,i});
	}
	vv per(n); iota(ALL(per),1);
	shuffle(ALL(per),rng);
	shuffle(ALL(ed),rng);
	for(auto [u,v]:ed){
		// if(rng()&1)swap(u,v);
		cout<<per[u]<<" "<<per[v]<<" "<<rng()%V+1<<"\n";
	}
}