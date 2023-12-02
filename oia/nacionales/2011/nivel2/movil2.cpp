#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=3e6+5;

//100

int main(){FIN;
    ifstream cin;  cin.open("movil.in" ,ios::in);
    ofstream cout;cout.open("movil.out",ios::out);
    ll n; cin>>n;
    vector<ll>a;
    ll can=0;
    vector<ll>b[MAXV];
    fore(i,0,n){
    	ll x; cin>>x;
        if(x==0)can++;
        else {
        	a.pb(x);
    		b[x].pb(1);
        }
    }
    ii res={can,0};
    fore(i,1,MAXV){
        for(ll j=SZ(b[i])&1;j<SZ(b[i]);j+=2){
            b[2*i].pb(b[i][j]+b[i][j+1]);
        }
        if(SZ(b[i])&1)res=max(res,{b[i][0],-i});
    }
    if(res.fst<=0){
    	cout<<"no se puede";
    	return 0;
    }
    res.snd*=-1;
    cout<<res.fst<<" "<<res.snd<<" ";
    if(res.snd==0){
    	cout<<"0";
    	return 0;
    }
    ll p=res.snd;
    while(p%2==0)p/=2;
    vector<ll>c;
    fore(i,0,SZ(a)){
        ll x=a[i];
        while(x%2==0)x/=2;
        if(x==p)c.pb(a[i]);
    }
    sort(ALL(c));
    reverse(ALL(c));
    ll ans=0;
    for(auto i:c){
        if(i<=res.snd)res.snd-=i,ans++;
    }
    cout<<ans;
    return 0;
}
