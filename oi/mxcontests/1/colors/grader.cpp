#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ifstream Cin;   Cin.open("in", ios::in);
	ofstream Cout; Cout.open("veredict", ios::out);	
	ll n,c; Cin>>n>>c;
	// cerr<<n<<" "<<c<<"\n";
	set<ll>st;
	ll col=-1,cnt=0;
	cout<<n<<endl;
	while(1){
		char ty; ll x; cin>>ty>>x;
		// cerr<<ty<<" "<<x<<"\n";
		if(ty=='='){
			if(c==x)Cout<<"AC\n";
			else Cout<<"WA\n";
			Cout<<"Guessed: "<<x<<"\nUsing "<<cnt<<" queries\n";
			break;
		}
		if(st.count(x)){
			Cout<<"FAILED\nUsed "<<x<<" twice\n";
			break;
		}
		st.insert(x);
		// cerr<<ll(abs(col-x)>=c)<<endl;
		cout<<ll(abs(col-x)>=c)<<endl;
		col=x;
		cnt++;
	}
	return 0;
}