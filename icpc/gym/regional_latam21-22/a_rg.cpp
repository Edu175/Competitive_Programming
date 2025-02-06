#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	ET
	ll N,V,S; cin>>N>>V>>S;
	ll n=rng()%(N-3)+4;
	vector<ii>a;
	if(2*n<(V+1)*(V+1)){
		set<ii>st;
		while(SZ(st)<n){
			ll x=rng()%(V+1),y=rng()%(V+1);
			st.insert({x,y});
		}
		for(auto i:st)a.pb(i);
		shuffle(ALL(a),rng);
	}
	else {
		vector<ii>all;
		fore(i,0,V+1)fore(j,0,V+1)all.pb({i,j});
		shuffle(ALL(all),rng);
		fore(i,0,n)a.pb(all[i]);
	}
	cout<<rng()%S+1<<" "<<n<<"\n";
	for(auto [x,y]:a){
		cout<<x<<" "<<y<<"\n";
	}
}