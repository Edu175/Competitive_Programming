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
vector<string>  a = {"1","2","5","14","42","165","714","3094","14858","79534","447051","2714690","17395070","114371070","783152070","5708587335","43848093003","342444658094","2803119896185","23619540863730","201813981102615","1793779293633437","16342050964565645","154170926013430326","1518409177581024365","15259825120722837478","154870329715038713659","1601991088154989174258","16725278985898957454695","177792163538134124432895"};
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
	#ifdef ONLINE_JUDGE
	freopen("handsome.in","r",stdin);
	freopen("handsome.out","w",stdout);
	#endif
	
	JET
	ll x;
	cin>>x;
	ll t = 1;
	while(x){
		cout<<"Case #"<<t++<<": "<<a[x-1]<<"\n";
		cin>>x;
	}
	return 0;
}