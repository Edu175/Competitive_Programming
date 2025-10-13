#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll T,M; cin>>T>>M;
	ll n=6;
	ll t=rng()%T+1;
	cout<<t<<"\n";
	vector<ii> all;
	fore(i,0,n)fore(j,i,n)all.pb({i,j});
	while(t--){
		ll m=rng()%M+1;
		shuffle(ALL(all),rng);
		cout<<m<<"\n";
		assert(m<=SZ(all));
		fore(i,0,m){
			cout<<all[i].fst+1<<" "<<all[i].snd+1<<"\n";
		}
	}
	return 0;
}