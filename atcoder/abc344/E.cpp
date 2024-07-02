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
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	map<ll,ll>L,R;
	R[0]=a[0];
	fore(i,0,n){
		if(i)L[a[i]]=a[i-1];
		if(i<n-1)R[a[i]]=a[i+1];
	}
	L[0]=a[n-1];
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,y; cin>>x>>y;
			L[R[x]]=y;
			R[y]=R[x];
			L[y]=x;
			R[x]=y;
		}
		else {
			ll x; cin>>x;
			R[L[x]]=R[x];
			L[R[x]]=L[x];
			L[x]=R[x]=0;
		}
	}
	ll x=R[0];
	while(x){
		cout<<x<<" ";
		x=R[x];
	}
	cout<<"\n";
	return 0;
}
