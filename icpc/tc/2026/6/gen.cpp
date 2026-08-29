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

int main(){
	JET
	ll N; cin>>N;
	ll n=N;
	cout<<n<<"\n";
	vector<ii> ed;
	fore(i,1,n){
		// ll p=rng()%i;
		ll p=i-1;
		ed.pb({p,i});
	}
	shuffle(ALL(ed),rng);
	vv per(n); iota(ALL(per),1);
	shuffle(ALL(per),rng);
	for(auto [x,y]:ed){
		if(rng()&1)swap(x,y);
		cout<<per[x]<<" "<<per[y]<<"\n";
	}
	return 0;
}
