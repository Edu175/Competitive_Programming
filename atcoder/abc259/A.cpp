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
	ll n,m,x,t,d; cin>>n>>m>>x>>t>>d;
	ll a[n+1];
	a[n]=t;
	for(ll i=n-1; i>=0; i--){
		a[i]=a[i+1];
		if(i<x)a[i]-=d;
	}
	//imp(a);
	cout<<a[m]<<"\n";
	return 0;
}
