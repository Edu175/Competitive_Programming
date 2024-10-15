#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	cout<<"1\n";
	ll N; cin>>N;
	ll n=rng()%(N-1)+2;
	vector<ii>ed;
	fore(i,1,n)ed.pb({i,0});
	fore(i,2,n)ed.pb({i,1});
	vector<ii>cand;
	fore(i,2,n)fore(j,i+1,n)cand.pb({i,j});
	shuffle(ALL(cand),rng);
	ll m=rng()%(SZ(cand)+1);
	fore(i,0,m)ed.pb(cand[i]);
	ll z=rng()%(n-1)+1;
	cout<<z<<" "<<n-z<<" "<<SZ(ed)<<"\n";
	// shuffle(ALL(ed),rng);
	for(auto [x,y]:ed){
		// if(rng()&1)swap(x,y);
		cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}
