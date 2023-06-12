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
	ll k; cin>>k;
	string s; cin>>s;
	map<char,ll>oc;
	char f=s[0];
	ll diff=1;
	set<ll>pos;
	fore(i,0,SZ(s)){
		if(s[i]!=f&&!oc[s[i]])diff++,pos.insert(i);
		oc[s[i]]++;
	}
	//imp(pos);
	ll c=1;
	if(diff>=k){
		cout<<"YES\n";
		fore(i,0,SZ(s)){
			if(c<k&&pos.count(i))c++,cout<<"\n";
			cout<<s[i];
		}
	}
	else cout<<"NO";
	return 0;
}
