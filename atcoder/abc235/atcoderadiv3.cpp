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
ll edu(ll a,ll b,ll c){
	return a*100+b*10+c;
}
int main(){FIN;
	ll A;
	cin>>A;
	ll a=A/100,c=A%10,b=A%100/10;
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	cout<<edu(a,b,c)+edu(b,c,a)+edu(c,a,b);
	return 0;
}
