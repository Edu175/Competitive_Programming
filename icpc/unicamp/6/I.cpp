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
	ll n; cin>>n;
	string s=to_string(n);
	ll res=0;
	fore(i,0,10){
		string t(SZ(s),'0'+i);
		if(i&&stoll(t)<=n)res++;
		res+=SZ(s)-1;
	}
	if(SZ(s)==1)res++;
	cout<<res<<"\n";
	return 0;
}
