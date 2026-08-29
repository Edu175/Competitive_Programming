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
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ifstream in; in.open("o",ios::in);
	cout<<"second"<<endl;
	ll t; in>>t; cout<<t<<endl;
	while(t--){
		ll n; in>>n;
		vv a(n);
		fore(i,0,n)in>>a[i];
		ll k; in>>k;
		vv b(k);
		fore(i,0,k)in>>b[i];
		cerr<<"Input:\n";
		for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
		for(auto i:b)cerr<<i<<" ";;cerr<<"\n";
		cout<<n<<" "<<k<<endl;
		// cerr<<"n k grader "<<n<<" "<<k<<"\n";
		ll cnt=0;
		while(1){
			char ty; cin>>ty;
			if(ty=='?'){
				cnt++;
				if(cnt>80*(k-80)){cerr<<"Muchas queries bro\n";exit(0);}
				ll i,j; cin>>i>>j; i--,j--;
				assert(i!=j);
				cout<<gcd(b[i],b[j])<<endl;
			}
			else {
				vv ai(n);
				fore(i,0,n)cin>>ai[i];
				cerr<<"Answered\n";
				for(auto i:ai)cerr<<i<<" ";;cerr<<"\n";
				ll good=1;
				if(a!=ai)cerr<<"Incorrect a\n",good=0;
				if(good)cerr<<"Correct :)\n";
				break;
			}
		}
	}
	return 0;
}

// mkfifo fifo
// (./a<fifo) | (./g>fifo)