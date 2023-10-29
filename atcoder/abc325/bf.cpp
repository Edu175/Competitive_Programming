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
const ll MAXN=305;

map<string,ll>dp;
ll k;

ll f(string s){
	if(dp.count(s))return dp[s];
	ll &res=dp[s];
	res=SZ(s);
	fore(i,0,SZ(s)-1){
		if(s[i]=='o'&&s[i+1]=='f'){
			fore(j,0,k+1){
				if(i+2+j>SZ(s))break;
				string t;
				fore(h,0,SZ(s))if(h<i||h>=i+2+j)t.pb(s[h]);
				res=min(res,f(t));
			}
		}
	}
	return res;
}

int main(){FIN;
	string s;
	cin>>s>>k;
	cout<<f(s)<<"\n";
	return 0;
}
