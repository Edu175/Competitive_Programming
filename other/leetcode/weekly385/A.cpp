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

bool f(string a, string b){
	if(SZ(a)>SZ(b))return 0;
	string p,s;
	fore(i,0,SZ(a))p.pb(b[i]);
	fore(i,SZ(b)-SZ(a),SZ(b))s.pb(b[i]);
	return a==p&&a==s;
}

int countPrefixSuffixPairs(vector<string>& a) {
	ll res=0;
	fore(i,0,SZ(a))fore(j,i+1,SZ(a))res+=f(a[i],a[j]);
	return res;
}
