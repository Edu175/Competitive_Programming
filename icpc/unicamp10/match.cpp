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

bool ismat(string s){
	map<char,ll>mp;
	for(auto i:s)mp[i]++;
	if(1<=mp['=']&&mp['=']<=20&&mp['O']==1&&mp['O']+mp['=']==SZ(s)&&(s[0]=='O'||s.back()=='O'))return 1;
	return 0;
}

int main(){FIN;
	ll n; cin>>n;
	string nom,mat;
	fore(i,0,n){
		string a,b; cin>>a>>b;
		if(ismat(a))swap(a,b);
		if(!SZ(mat)||SZ(mat)>SZ(b))mat=b,nom=a;
	}
	cout<<nom<<"\n";
	return 0;
}
