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

int main(){//FIN;
	string s; cin>>s;
	ll n=SZ(s);
	vector<ll> a(n);
	//cout<<"a\n";
	fore(i,0,n)a[i]=s[i]-'0';
	//imp(a);
	//cout<<"sp\n";
	ll sp[n+1][10]; mset(sp,0);
	vector<ll>c(1ll<<11);
	c[0]++;
	//cout<<"c sp\n";
	fore(i,1,n+1){
		ll x=0;
		fore(j,0,10)sp[i][j]=sp[i-1][j];//,cout<<j<<"s ";
		//cout<<"\n"<<a[i-1]<<"\n";
		sp[i][a[i-1]]^=1;
		fore(j,0,10)x|=sp[i][j]<<j;//,cout<<j<<"x ";
		//cout<<"\n"<<x<<"\n";
		c[x]++;
	}
	//cout<<"res\n";
	ll res=0;
	for(auto i:c)res+=i*(i-1)/2;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
