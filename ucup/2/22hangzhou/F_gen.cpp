#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,Q,L; cin>>N>>Q>>L;
	ll n=N,q=Q;
	cout<<n<<" "<<q<<"\n";
	vv a(n); iota(ALL(a),0); shuffle(ALL(a),rng);
	imp(a)
	vv per=a;
	shuffle(ALL(per),rng);
	vector<ii> ed;
	fore(i,1,n){
		// ll p=rng()%i;
		ll p=i-1;
		ed.pb({p,i});
	}
	shuffle(ALL(ed),rng);
	for(auto [x,y]:ed){
		if(rng()&1)swap(x,y);
		cout<<per[x]+1<<" "<<per[y]+1<<" "<<rng()%L+1<<"\n";
	}
	fore(i,0,q){
		cout<<rng()%n+1<<" "<<rng()%L+1<<"\n";
	}
	return 0;
}