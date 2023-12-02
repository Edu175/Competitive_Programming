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

int main(){FIN;
    //ifstream cin;  cin.open("movil.in" ,ios::in);
    //ofstream cout;cout.open("movil.out",ios::out);
    ll n; cin>>n;
    ll a[n];
    ll flag=0;
    vector<ll>b[MAXV];
    fore(i,0,n){
        cin>>a[i];
        b[a[i]].pb(1);
        if(a[i])flag=1;
    }
    if(!n||!flag){
    	cout<<"no se puede";
    	return 0;
    }
    ii res={0,0};
    fore(i,0,MAXV){
    	start:
    	vector<ll>c=b[i];
    	b[i].clear();
    	if(SZ(c)&1)b[i].pb(c[0]);
        for(ll j=SZ(c)&1;j<SZ(c);j+=2){
            b[2*i].pb(c[j]+c[j+1]);
        }
        if(SZ(b[i])){cout<<i<<": "; imp(b[i]);cout<<endl;}
        if(SZ(b[i])>1)goto start;
        
        if(SZ(b[i])&1)res=max(res,{b[i][0],-i});
    }
    /*if(res.fst<=1){
    	cout<<"no se puede";
    	return 0;
    }*/
    cout<<"end for"<<endl;
    res.snd*=-1;
    cout<<res.fst<<" "<<res.snd<<" ";
    if(res.snd==0){
    	cout<<"0";
    	return 0;
    }
     cout<<endl;
    ll p=res.snd;
    while(p%2==0)p/=2;
    vector<ll>c;
    fore(i,0,n){
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
