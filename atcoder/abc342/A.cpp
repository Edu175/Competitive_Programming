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

int main(){FIN;
		vector<ll>c(32);
		string s; cin>>s;
		for(auto i:s)c[i-'a']++;
		ll res=-1;
		fore(i,0,SZ(s))if(c[s[i]-'a']==1)res=i;
		cout<<res+1<<"\n";
	return 0;
}
