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

int main(){FIN;
	ll N,M; srand((ll)&N); cin>>N>>M;
	ll n=rand()%N+1;
	vector<ll>ms;
	fore(i,0,n)ms.pb(rand()%(M+1));
	sort(ALL(ms));
	cout<<n<<"\n";
	fore(i,0,n){
		ll m=ms[i]-(i?ms[i-1]:0);
		cout<<m<<" ";
		fore(j,0,m)cout<<rand()%n+1<<" ";
		cout<<"\n";
	}
	return 0;
}
