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
const ll MAXN=2e5+5;

ll n,c,d;
ll a[MAXN],sp[MAXN];

bool solve(ll k){
	ll sum=sp[min(n,k+1)]*(d/(k+1));
	sum+=sp[min(n,d%(k+1))];
	return (sum>=c);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>c>>d;
		fore(i,0,n)cin>>a[i];
		sp[0]=0;
		sort(a,a+n);
		reverse(a,a+n);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll l=0,r=MAXN;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(m))l=m+1;
			else r=m-1;
		}
		if(r<0)cout<<"Impossible\n";
		else if(l>MAXN)cout<<"Infinity\n";
		else cout<<r<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
