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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<ll>h(30);
		ll n=SZ(s);
		ll q=0,br=0;
		for(auto i:s)q+=(h[i-'a']==0),h[i-'a']++;
		sort(ALL(s));
		string res(n,'$');
		fore(i,0,n/2){
			fore(c,0,30){
				if(!h[c])continue;
				if(h[c]>=2){
					res[i]='a'+c,res[n-1-i]='a'+c;
					h[c]-=2;
					q-=(!h[c]);
					break;
				}
				h[c]--; q-=(!h[c]);
				if(q>1)res[n-1-i]='a'+c;
				else res[n/2]='a'+c;
				br=1;
				break;
			}
			if(br)break;
		}
		vector<ll>v;
		fore(i,0,30)while(h[i]--)v.pb(i);
		ll j=0;
		fore(i,0,n)if(res[i]=='$'){
			res[i]='a'+v[j];
			j++;
		}
		//cout<<s<<": ";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
