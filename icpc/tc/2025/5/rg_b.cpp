#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

string get(){
	ll v=rng()%(101);
	string s;
	s.pb('0'+v%10); v/=10;
	s.pb('0'+v%10); v/=10;
	s.pb('.');
	s.pb('0'+v%10); v/=10;
	reverse(ALL(s));
	return s;
}

int main(){
	JET
	ll n,q; cin>>n>>q;
	cout<<n<<"\n";
	fore(i,0,n){
		cout<<get()<<" ";
	}
	cout<<"\n";
	vector<ii>ed;
	vv per(n); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	fore(i,1,n){
		ed.pb({per[rng()%i],per[i]});
	}
	shuffle(ALL(ed),rng);
	for(auto [x,y]:ed)cout<<x<<" "<<y<<"\n";
	
	cout<<q<<"\n";
	fore(i,0,q){
		cout<<rng()%n<<" "<<get()<<"\n";
	}
	
	return 0;
}