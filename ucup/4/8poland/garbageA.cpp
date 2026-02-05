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
	ll c=0;
	while(n%5==0)n/=5,c++;
	ll x=0,y=0;
	fore(i,1,c+1)if(c%i==0){
		ll a=i,b=c/i;
		if(x==0||(a+b)<x+y)x=a,y=b;
	}
	cout<<n<<" "<<c<<": ";
	cout<<x<<" "<<y<<endl;
	while(x+y>n){
		n*=5;
		x>y?x--:y--;
	}
	fore(i,0,x)cout<<"A";
	fore(i,0,y)cout<<"I";
	n-=(x+y); assert(n>=0);
	fore(i,0,n)cout<<"X";
	cout<<"\n";
	return 0;
}
