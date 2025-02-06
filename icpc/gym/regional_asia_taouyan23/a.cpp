#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll sum=0;
		string aux="";
		ll p=1;
		for(ll i=SZ(s)-1;i>=0;i--){
			aux.pb(s[i]);
			if(SZ(aux)==3){
				reverse(ALL(aux));
				sum+=p*(stoll(aux));
				p*=-1;
				aux.clear();
			}
		}
		reverse(ALL(aux));
		if(SZ(aux))sum+=p*(stoll(aux));
		cout<<abs(sum)<<" ";
		(sum%13==0) ? cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}