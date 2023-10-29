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
	ll n; cin>>n;
	string s,t; cin>>s>>t;
	ll a[n],b[n];
	fore(i,0,n)a[i]=s[i]-'0',b[i]=t[i]-'0';
	ll h=0;
	fore(i,0,n)h+=(a[i]^b[i]);
	if(h&1){
		cout<<"-1\n";
		return 0;
	}
	ll res[n];
	mset(res,0);
	ll p[2]={0,0};
	fore(i,0,n){
		if((a[i]^b[i])==0)continue;
		ll who=0;
		if(b[i]==1)who=1;
		if(p[who]<h/2)p[who]++;
		else res[i]=1,p[who^1]++;
	}
	for(auto i:res)cout<<i;
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
