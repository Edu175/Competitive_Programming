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
typedef int ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	cout<<"1\n";
	ll n=2e5-1,q=2e5;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<"1";
	}
	cout<<"\n";
	fore(i,0,q)cout<<1<<" "<<n<<"\n";
	return 0;
}
