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
	ifstream cin;
	ofstream cout;
	cin.open("input.txt",ios::in);
	cout.open("output.txt",ios::out);
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		string s; cin>>s;
		ll n=SZ(s);
		ll con=0,vow=0;
		map<char,ll> vwoc, cnoc;
		ll maxc=0,maxv=0;
		fore(i,0,n){
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
				vow++;
				vwoc[s[i]]++;
				maxv=max(maxv,vwoc[s[i]]);
			}
			else {
				con++;
				cnoc[s[i]]++;
				maxc=max(maxc,cnoc[s[i]]);
			}
		}
		cout<<min(con+2*vow-2*maxv,vow+2*con-2*maxc)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
