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

char ask(ll a, ll b, ll c, ll d){
	cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	char ch; cin>>ch;
	return ch;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll mx=0;
		fore(i,1,n){
			if(ask(mx,mx,i,i)=='<')mx=i;
		}
		vector<ll>can={0};
		fore(i,1,n){
			char c=ask(mx,can[0],mx,i);
			if(c=='=')can.pb(i);
			if(c=='<')can.clear(),can.pb(i);
		}
		ll mn=can[0];
		for(auto i:can){
			if(ask(mn,mn,i,i)=='>')mn=i;
		}
		cout<<"! "<<mn<<" "<<mx<<endl;
	}
	return 0;
}
