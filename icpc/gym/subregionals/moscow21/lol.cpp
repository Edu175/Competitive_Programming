#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


// string alp="IVXCMLD";
vector<vector<string>> tab={
	{"","I","II","III","IV","V","VI","VII","VIII","IX"},	
	{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	{"","M","MM","MMM"}

};
string cv(ll n){
	vector<string>res;
	fore(i,0,SZ(tab)){
		// if(SZ)
		res.pb(tab[i][n%10]);
		n/=10;
	}
	reverse(ALL(res));
	string s;
	for(auto i:res)s+=i;
	return s;
}
bool ispal(string s){
	auto r=s;
	reverse(ALL(r));
	return r==s;
}
int main(){
	fore(i,1,4000){
		string s=cv(i);
		// if(i<50)cout<<i<<": "<<cv(i)<<"\n";
		if(ispal(s))cout<<s<<"\n";
	}
}