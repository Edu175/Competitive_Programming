#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; ll p; cin>>s>>p;
		string r=s;
		ll ip=0;
		for(auto i:s)ip+=i-'a'+1;
		sort(ALL(r));
		reverse(ALL(r));
		set<char>st;
		map<char,ll>mp;
		fore(i,0,SZ(r)){
			if(ip<=p)break;
			ip-=r[i]-'a'+1;
			//cout<<ip<<" ";
			st.insert(r[i]);
			mp[r[i]]++;
		}
		//cout<<"\n";
		//imp(st);
		string res;
		for(auto i:s){
			if(st.count(i)){
				mp[i]--;
				if(mp[i]==0)st.erase(i);
			}
			else res.pb(i);
		}
		pres;
	}
	return 0;
}
