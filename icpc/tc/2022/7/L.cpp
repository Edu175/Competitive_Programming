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
	ll n; cin>>n;
	ll a[n], b[n];
	fore(i,0,n){
		cin>>a[i]>>b[i];
	}
	ll g=b[0];
	fore(i,1,n){
		g=gcd(g,b[i]);
	}
	//cout<<g<<"\n";
	ll m=a[0];
	fore(i,1,n){
		m=(m*a[i])/gcd(m,a[i]);
	}
	//cout<<m<<"\n";
	fore(i,2,sqrt(min(m,g))+1){
		while(m%i==0&&g%i==0){
			m/=i;
			g/=i;
		}
	}
	cout<<m<<" "<<g;
	return 0;
}
