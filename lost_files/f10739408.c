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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a; cin>>a;
		map<ll,pair<ll,ll>>mp;
		fore(i,0,n){
			if(i%2)mp[a[i]].snd++;
			else mp[a[i]].fst++;
		}
		ll flag=1;
		if(n%2==0){
			for(auto i:mp)if(i.snd.fst!=i.snd.snd)flag=0;
		}
		else {
			ll im=0;
			for(auto i:mp){
				if(i.snd.fst%2){
					if(im)flag=0;
					else im++;
				}
				if(i.snd.snd%2){
					if(im)flag=0;
					else im++;
				}
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
