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
typedef long long ll;

int main(){FIN;
	ll x,y,z; cin>>x>>y>>z;
	ll a,b,c; cin>>a>>b>>c;
	ll flag=1;
	a-=x;
	if(a<0)flag=0;
	b+=a;
	b-=y;
	if(b<0)flag=0;
	c+=b;
	c-=z;
	if(c<0)flag=0;
	if (flag)cout<<"YES";
	else cout<<"NO";
	return 0;
}
//Sən məğlub oldun
