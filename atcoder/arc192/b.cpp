#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	if(n==1){
		cout<<"Fennec\n";
		return 0;
	}
	ll sum=0;
	vv c(2);
	ll busca=0; // A
	fore(i,0,n){
		ll x; cin>>x; x--;
		c[x&1]++;
		sum+=x;
	}
	if(n%2==0)busca=1;
	if(sum&1)busca^=1;
	cerr<<"busca "<<busca<<"\n";
	char wins='.';
	if(n==2)wins=sum%2==busca?'A':'B';
	else if(abs(c[0]-c[1])>=2){
		if(!busca)wins='A';
		else wins='B';
	}
	else {
		if(n%2==0){
			assert(c[0]==c[1]);
			// if(!busca)wins='B';
			wins=c[0]%2==0?'B':'A';
		}
		else {
			// wins='A';
			ll mn=min(c[0],c[1]);
			if(!busca)wins='A';
			// else wins=mn%2==0?'A':'B'; // no
			// else wins=mn%2==0?'B':'A'; // no
			else if(n==3)wins='A';
			else wins='B'; // no
			
		}
	}
	if(wins=='A')cout<<"Fennec\n";
	else cout<<"Snuke\n";
	return 0;
}
