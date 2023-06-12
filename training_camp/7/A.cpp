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
typedef long double ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll m=ll(1)/ll(4);
		ll tr=a*a*m/2;
		if(a*m>b)tr=a*b-b*b*2;//,cout<<"se pasa ";
		ll mitad=a*b;
		ll res=(tr+mitad)/(2*b*a);
		if(a==0)res=ll(1)/ll(2);
		if(b==0)res=1;
		cout<<fixed<<setprecision(15)<</*mitad<<'+'<<tr<<" "<<*/res<<"\n";
	}
	return 0;
}
