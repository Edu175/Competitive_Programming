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
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		ll cnt=1;
		fore(i,0,k){
			if(i%2==0)for(ll j=i;j<n;j+=k)a[j]=cnt++;
			else {
				ll q=(n-i+k-1)/k;
				for(ll j=i,c=cnt+q-1;j<n;j+=k)a[j]=c--;
				cnt+=q;
			}
		}
		imp(a);
	}
	return 0;
}
