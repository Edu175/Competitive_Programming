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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	
int main(){FIN;
	ll n,m; cin>>n>>m;
	char b[n][m];
	ll a[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>b[i][j],a[i][j]=b[i][j]-'0';
	}
	ll mini=0,maxi=0;
	fore(i,0,n){
		ll s=m/2,d=m/4,minp=0,maxp=0;
		ll c=0; fore(j,0,m)c+=a[i][j];
		fore(j,0,m-1){ // not 11 = 01 10 00 together
			if(!(a[i][j]&&a[i][j+1])&&d)d--,j++;
		}
		maxp=c-d;
		s=m/2,d=m/4;
		fore(j,0,m-1){ // min 11
			if(a[i][j]&&a[i][j+1]&&d)d--,j++;
		}
		minp=c-(m/4-d);
		mini+=minp;
		maxi+=maxp;
	}
	cout<<mini<<" "<<maxi<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
