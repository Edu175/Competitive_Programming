#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll tipo(char a){
	if(a>='A'&&a<='Z')return 1;
	if(a>='a'&&a<='z')return 0;
	return -1;
}

bool good(string s){
	if(SZ(s)==1)return 0;
	ll fg=tipo(s[0])==1;
	fore(i,1,SZ(s))fg&=tipo(s[i])==0;
	return fg;
}
void abbr(vector<string>a){
	if(SZ(a)==1){
		cout<<a[0];
		return;
	}
	for(auto j:a)cout<<j[0];
	cout<<" (";
	fore(i,0,SZ(a)){
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<")";
}
int main(){
    JET
    #ifdef ONLINE_JUDGE
    freopen("abbreviation.in","r",stdin);     freopen("abbreviation.out","w",stdout);
    #endif
	string s;
	// ll dbg=7;
	while(1){
		s="";
		getline(cin,s);
		// cerr<<"lei "<<s<<"\n";
		if(s=="")break;
		s.pb('.');
		// cin.ignore();
		// vector<string> ws;
		// string w;
		// for(auto i:s){
		// 	if(tipo(i)==-1){
		// 		if(SZ(w))ws.pb(w);
		// 		if(i!=' '){
		// 			if(SZ(ws)){ // escribo la abreviacion
		// 				cout<<"(";
		// 				for(auto j:ws)cout<<j[0];
		// 				cout<<")";
		// 			}
					
		// 		}
		// 	}
		// }
		
		vector<string>dat; // separado por no letras
		string tmp;
		for(auto i:s){
			if(tipo(i)==-1){
				if(SZ(tmp))dat.pb(tmp),tmp.clear();
				dat.pb(string(1,i));
			}
			else tmp.pb(i);
		}
		// cout<<tmp<<endl;
		assert(!SZ(tmp));
		vector<string>ws;
		fore(i,0,SZ(dat)){
			assert(SZ(dat[i]));
			if(good(dat[i]))ws.pb(dat[i]);
			else if(dat[i]==" "&&i&&good(dat[i-1])&&good(dat[i+1]));
			else {
				if(SZ(ws))abbr(ws),ws.clear();
				if(i!=SZ(dat)-1)cout<<dat[i];
			}
		}
		cout<<"\n";
		// cout<<"termino linea\n";
		// break;
	}
    return 0;
}