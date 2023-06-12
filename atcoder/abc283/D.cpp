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
	string a; cin>>a;
	ll l=-3,r=-3,n=SZ(a);
	map<char,ll>mp;
	ll flag=1;
	fore(i,0,n){
		if(a[i]=='(')continue;
		if(a[i]!=')'){
			mp[a[i]]++;
			if(mp[a[i]]>1)flag=0;
			continue;
		}
		if(r!=-3)fore(j,r+1,i)mp[a[j]]--;
		r=i;
		if(l==-3)l=i-1;
		while(l>=0&&a[l]!='('){
			if(a[l]!=')')mp[a[l]]--;
			l--;
		}
		l--;
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
