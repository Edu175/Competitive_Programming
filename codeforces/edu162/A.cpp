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

ll is(vector<ll>a){
	ll c=0;
	fore(i,0,SZ(a))if(a[i]&&(!i||!a[i-1]))c++;
	return c<=1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		while(!is(a)){
			res++;
			ll p=-1;
			for(ll i=n-1;i>=0;i--){
				if(a[i]&&p==-1)p=i;
				if(!a[i]&&p!=-1){
					swap(a[i],a[p]);
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
