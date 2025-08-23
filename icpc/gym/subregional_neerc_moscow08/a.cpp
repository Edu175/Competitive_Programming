#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	int n; cin>>n;
	vector<pair<string,string>> rta;
	map<string,int> mp;
	fore(i,0,n){
		string a, b;
		cin>>a>>b;
		if(a=="SCH" || rta.size()==10) continue;
		if(a=="MSU" && mp[a]<4) rta.pb({a,b});
		if(a!="MSU" && mp[a]<2) rta.pb({a,b});
		mp[a]++;
	}
	cout<<rta.size()<<"\n";
	for(auto x:rta) cout<<x.fst<<" "<<x.snd<<"\n";
	return 0;
}
