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

ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string a; cin>>a;
		ll n=SZ(a);
		ll x=-1,c=-1;
		fore(i,0,n)if(x==-1&&a[i]=='0')x=i;
		for(ll i=n-1;i>=0;i--)if(c==-1&&a[i]=='0')c=n-1-i;
		if(x==-1){
			cout<<n*n<<"\n";
			continue;
		}
		ll res=0;
		if(c+x+1)res=max(res,fqrt(c+x+1)*(c+x+1-fqrt(c+x+1)));
		x=0;
		fore(i,0,n){
			if(a[i]=='1')x++;
			else {
				if(x)res=max(res,fqrt(x+1)*(x+1-fqrt(x+1)));
				x=0;
			}
		}
		if(x)res=max(res,fqrt(x+1)*(x+1-fqrt(x+1)));
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
