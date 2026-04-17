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
	freopen("holes.in","r",stdin);     freopen("holes.out","w",stdout);
	#endif
	JET
	string s;
	map<ll,ll> mp;
	vector<vector<string>> words;
	int k=0;
	while(getline(cin,s)){
		cin.ignore();
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
			}
		}
		if(aux!=""){
			mp[SZ(line)] = max(mp[SZ(line)],SZ(aux));
			line.pb(aux);
			aux="";
		}
		words.pb(line);
	}
	fore(i,0,SZ(words)){
		fore(j,0,SZ(words[i])){
			cout<<words[i][j];
		}
		fore(j,0,mp[i]-SZ(words[i])) cout<<" ";
		cout<<" ";
	}
	return 0;
}