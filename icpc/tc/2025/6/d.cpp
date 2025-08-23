#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	string s1,s2;
	ll a = 0,b = 0;
	fore(i,0,4){
		string s; cin>>s;
		int x; cin>>x;
		if(x>a){
			a = x;
			s1 = s;
		}
	}
	fore(i,0,4){
		string s; cin>>s;
		int x; cin>>x;
		if(x>b){
			b = x;
			s2 = s;
		}
	}
	if(a>b){
		cout<<s1<<" beats "<<s2<<"\n";
	}
	else cout<<s2<<" beats "<<s1<<"\n";
	return 0;
}