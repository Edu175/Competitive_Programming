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
	ll N,Q,V; cin>>N>>Q>>V;
	ll n=rng()%N+1,q=rng()%Q+1;
	cout<<n<<" "<<rng()%n+1<<" "<<q<<"\n";
	fore(i,0,q){
		cout<<rng()%n+1<<" "<<rng()%(V+1)<<"\n";
	}
	return 0;
}
