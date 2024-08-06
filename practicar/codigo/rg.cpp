#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,Q,V; cin>>N>>Q>>V;
	ll n=rng()%N+1,q=rng()%Q+1;
	cout<<"1\n";
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
	fore(_,0,q){
		ll ty=rng()%2+1;
		if(ty==1){
			ll l=rng()%n+1,r=rng()%n+1;
			if(l>r)swap(l,r);
			cout<<"1 "<<l<<" "<<r<<"\n";
		}
		else cout<<"2 "<<rng()%n+1<<" "<<rng()%V+1<<"\n";
	}
	return 0;
}