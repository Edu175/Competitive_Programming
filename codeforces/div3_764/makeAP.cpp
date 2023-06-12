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

int canap(ll x,ll y,ll z){
	if((abs(x-y)+max(x,y))%z==0)return 1;
	else return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
	ll a,b,c; cin>>a>>b>>c;
	/*if(a>b&&a>c){
		cout<<"NO\n";
		continue;
	}*/
	if(canap(a,b,c)||canap(a,c,b)||canap(b,c,a))cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
	}
	 return 0;
}

