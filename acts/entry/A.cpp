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

ll get(ll x){
	if(x<=2)return 1;
	if(x%10==7)return get(x-5)+1;
	if(x%4==0)return get(x/4)+get(x/2);
	return get(x+1)+2;
}

int main(){FIN;
	ll x; cin>>x;
	cout<<get(x)<<"\n";
	return 0;
}
