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

string f(string s, ll k){
	reverse(ALL(s));
	ll p=0;
	fore(i,0,k){
		while(p<SZ(s)&&s[p]=='1')p++;
		if(p<SZ(p))s[p]='1';
		else s.pb(1);
	}
	while(s.back()==0)s.pop_back();
	reverse(ALL(s));
	return s;
}
string greedy(string s, ll k){
	ll _k=k;
	fore(i,0,n)if(k){
		if(s[i]=='1')s[i]='0',k--;
	}
	return f(s,k);
}
string doit(string s, ll k){
	ll n=SZ(s);
	vector<ll>pre(n+5,0),suf(n+5,0);
	ll c=0;
	fore(i,0,n){
		c+=s[i]-'0';
		pre[c]=i+1;
	}
	c=0;
	ll mx=0,l,r;
	for(ll i=n-1;i>=0;i--){
		c+=s[i]-'0';
		ll resi=n-i+pre[k-c];
		if(resi>)
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
