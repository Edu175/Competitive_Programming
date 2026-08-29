#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll res = 0, cent = 0;

void process(string num){
	if(SZ(num)<=3){
		res+=stoll(num);
		return;
	}
	ll i = SZ(num)-1,post = 0;
	while(num[i] != '.')i--,post++;
	if(post == 2){
		string c = num.substr(SZ(num)-2,2);
		cent+=stoll(c);
		fore(j,0,3) num.pop_back();
	}
	string aux = "";
	for(auto x:num)if(x != '.')aux.pb(x);
	// reverse(ALL(aux));
	// cout<<aux<<endl;
	res+=stoll(aux);
}

int main(){
	JET
	string s; cin>>s;
	string num = "";
	for(auto x:s){
		if(x >= 'a' && x<='z' && SZ(num)){
			process(num);
			num.clear();
		}
		else if(x<'a' || x>'z') num.pb(x);
	}
	if(SZ(num))process(num);
	res+=cent/100;
	cent%=100;
	string aux = to_string(res);
	string rta = "";
	ll p = 0;
	for(ll i = SZ(aux)-1;i>=0;i--){
		rta.pb(aux[i]);
		p++;
		if(p%3 == 0) rta.pb('.');
	}
	if(rta.back()== '.')rta.pop_back();
	reverse(ALL(rta));
	cout<<rta;
	if(cent){
		string c = to_string(cent);
		if(SZ(c) == 1){
			c.pb('0');
			reverse(ALL(c));
		}
		cout<<"."<<c;
	}
	cout<<"\n";
	return 0;
}