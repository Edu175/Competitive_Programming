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
	string l;
	getline(cin,l);
	ll n,s=0,sz=SZ(l); cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		if(s<x)s=x-1-s;
		else s=sz-1-(s-x);
		//cout<<s<<" ";
	}
	string res(sz,' ');
	if(n%2)s=sz-1-s;
	fore(i,0,sz){
		res[i]=l[(i-s+sz)%sz];
	}
	if(n%2)reverse(ALL(res));
	pres;
	return 0;
}
