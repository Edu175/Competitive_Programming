#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	ll flag=1;
	if(SZ(s)!=8){
		flag=0;
	}
	if(s[0]<'A'||s[0]>'Z')flag=0;//,cout<<"0\n";
	if(s[SZ(s)-1]<'A'||s[SZ(s)-1]>'Z')flag=0;//,cout<<SZ(s)-1<<"\n";
	fore(i,1,SZ(s)-1){
		if(i==1&&s[i]=='0')flag=0;//,cout<<i<<" a\n";
		if(s[i]<'0'||s[i]>'9')flag=0;//,cout<<i<<" b\n";
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
