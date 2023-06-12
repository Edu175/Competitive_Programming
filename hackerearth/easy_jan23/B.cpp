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
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
int main(){FIN;
	string a; cin>>a;
	ll sum=0,p=-1;
	fore(i,0,SZ(a)){
		if(a[i]!='X')sum+=a[i]-'0';
		else {
			if(p==-1)a[i]='9';
			p=i;
		}
	}
	sum%=9;
	ll x=6-sum,y=3-sum;
	if(x<=0)x+=9;
	if(y<=0)y+=9;
	a[p]='0'+(max(x,y));
	cout<<a<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
