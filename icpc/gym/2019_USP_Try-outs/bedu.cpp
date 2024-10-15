#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a;jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end();
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
ll at=0;
void out(bool b){
	if(!b){
		cout<<"NO\n";
		exit(0);
	}
}
string s;
ll n;
void check(char c){
	// cout<<"check "<<at<<" == "<<c<<"\n";
	out(at<n&&s[at]==c);
}
bool digit(char c){return c>='0'&&c<='9';}
void buscoT();
void buscoM();
void buscoP();

void buscoT(){
	// cout<<"buscoT "<<at<<"\n";
	out(at<n);
	if(s[at]=='{'){
		at++;
		buscoM();
		check('}');
		at++;
	}
	else out(at<n&&digit(s[at]));
	while(at<n&&digit(s[at]))at++;
}
void buscoP(){
	// cout<<"buscoP "<<at<<"\n";
	buscoT();
	while(at<n&&s[at]==':')at++,buscoT();
}
void buscoM(){
	// cout<<"buscoM "<<at<<"\n";
	while(at<n&&s[at]=='|')at++;
	out(at<n);
	if(s[at]=='$'){
		at++;
		check('|');
		at++;
	}
	buscoP();
	while(at<n&&s[at]=='|')at++,buscoP();
}
int main(){
	JET
	string t;
	// cin.ignore();
	getline(cin,t);
	// cout<<t<<"\n";
	ll fg=0;
	for(auto i:t){
		// cout<<s<<" \""<<i<<"\"\n";
		if(i==' ')fg=1;
		else {
			out(!(SZ(s)&&digit(s.back())&&digit(i)&&fg));
			s.pb(i);
			fg=0;
		}
	}
	// char c;
	// while(cin>>c)s.pb(c);
	n=SZ(s);
	buscoM();
	out(at==n);
	cout<<"YES\n";
	return 0;
}