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
		ll n,m; cin>>n>>m;
		ll tr=0;
		fore(i,0,n){
			fore(j,0,m){
				char a; cin>>a;
				if(a=='^')tr++;
			}
		}
		if(tr==0){
			cout<<"Possible\n";
			fore(i,0,n){
				fore(j,0,m)cout<<'.';
				cout<<"\n";
			}
		}
		else if((n==1)xor(m==1)){
			cout<<"Impossible\n";
		}
		else {
			cout<<"Possible\n";
			fore(i,0,n){
				fore(j,0,m)cout<<'^';
				cout<<"\n";
			}
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
