#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN;
	ll N,V,Q; srand((ll)&N); cin>>N>>V>>Q;
	ll n=rand()%N+1,q=rand()%Q+1;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rand()%V+1<<" ";;cout<<"\n";
	fore(i,0,n)cout<<rand()%V+1<<" ";;cout<<"\n";
	while(q--){
		ll ty=rand()%3+1;
		ll l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		cout<<ty<<" "<<l<<" "<<r;
		if(ty<3)cout<<" "<<rand()%V+1;
		cout<<"\n";
	}

	return 0;
}
