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

void tree(ll n){
	vector<ii> ed;
	fore(i,1,n){
		ll p=rng()%i;
		// ll p=i-1;
		ed.pb({p,i});
	}
	vv per(n); iota(ALL(per),1);
	shuffle(ALL(per),rng);
	shuffle(ALL(ed),rng);
	for(auto [u,v]:ed){
		if(rng()&1)swap(u,v);
		cout<<per[u]<<" "<<per[v]<<"\n";
	}
}

int main(){
	FIN;
	ll N,Q,V; cin>>N>>Q>>V;
	ll n=N,q=Q;
	auto getv=[&](){return rng()%V+1;};
	auto getx=[&](){return rng()%n+1;};
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<getv()<<" ";;cout<<"\n";
	fore(i,0,n)cout<<"BW"[rng()%2];
	cout<<"\n";
	tree(n);
	while(q--){
		ll ty=rng()%3+1; ty=2;
		if(!q)ty=3;
		if(ty==1){
			cout<<ty<<" "<<getx()<<" "<<getv()<<"\n";
		}
		if(ty==2){
			cout<<ty<<" "<<getx()<<"\n";
		}
		if(ty==3){
			cout<<ty<<"\n";
		}
	}
}