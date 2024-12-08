#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll T,N,Q,V; cin>>T>>N>>Q>>V;
	ll t=rng()%T+1; cout<<t<<"\n";
	while(t--){
		ll n=rng()%(N-1)+2;
		ll g[n][n]; mset(g,0);
		fore(i,1,n)g[rng()%i][i]=1;
		vector<ii>ed,all;
		fore(i,0,n)fore(j,i+1,n){
			if(!g[i][j])all.pb({i,j});
			else ed.pb({i,j});
		}
		shuffle(ALL(all),rng);
		ll m=rng()%(SZ(all)+1);
		fore(i,0,m)ed.pb(all[i]);
		ll q=rng()%Q+1;
		cout<<n<<" "<<SZ(ed)<<" "<<q<<"\n";
		for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<" "<<rng()%V+1<<"\n";
		fore(i,0,q){
			ll x=rng()%n,y=rng()%(n-1);
			if(y>=x)y++;
			cout<<x+1<<" "<<y+1<<" "<<rng()%V+1<<"\n";
		}
	}
	return 0;
}