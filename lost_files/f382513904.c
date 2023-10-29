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
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	ll a[n];
	fore(i,0,n){
		a[i]=(s[i]=='Y');
	}
	vector<ll>mk(k,1);
	mk.resize(n);
	sort(ALL(mk));
	ll res=0;
	do{
		ll b[n],resi=0;
		fore(i,0,n)b[i]=a[i]^mk[i];
		fore(i,1,n)if(b[i]&&b[i-1])resi++;
		res=max(res,resi);
	}
	while(next_permutation(ALL(mk)));
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
