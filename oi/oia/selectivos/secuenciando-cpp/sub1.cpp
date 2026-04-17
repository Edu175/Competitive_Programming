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

int medir(string cad);
ll n;
string res;
string secuenciar(int N, string s){
	n=N;
	char c='A';
	ll l=1,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		string cad(m,c);
		if(medir(cad))l=m+1;
		else r=m-1;
	}
	string a(r,c),b(n-r,'C');
    return a+b;
}
