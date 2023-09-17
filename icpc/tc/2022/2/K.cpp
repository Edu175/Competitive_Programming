#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

bool ask(pair<ll,ll>p){
	string s;
	cout<<p.fst<<" "<<p.snd<<endl;
	cin>>s;
	if(s=="black")return 1;
	else return 0;
}

int main(){FIN;
	ll n; cin>>n;
	ll l=1,r=1000000000;
	ll s=ask({0,1});
	while(--n){
		//cout<<l<<" "<<r<<"\n";
		ll x=(l+r)/2;
		if(ask({x,1})==s)l=x+1;
		else r=x-1;
	}
	cout<<l<<" "<<0<<" "<<r<<" "<<2;
	return 0;
}
