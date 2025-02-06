#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
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
    ll N,V; cin>>N>>V;
	ll n=rng()%(N-2)+3;
	cout<<n<<"\n";
	assert(n<=V*V);
	vector<ii>ps;
	if(2*n<V*V){
		set<ii>st;
		fore(i,0,n){
			ll x=rng()%V+1;
			ll y=rng()%V+1;
			if(st.count({x,y}))i--;
			else ps.pb({x,y}),st.insert({x,y});
		}
	}
	else {
		vector<ii>all;
		fore(i,0,V)fore(j,0,V)all.pb({i+1,j+1});
		shuffle(ALL(all),rng);
		fore(i,0,n)ps.pb(all[i]);
	}
	sort(ALL(ps));
	for(auto [x,y]:ps)cout<<x<<" "<<y<<"\n";
}