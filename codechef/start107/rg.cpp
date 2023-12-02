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
const ll MAXP=1e9;

int main(){FIN;
	ll N,X,Y; srand((ll)&N); cin>>N>>X>>Y;
	ll n=rand()%N+1,v=rand()%X+1;
	cout<<"1\n"<<n<<" "<<v<<"\n";
	fore(i,0,n){
		ll x=rand()%X+1;
		cout<<x<<" "<<rand()%min(Y,MAXP/x)+1<<"\n";
	}
	return 0;
}
