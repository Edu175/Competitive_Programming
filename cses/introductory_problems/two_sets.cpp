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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	if(n%4==1||n%4==2){
		cout<<"NO\n";
		return 0;
	}
	vector<ll>r1,r2;
	if(n%4==3)r1.pb(n),n--;
	fore(i,0,n/4)r1.pb(i+1),r1.pb(n-i);
	fore(i,n/4,n/2)r2.pb(i+1),r2.pb(n-i);
	cout<<"YES\n";
	cout<<SZ(r1)<<"\n";
	imp(r1);
	cout<<SZ(r2)<<"\n";
	imp(r2);
	return 0;
}
