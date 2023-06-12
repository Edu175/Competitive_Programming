#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
int can(ll x){
	cout<<x<<endl;
	string y; cin>>y;
	if(y==">=")return 1;
	else return 0;
}

int main(){FIN;
	ll l=1,r=1000000;
	while(l <= r) {
 		ll m = (l+r)/2;
 		if (can(m)) l=m+1;
  		else r=m-1;
	}
	cout<<"! "<<r;
	 return 0;
}
