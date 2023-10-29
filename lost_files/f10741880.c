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
#define PI 3.141592653589793238462643383279502884197175105820974944592307816
using namespace std;
typedef double ll;

int main(){FIN;
	ll b,h; cin>>b>>h;
	ll G=b/h;
	cout<<fixed<<setprecision(15)<<asin(b/h)*180/PI<<"\n";
	return 0;
}
