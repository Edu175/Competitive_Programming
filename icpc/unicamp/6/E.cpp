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

set<char>let;
string solve(string s, ll p){
	fore(i,p,SZ(s))if(s[i]=='.'){
		auto st=let;
		if(i)st.erase(s[i-1]);
		if(i<SZ(s)-1)st.erase(s[i+1]);
		if(SZ(st))s[i]=*st.begin();
		else s[i]='A';
	}
	return s;
}
int main(){FIN;
	ll k; cin>>k;
	string s; cin>>s;
	fore(i,0,k)let.insert('A'+i);
	ll p=0;
	fore(i,0,SZ(s))if(s[i]!='.'){p=i;break;}
	if(!p)s=solve(s,0);
	else {
		s=solve(s,p);
		reverse(ALL(s));
		s=solve(s,0);
		reverse(ALL(s));
	}
	cout<<s<<"\n";
	return 0;
}
