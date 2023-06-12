#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin,x.end
#define SZ(x)((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("rapigrama.in", ios::in);
	cout.open("rapigrama.out", ios::out);
	ll n,p; cin>>n>>p;
	set<string>st;
	map<string,vector<ll>>pos;
	vector<char> res(p,'F');
	char a[n][n];
	fore(i,0,n){
		fore(j,0,n)cin>>a[i][j];
	}
	fore(i,0,p){
		string s; cin>>s;
		st.insert(s);
		pos[s].pb(i);
	}
	fore(i,0,n){
		fore(j,0,n){
			string s;
			fore(k,j,n){//E
				s+=a[i][k];
				if(st.count(s)){
					st.erase(s);
					for(auto l:pos[s])res[l]='E';
				}
			}
			s.clear();
			fore(k,i,n){//S
				s+=a[k][j];
				if(st.count(s)){
					st.erase(s);
					for(auto l:pos[s])res[l]='S';
				}
			}
			s.clear();
			for(int k=j;k>=0;k--){//O
				s+=a[i][k];
				if(st.count(s)){
					st.erase(s);
					for(auto l:pos[s])res[l]='O';
				}
			}
			s.clear();
			for(int k=i;k>=0;k--){//N
				s+=a[k][j];
				if(st.count(s)){
					st.erase(s);
					for(auto l:pos[s])res[l]='N';
				}
			}
			s.clear();
		}
	}
	fore(i,0,p){
		if(res[i]!='F')cout<<i+1<<" "<<res[i]<<"\n";
	}
	return 0;
}
