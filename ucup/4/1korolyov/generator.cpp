#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;
typedef vector<vv> mtx;

#define gc getchar_unlocked()
typedef ll tre;
static inline tre re(){ //fast input bestial!!
	tre x=0;
	char c=gc; 
    bool f=0;
    if(c=='-') f=1,c=gc;
	while(c>' '&&c!='\n') { //while is a digit
        x=(x<<3)+(x<<1)+(c&15),c=gc; //x*10 + digit
    }
    return f?-x:x;
}
random_device rd;
mt19937 rng(rd());
int main(){
    JET
    ll maxn=re(),maxq=re(), maxd=re(),maxa=re()+1;
    ll n=maxn,q=maxq, d=maxd;
    cout<<n<<" "<<q<<" "<<d<<"\n";
    fore(i,0,n){
        ll ai=rng()%maxa;
        cout<<ai<<" ";
    }
    cout<<"\n";
    while(q--){
        ll r=rng()%n+1;
        ll l=rng()%r+1;
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}