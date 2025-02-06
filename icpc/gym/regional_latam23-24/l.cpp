#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<string> no={
	")(",
	"()",
	"a(",
	"(+",
	"+)",
	")a",
	"++"
};

bool sep(char a, char b){
	string s;
	s.pb(a); s.pb(b);
	return count(ALL(no),s);
}
ll res=0;
void calc(string s){
	if(!SZ(s))return;
	// rbs
	ll n=SZ(s);
	vv a(n),can(n);
	ll c=0;
	map<ll,vv>mp;
	fore(i,0,n){
		a[i]=c; can[i]=s[i]!='+';
		if(s[i]=='(')c++;
		if(s[i]==')')c--;
		if(can[i])mp[c].pb(i);
	}
	vv r(n);
	for(ll i=n-1;i>=0;i--)
		for(r[i]=i+1;r[i]!=n&&a[i]<=a[r[i]];r[i]=r[r[i]]);
	ll resi=0;
	fore(i,0,n)if(can[i]){
		auto &v=mp[a[i]];
		resi+=lower_bound(ALL(v),r[i])-lower_bound(ALL(v),i);
	}
	res+=resi;
	// cout<<"calc "<<s<<": "<<resi<<"\n";
}
int main(){
	ET;
	string s; cin>>s;
	string a;
	
	for(auto i:s){
		if(i=='-'||i=='/'||i=='*')i='+';
		if('a'<=i&&i<='z')i='a';
		if(SZ(a)&&sep(a.back(),i))calc(a),a.clear();
		a.pb(i);
	}
	calc(a);
	cout<<res<<"\n";
}