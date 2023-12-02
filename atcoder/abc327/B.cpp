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

ll pw(ll a, ll b){
	ll res=1;
	fore(i,0,b)res*=a;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll res=-1;
	fore(i,0,16)if(n==pw(i,i))res=i;
	cout<<res<<"\n";
	return 0;
}
