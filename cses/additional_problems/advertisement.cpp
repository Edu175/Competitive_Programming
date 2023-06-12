#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ll> fme(vector<ll>&a){ //index of first minor element to the left (-1 if none)
	ll n=SZ(a);
	vector<ll>f(n,-1);
	fore(i,0,n){
		ll x=i-1;
		for(;x!=-1&&!(a[x]<a[i]);x=f[x],f[i]=x);
		f[i]=x;
	}
	return f;
}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>l=fme(a);
	reverse(ALL(a));
	vector<ll>r=fme(a);
	fore(i,0,n)r[i]=n-1-r[i]; //reverse indexes
	reverse(ALL(r)); //reverse answers
	reverse(ALL(a));
	ll res=0;
	vector<ll>add;
	fore(i,0,n){ //(l,r)
		res=max(res,(r[i]-l[i]-1)*a[i]);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
