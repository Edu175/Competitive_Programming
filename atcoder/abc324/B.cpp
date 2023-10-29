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

void f(ll& n, ll d){
	while(n%d==0)n/=d;
}

int main(){FIN;
	ll n; cin>>n;
	f(n,2);
	f(n,3);
	if(n==1)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
