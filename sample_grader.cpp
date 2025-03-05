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
	ifstream in; in.open("in",ios::in);
	ll n; in>>n;
	vv p(n),a(n);
	fore(i,0,n)in>>p[i],p[i]--;
	fore(i,0,n)in>>a[i];
	shuffle(ALL(p),rng); if(p[0]>p[1])swap(p[0],p[1]);
	shuffle(ALL(a),rng);
	cerr<<"Input:\n";
	for(auto i:p)cerr<<i+1<<" ";;cerr<<"\n";
	for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
	vv sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	ll cnt=0;
	cout<<n<<endl;
	while(1){
		char ty; cin>>ty;
		if(ty=='?'){
			cnt++;
			if(cnt>2*n){cerr<<"Muchas queries bro\n";exit(0);}
			ll s,t; cin>>s>>t; s--,t--;
			assert(s!=t);
			ll l=p[s],r=p[t];
			if(l>r)swap(l,r);
			cout<<sp[r+1]-sp[l]<<endl;
		}
		else {
			vv pi(n),ai(n);
			fore(i,0,n)cin>>pi[i],pi[i]--;
			fore(i,0,n)cin>>ai[i];
			cerr<<"Answered\n";
			for(auto i:pi)cerr<<i+1<<" ";;cerr<<"\n";
			for(auto i:ai)cerr<<i<<" ";;cerr<<"\n";
			ll good=1;
			if(p!=pi)cerr<<"Incorrect p\n",good=0;
			if(a!=ai)cerr<<"Incorrect a\n",good=0;
			if(good)cerr<<"Correct :)\n";
			break;
		}
	}
	return 0;
}


// (./a<fifo) | (./g>fifo)