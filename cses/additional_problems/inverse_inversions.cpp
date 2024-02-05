#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n,-1);
	ll s=n;
	fore(i,0,n){
		if(k==0){
			s=i;
			break;
		}
		ll p=min(k,n-1-i);
		//cout<<i<<" "<<k<<": "<<p<<endl;
		a[p]=i;
		k-=p;
	}
	fore(i,0,n){
		if(a[i]==-1)a[i]=s++;
	}
	for(auto i:a)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
