#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

bool is_pali(string s){
	string t=s;
	reverse(ALL(t));
	return (s==t);
}

int  prueba( string s )
{
    ll n=SZ(s);
    ll pre=0,suf=0;
    string si;
    fore(i,0,n){
    	si.pb(s[i]);
    	if(is_pali(si))pre=i+1;
    }
    si.clear();
    for(ll i=n-1;i>=0;i--){
    	si.pb(s[i]);
    	if(is_pali(si))suf=n-i;
    }
    return min(n-pre,n-suf);
}
