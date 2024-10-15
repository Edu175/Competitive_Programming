#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<string>
out={"LI","+I","+-","=-"},
put={"IL","I+","-+","-="},
both={"I-","-I","L+","+L","=+","+=","VX","XV"};

set<string> all;
string sacar(string s, ll i, ll ty){
	auto t=out[ty];
	if(s[i]!=t[0])return "";
	s[i]=t[1];
	return s;
}
string poner(string s, ll i, ll ty){ // a tu vieja se la puse
	auto t=put[ty];
	if(s[i]!=t[0])return "";
	s[i]=t[1];
	return s;
}
string reponer(string s, ll i, ll ty){
	auto t=both[ty];
	if(s[i]!=t[0])return "";
	s[i]=t[1];
	return s;
}
string poner_entre(string s, ll i, ll ty){ // antes del iesimo
	string r;
	fore(j,0,i)r.pb(s[i]);
	r.pb(ty?'I':'-');
	fore(j,i,SZ(s))r.pb(s[i]);
	return r;
}

bool check(string s){
	if(count(ALL(s),'=')!=1)return 0;
	string l,r;
	ll flag=1,did=0;
	fore(i,0,SZ(s)){
		if(s[i]=='=')did=1;
		(did?r:l).pb(s[i]);
	}
	auto num=[&](string s){
		vector<string> t={""},sig;
		fore(i,0,SZ(s)){
			auto &c=s[i];
			if(c=='+'||c=='-'){
				
			}
		}
	};
}

int main(){
	JET
	
	return 0;
}
