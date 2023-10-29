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
	ifstream cin;
	cin.open("words.txt", ios::in);
	vector<string>v;
	fore(i,0,2309){
		string s;cin>>s;
		set<char>st;
		for(auto i:s)st.insert(i);
		if(SZ(st)==5)v.pb(s);
	}
	
	
	return 0;
}
