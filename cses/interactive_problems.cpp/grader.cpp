#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ifstream input;   input.open("input", ios::in);
	ll n; input>>n;
	vv a(n);
	fore(i,0,n)input>>a[i];
	auto count=[&](){
		ll res=0;
		fore(i,0,n)fore(j,i+1,n)res+=a[i]>a[j];
		return res;
	};
	cout<<n<<endl;
	ll cant=0;
	while(1){
		cant++;
		ll l,r; cin>>l>>r;
		cerr<<" asked "<<l<<" "<<r<<"\n";
		l--;
		reverse(a.begin()+l,a.begin()+r);
		for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
		cout<<count()<<endl;
		if(!count())break;
	}
	cerr<<"Made "<<cant<<" queries\n";
	return 0;
}
// mkfifo fifo
// (./a < fifo) | (./g > fifo)
// a solution, g grader