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
string merge(ll p,char c,ll q){
	string l,r;
	fore(i,0,p)l.pb(res[i]);
	fore(i,p,SZ(res))r.pb(res[i]);
	string m(q,c);
	return l+m+r;
}
string secuenciar(int N, string s){
	n=N;
	if(s=="AC"){
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			string cad(m,s[0]);
			if(medir(cad))l=m+1;
			else r=m-1;
		}
		string a(r,s[0]),b(n-r,s[1]);
		return a+b;
	}
	//cout<<n<<"\n";
	ll k=0;
	for(auto c:s){
		//cout<<c<<":\n";
		if(k==n)break;
		vector<ll>upd;
		fore(i,0,SZ(res)+1){
			if(k==n)break;
			ll l=1,r=n-k;
			while(l<=r){
				ll m=(l+r)/2;
				if(medir(merge(i,c,m)))l=m+1;
				else r=m-1;
			}
			upd.pb(r);
			k+=r;
			//cout<<i<<": "<<r<<" "<<res<<"\n";
		}
		ll d=0;
		fore(i,0,SZ(upd))res=merge(i+d,c,upd[i]),d+=upd[i];
	}
    return res;
}
