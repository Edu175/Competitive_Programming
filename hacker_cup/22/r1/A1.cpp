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
		ll n,k,r; cin>>n>>k;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			cin>>b[i];
			if(b[i]==a[0])r=(n-i)%n;
		}
		bool flag=1;
		fore(i,0,n){
			if(b[i]!=a[(i+r)%n]){
				flag=0;
				//cout<<"not r ";
				break;
			}
		}
		if(k==0&&r!=0)flag=0;
		if(k==1&&r==0)flag=0;
		if(n==2&&(k%2!=r%2))flag=0;
		//cout<<r<<" ";
		if(flag){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
