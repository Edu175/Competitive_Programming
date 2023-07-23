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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n=3;
		char a[3][3];
		fore(i,0,n)fore(j,0,n)cin>>a[i][j];
		char w='.';
		fore(i,0,3){
			if(a[i][0]!='.'&&a[i][0]==a[i][1]&&a[i][1]==a[i][2])w=a[i][0];
			if(a[0][i]!='.'&&a[0][i]==a[1][i]&&a[1][i]==a[2][i])w=a[0][i];
		}
		if(a[1][1]!='.'){
			if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])w=a[1][1];
			if(a[2][0]==a[1][1]&&a[1][1]==a[0][2])w=a[1][1];
		}
		if(w=='.')cout<<"DRAW\n";
		else cout<<w<<"\n";
	}
	return 0;
}
