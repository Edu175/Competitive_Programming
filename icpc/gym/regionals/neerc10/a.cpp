#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	#ifdef ONLINE_JUDGE
	freopen("alignment.in","r",stdin);     freopen("alignment.out","w",stdout);
	#endif
	JET
	string s;
	map<ll,ll> mp;
	vector<vector<string>> words;
	while(getline(cin,s)){
		// cout<<s<<"\n";
		string aux = "";
		bool st=false;
		vector<string> line;
		fore(i,0,SZ(s)){
			if(s[i]==' ' && !st) continue;
			if(s[i]==' ' && aux!=""){
				mp[SZ(line)] = max(mp[SZ(line)],SZ(aux));
				line.pb(aux);
				aux="";
			}
			if(s[i]!=' '){
				aux.pb(s[i]);
				st=true;
			}
		}
		if(aux!=""){
			mp[SZ(line)] = max(mp[SZ(line)],SZ(aux));
			line.pb(aux);
			aux="";
		}
		words.pb(line);
		// cout<<" line ";
		// fore(i,0,SZ(line)) cout<<line[i]<<" ";
		// cout<<"\n";
	}
	fore(i,0,SZ(words)){
		fore(j,0,SZ(words[i])){
			cout<<words[i][j];
			if(j<SZ(words[i])-1){
				fore(k,0,mp[j]-SZ(words[i][j])) cout<<" ";
				// cout<<mp[j]-SZ(words[i][j]);
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}
// sdkjfdskjhf

/*


  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;   
c:   char; // temp 


out:
start: integer; // begins here 
stop:  integer; // ends   here 
s:     string;  
c:     char;    // temp



*/