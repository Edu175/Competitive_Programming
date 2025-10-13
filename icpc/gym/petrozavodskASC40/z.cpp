#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef __int128_t xl;

vv pr;
const xl inf  = 1e33;  
bool prim(ll x){
	for(auto p:pr) while(x%p == 0 && p!=1) x/=p;
	return x > 1;
}

xl mul(xl a, xl b){
	return min(a*b, inf);
}

string tos(xl a){
	string s = "";
	while(a){
		s.pb('0'+a%10);
		a/=10;
	}
	reverse(ALL(s));
	return s;
}

int main(){
	JET
	assert(inf>0);
	ll i = 2;
	pr.pb(1);
	while(SZ(pr)<33){
		if(prim(i))pr.pb(i);
		i++;;
	}
	vector<string> rta;
	fore(k,30,31){
		xl bst = 0 ;
		fore(i,0,1ll<<(k+1)){
			xl uno = 1, dos  = 1;
			fore(j,1,k+1){
				if(i & (1<<j)) uno = mul(uno,pr[j]);
				else dos = mul(dos, pr[j]);
			}
			if(uno > dos) continue;
			bst = max(bst, uno);
			// cout<<"debugg "<<(ll)dos<<" "<<(ll)uno<<"\n";
		}
		rta.pb(tos(bst));
		cout<<tos(bst)<< " "<<k<<endl;
	}
	for(auto x:rta){
		cout<<x<<", ";
	}
	cout<<"\n";
	
	return 0;
}