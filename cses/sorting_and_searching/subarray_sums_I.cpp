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
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll p=0,sum=0,res=0;
	fore(i,0,n){
		while(p<n&&sum<x)sum+=a[p++];
		res+=sum==x;
		sum-=a[i];
	}
	cout<<res<<"\n";
	return 0;
}
