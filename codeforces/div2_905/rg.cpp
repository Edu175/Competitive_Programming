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
	cout<<"1\n";
	ll N,Q,V; srand((ll)&N); cin>>N>>Q>>V;
	ll n=rand()%N+1; cout<<n<<"\n";
	fore(i,0,n)cout<<rand()%(2*V)-V+1<<" ";;cout<<"\n";
	ll q=rand()%Q+1; cout<<q<<"\n";
	while(q--){
		ll l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		cout<<l<<" "<<r<<" "<<rand()%(2*V)-V+1<<"\n";
	}
	return 0;
}
