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
	ll n,k; cin>>n>>k;
	ll a[n], r[n];
	ll m=n/2;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	fore(i,0,n){
		if(i>m)r[i-m]=a[i]-a[m];
	}
	ll res=0;
	ll flag=0;
	fore(i,1,n-m){
		if(k/i>r[i])res=r[i];
		else{
			res+=k/i;
			flag=1;
			break;
		}
	}
	if(!flag)res+=k/(n-m);
	res+=a[m];
	pres;
	return 0;
}
