#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=1e9+7;
int main(){
	JET
	ll n; cin>>n;
	if(n<9) cout<<n<<"\n";
	else{
		if(!(n&1)) cout<<(n/2)%mod<<"\n";
		else{
			if(n==11) cout<<4<<"\n";
			else if(n==13) cout<<5<<"\n";
			else if(n==15) cout<<6<<"\n";
			else if(n==17) cout<<8<<"\n";
			else{
				ll m=0;
				if(n%5!=4) m=max(((n%5)+(n%5!=2)+((n)/5)),m);
				if(n%7<2) m=max((n%7)+n/7,m);
				if(n%7==3) m=max(m,1+(n/7));
				if(n%7>3) m=max(m,2+(n/7));
				if(n%4==3) m=max(m,1+(n/4));
				if(n%6==5) m=max(m,2+(n/6));
				if(n%6<5) m=max(m,1+(n/6));
				assert(n>=11);
				m=max(m,1+((n-11)/2));
				m=max(m,8+(n-8)/10);
				cout<<m%mod<<"\n";
			}
		}
	}
	return 0;
}