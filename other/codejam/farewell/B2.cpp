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

vector<string>flecha={"-->","<--"};
int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n,q; cin>>n>>q;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll p=0;
		set<ll>bag;
		//cout<<"\n";
		while(q--){
			ll x; cin>>x;
			ll res=0;
			ll l=p,r=p+x; if(l>r)swap(l,r);
			/*cout<<l<<" "<<r<<" "<<flecha[(x<0)]<<" : { ";
			for(auto i:bag)cout<<i<<" ";
			cout<<"} ";*/
			fore(i,0,n){
				if(b[i]>=l&&b[i]<=r){
					if(bag.count(i))bag.erase(i),res++;
					else if(l<=a[i]&&a[i]<=r){
						if(x<0){
							if(a[i]>=b[i])res++;
							else bag.insert(i);
						}
						else {
							if(a[i]<b[i])res++;
							else bag.insert(i);
						}
						a[i]=-1;
					}
				}
				if(a[i]!=-1&&a[i]>=l&&a[i]<=r)bag.insert(i),a[i]=-1;
			}
			p+=x;
			cout<<res<<" ";
			//cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
// NO FAREWELL: KEEP GOOGLE COMPETITIONS ALIVE
