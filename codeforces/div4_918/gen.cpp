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
	ll n=500,m=1000;
	cout<<"1\n"<<n<<" "<<m<<"\n";
	fore(i,0,n-1){
		cout<<i+1<<" "<<i+2<<" "<<1e5<<"\n";
	}
	fore(i,n-1,m)cout<<"1 2 "<<1e5<<"\n";
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<1000;
	}
	cout<<"\n";
	return 0;
}
