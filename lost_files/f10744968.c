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
	cin.open("input.txt", ios::in);
	cout.open("output.txt", ios::out);	
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		string s; cin>>s;
		ll n=SZ(s);
		map<char,set<char>>ch;
		ll k; cin>>k;
		fore(i,0,k){
			string si; cin>>si;
			ch[si[0]].insert(si[1]);
		}
		ll res=-1;
		for(char i='A'; i<='Z'; i++){
			ll resi=0;
			fore(j,0,n){
				if(s[j]!=i){
					if(ch[s[j]].count(i)){
						resi++;
					}
					else{
						resi=-1;
						break;
					}
				}
			}
			res=max(res,resi);
		}
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
