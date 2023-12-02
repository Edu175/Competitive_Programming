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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll a[n];
		fore(i,0,n)a[i]=s[i]-'0';
		vector<ll>b;
		ll q=1;
		fore(i,1,n){
			if(a[i]==a[i-1])q++;
			else b.pb(q%2),q=1;
		}
		b.pb(q%2);
		//imp(b);
		vector<ll>p;
		ll cnt=0;
		for(auto i:b){
			//cout<<cnt++<<": "<<i<<" "; imp(p);
			if(!i){
				if(SZ(p)){
					if(p.back())p.pb(0);
					else p.pop_back();
				}
			}
			else {
				if(SZ(p)&&p.back()==0){
					p.pop_back();
					p.pop_back();
					if(SZ(p)){
						if(p.back())p.pb(0);
						else p.pop_back();
					}
				}
				else p.pb(1);
			}
		}
		while(SZ(p)&&p.back()==0)p.pop_back();
		//imp(p);
		if(SZ(p)<=1)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
