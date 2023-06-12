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

string e,s;
ll g[18][15],gt,n;
ll dp[18][18][3][3];
ll p10[18];
ll f(ll i, ll p, ll b, ll z){
	ll &res=dp[i][p][b][z];
	if(res!=-1)return res;
	if(i==SZ(e))return res=0;
	res=0;
	fore(j,0,10){
		char d='0'+j;
		if(b&&d>e[i])break;
		ll pi=g[p][j],bi=(b&&e[i]==d);
		if(!j&&!z)pi=0;
		ll add=0;
		if(pi==n){
			ll x=SZ(e)-1-i;
			if(!bi)add=p10[x];
			else if(i+1==SZ(e))add=1;
			else add=stoll(e.substr(i+1))+1;
			pi=gt;
		}
		res+=add+f(i+1,pi,bi,(z||j));
	}
	return res;
}
int main(){FIN;
	p10[0]=1;
	fore(i,1,18)p10[i]=p10[i-1]*10;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>s>>l>>r; l--;
		n=SZ(s);
		fore(i,0,n){
			fore(j,0,10){
				char d='0'+j;
				string w=s.substr(0,i);
				w.pb(d);
				ll res=0;
				fore(m,0,SZ(w)+1){
					if(w.substr(SZ(w)-m)==s.substr(0,m))res=m;
				}
				g[i][j]=res;
			}
		}
		gt=0;
		fore(i,1,n){
			if(s.substr(i)==s.substr(0,n-i)){
				gt=n-i;
				break;
			}
		}
		e=to_string(r);
		mset(dp,-1);
		ll res=f(0,0,1,0);
		e=to_string(l);
		mset(dp,-1);
		res-=f(0,0,1,0);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
