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
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a[3],sum=0;
		fore(i,0,3)cin>>a[i],sum+=a[i];
		ll flag=1;
		if(sum%3!=0)flag=0;
		ll m=sum/3,op0=0,op1=0;
		fore(i,0,3){
			if(abs(a[i]-m)%2)flag=0;
			if(a[i]>m)op1+=(a[i]-m)/2;
			else op0+=(m-a[i])/2;
		}
		if(!flag)cout<<"-1\n";
		else {
			//assert(op1==op0);
			cout<<op0<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
