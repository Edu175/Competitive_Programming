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
	ll n,c; cin>>n>>c;
	ll m=2*n-1;
	ll a[m];
	ll odd[n-1];
	ll add=0;
	fore(i,0,m){
		cin>>a[i];
		if(i%2==0)a[i]=min(c,a[i]);
	}
	for(int i=1,j=0;i<m;i+=2,j++){
		ll sum=a[i-1]+a[i+1];
		odd[j]=min(c-sum,a[i]);
		if(j)odd[j]-=odd[j-1];
		odd[j]=max(ll(0),odd[j]);
		add+=odd[j];
	}
	ll res=add;
	imp(odd);
	for(int i=0;i<m;i+=2){
		res+=a[i];
	}
	pres;
	return 0;
}
