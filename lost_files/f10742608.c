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
	fore(k,1,n+1){
		if(k<=3){
			if(k==1)cout<<0<<"\n";
			if(k==2)cout<<6<<"\n";
			if(k==3)cout<<28<<"\n";
			continue;
		}
		ll res=0;
		res+=(k*k-3)*4;
		res+=(k*k-4)*8;
		res+=(k*k-5)*4;
		res+=(k*k-5)*(k-4)*4;
		res+=(k*k-7)*(k-4)*4;
		res+=(k*k-9)*(k-4)*(k-4);
		res/=2;
		pres;
	}
	return 0;
}
