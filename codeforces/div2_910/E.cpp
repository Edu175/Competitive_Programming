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

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

bool mayig(vector<ll> &a, vector<ll>&b){
	fore(i,0,SZ(a))if(a[i]<b[i])return 0;
	return 1;
}

int main(){FIN;
	ll __; cin>>__;
	while(__--){
		ll n,m; cin>>n>>m;
		string s,t; cin>>s>>t;
		vector<string>a;
		string p; p.pb(t[0]);
		fore(i,1,m){
			if(t[i-1]<=t[i])p.pb(t[i]);
			else a.pb(p),p.clear(),p.pb(t[i]);
		}
		a.pb(p);
		//imp(a);
		ll k=0,l=0;
		vector<ll>v(30),c(30);
		for(auto j:a[k])v[j-'a']++;
		vector<ll>us(n);
		fore(i,0,n){
			if(k>=SZ(a))break;
			c[s[i]-'a']++;
			if(c[s[i]-'a']<=v[s[i]-'a'])us[i]=1;
			while(mayig(c,v)){
				vector<ll>d(30);
				char r=s[i];
				for(ll h=i;h>=l;h--){
					if(us[h])r=max(r,s[h]);
					if(s[h]>r)d[s[h]-'a']++;
					c[s[h]-'a']--;
				}
				ll u=a[k].back()-'a';
				fore(i,u,30)d[i]+=c[i];
				c=d;
				k++;
				if(k>=SZ(a))break;
				vector<ll>vi(30);
				for(auto j:a[k])vi[j-'a']++;
				v=vi;
				l=i+1;
				//cout<<i<<": "<<c<<"\n";
			}
			//cout<<i<<" "<<k<<": "<<c<<" "<<v<<"\n";
		}
		if(k>=SZ(a))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
