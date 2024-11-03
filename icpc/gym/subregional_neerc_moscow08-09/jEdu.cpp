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
out={"LI","+I","+-","=-","pingo"},
put={"IL","I+","-+","-="},
both={"I-","-I","L+","+L","=+","+=","VX","XV"};

string sacar(string s, ll i, ll ty){
	auto t=out[ty];
	if(t=="pingo"){
		if(s[i]!='I'&&s[i]!='-')return "";
		s.erase(s.begin()+i);
		return s;
	}
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
	fore(j,0,i)r.pb(s[j]);
	r.pb(ty?'I':'-');
	fore(j,i,SZ(s))r.pb(s[j]);
	return r;
}
string cars="IVXL";
vv values={1,5,10,50};
map<char,ll>ord;

ll maxcon(string s){ // max consecutive equal chars
	ll res=0,q=1;
	fore(i,1,SZ(s)){
		if(s[i]==s[i-1])q++;
		else res=max(res,q),q=1;
	}
	res=max(res,q);
	return res;
}

bool valid(string s){
	if(count(ALL(s),'=')!=1)return 0;
	string l,r;
	ll flag=1,did=0;
	fore(i,0,SZ(s)){
		if(s[i]=='=')did=1;
		else (did?r:l).pb(s[i]);
	}
	auto num=[&](string s)->ll{
		// cout<<flag<<" flag\n";
		// cout<<"num "<<s<<" -->\n";
		ll n=SZ(s);
		if(!n||maxcon(s)>3||count(ALL(s),'L')>1||count(ALL(s),'V')>1)
			{flag=0;return 0;}
		string t;
		fore(i,0,n){
			if(i==n-1)t.pb(s[i]);
			else {
				auto sub=s.substr(i,2);
				if(sub=="XL")t+="XXXX",i++;
				else if(sub=="IX")t+="VIIII",i++;
				else if(sub=="IV")t+="IIII",i++;
				else t.pb(s[i]);
			}
		}
		s=t; n=SZ(s);
		if(maxcon(s)>4||count(ALL(s),'V')>1){flag=0;return 0;}
		ll res=0;
		fore(i,0,n){
			if(i<n-1)flag&=ord[s[i]]>=ord[s[i+1]];
			res+=values[ord[s[i]]];
		}
		// cout<<"num "<<s<<": "<<res<<": "<<flag<<"\n";
		return res;
	};
	auto val=[&](string s){
		s.pb('+');
		ll res=0,n=SZ(s);
		string p;
		char sig='+';
		fore(i,0,n){
			if(s[i]=='+'||s[i]=='-'){
				res+=(sig=='+'?1:-1)*num(p);
				sig=s[i];
				p.clear();
			}
			else p.pb(s[i]);
		}
		return res;
	};
	ll lhs=val(l),rhs=val(r);
	// cout<<l<<" , "<<r<<": "<<lhs<<" , "<<rhs<<": "<<flag<<"\n";
	return flag&&(lhs==rhs);
}

set<string> all;
void proba(string s){
	// cout<<"proba "<<s<<"\n";
	if(valid(s))all.insert(s);
}
int main(){
	JET
	fore(i,0,SZ(cars))ord[cars[i]]=i;
	string s; cin>>s;
	// cout<<valid(s)<<"\n";
	// return 0;
	ll n=SZ(s);
	fore(i,0,n){
		fore(ty,0,SZ(out)){
			auto t=sacar(s,i,ty);
			// cout<<"\nsacar "<<i<<" "<<ty<<": "<<t<<"\n";
			fore(j,0,SZ(t)){
				fore(ty,0,SZ(put)){
					// cout<<"poner "<<j<<" "<<ty<<"\n";
					auto f=poner(t,j,ty);
					proba(f);
				}
			}
			fore(j,0,SZ(t)+1){
				fore(ty,0,2){
					// cout<<"poner entre "<<j<<" "<<ty<<"\n";
					auto f=poner_entre(t,j,ty);
					proba(f);
				}
			}
		}
	}
	fore(i,0,n){
		// cout<<"reponer "<<i<<"\n";
		fore(ty,0,SZ(both)){
			auto f=reponer(s,i,ty);
			proba(f);
		}
	}
	for(auto i:all)cout<<i<<"\n";
	return 0;
}
