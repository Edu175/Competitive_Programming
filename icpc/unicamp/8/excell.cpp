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

ll n,m;

string encode(ll x){
	ll k=1,pot=26;
	fore(i,1,6){
		if(x<pot){
			k=i;
			break;
		}
		x-=pot;
		pot*=26;
	}
	string s(k,'A');
	fore(i,0,k)s[i]='A'+x%26,x/=26;
	reverse(ALL(s));
	return s;
}

ll decode(string s){
	ll k=SZ(s);
	ll x=0,pot=26;
	fore(i,1,k)x+=pot,pot*=26;
	pot=1;
	reverse(ALL(s));
	fore(i,0,k)x+=(s[i]-'A')*pot,pot*=26;
	return x;
}

int main(){FIN;
	cin>>n>>m;
	ll q; cin>>q;
	while(q--){
		string s; cin>>s;
		if(s[0]>='0'&&s[0]<='9'){
			ll x=stoll(s); x--;
			ll i=x/m,j=x%m;
			string w=encode(j);
			cout<<w<<i+1<<"\n";
		}
		else {
			string w,nu;
			for(auto i:s){
				if(i<='9'&&i>='0')nu.pb(i);
				else w.pb(i);
			}
			ll x=stoll(nu);
			ll i=x-1,j=decode(w);
			cout<<m*i+j+1<<"\n";
		}
	}
	
	return 0;
}
