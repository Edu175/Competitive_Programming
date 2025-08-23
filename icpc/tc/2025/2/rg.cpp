#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll n,m; cin>>n>>m;
	cout<<n<<" "<<m<<"\n";
	vv per(n); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	vector<ii>ed;
	fore(i,0,m){
		ll p=rng()%n;
		ll x=rng()%(n-1);
		if(x>=p)x++;
		p=per[p]+1;
		x=per[x]+1;
		if(rng()&1)swap(p,x);
		ed.pb({p,x});
	}
	shuffle(ALL(ed),rng);
	for(auto [p,x]:ed)cout<<p<<" "<<x<<"\n";
	return 0;
}