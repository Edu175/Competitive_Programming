// bash commands for interaction:

// mkfifo fifo
// (./a < fifo) | (./g > fifo)


// sample grader for cf 101021A (guess a number, queries: is it >=k?)
#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
using namespace std;
typedef long long ll;

#define MAX_QUERIES (3*n+1)/2

// for external input use in>>
// for external output use cerr<<

int main(){FIN;
	ifstream in; in.open("in",ios::in); // input in file "in"
	
	// tipically hidden info
	// enter it with in>>
    ll t; in>>t;
    cout<<t<<endl;
    while(t--){
        ll n; in>>n;
        cout<<n<<endl;
        vector<ll> a(n);
        fore(i,0,n)in>>a[i];
        cerr<<"Input:\n";
        fore(i,0,n)cerr<<a[i]<<" ";;cerr<<"\n";
        auto _a=a;
        ll cnt=0; // number of queries
        while(1){
            string ty; cin>>ty;
            // cerr<<"while\n";
            if(ty!="!"){
                if(++cnt > MAX_QUERIES){
                    cerr<<"Too much queries\n";
                    exit(0);
                }
                ll x; cin>>x; x--;
                cerr<<"asked "<<ty<<": "<<x<<"\n";
                if(ty=="swap")swap(a[x],a[x+1]);
                else {
                    ll res=0;
                    while(x<n)res++,x+=a[x];//,cerr<<x<<" x\n";;
                    cout<<res<<endl;
                }
            }
            else {
                // cerr<<"final\n";
                vector<ll> b(n);
                fore(i,0,n)cin>>b[i];
                cerr<<"Answered:\n";
                fore(i,0,n)cerr<<b[i]<<" ";;cerr<<"\n";
                if(_a==b)cerr<<"Correct :)\n";
                else cerr<<"Incorrect\n";
                break;
            }
        }
    }
	return 0;
}