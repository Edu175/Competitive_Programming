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
		ll a[n];
		ll pos=0;
		set<ll>st;
		fore(h,1,n){
			while(st.count(h)==1)h++;
			ll j=h;
				if(h>n||pos>=n){
					break;
				}
			fore(i,pos,n){
				if(j>n){
					pos=i;
					break;
				}
				a[i]=j;
				st.insert(j);
				//cout<<j;
				j*=2;
			}
		}
		cout<<2<<"\n";
		imp(a);
		/*cout<<"\n"<<pos;
		for(ll i=pos,j=1;i<n&&j<=n;i++,j++){
			while(st.count(j)==1)j++;
			a[i]=j;
			cout<<"for"<<j;
		}
		cout<<"\n"<<2<<"\n";
		imp(a);*/
	}
	return 0;
}
