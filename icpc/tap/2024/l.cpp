#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll pot[32];
int main(){
    JET
    ll n,q; cin>>n>>q;
    ll p[n];
    pot[0]=1;
    fore(i,1,32) pot[i]=pot[i-1]<<1;
    fore(i,0,n) cin>>p[i];
    ll sp[n+1];
    ll si[n+1];
    ll su[n+1];
    mset(sp,0);mset(si,0);mset(su,0);
    fore(i,1,n+1){
        su[i]=su[i-1];
        sp[i]=sp[i-1];
        si[i]=si[i-1];
        if(p[i-1]==1) {su[i]++; continue;}
        bool y=true;
        fore(j,0,32)if(p[i-1]==pot[j] && y){sp[i]+=p[i-1]; y=false;}
        if(p[i-1]&1 && y) si[i]+=p[i-1];
    }
    // fore(i,0,n+1) cout<<sp[i]<<" ";; cout<<"\n";
    //  fore(i,0,n+1) cout<<si[i]<<" ";; cout<<"\n";
    fore(i,0,q){
        ll l,r;
        cin>>l>>r; l--;
        ll w2=(su[r]-su[l])/2;
        ll w1=su[r]-su[l]-w2;
        cout<<(sp[r]-sp[l]+w1>si[r]-si[l]+w2? "A\n":(sp[r]-sp[l]+w1<si[r]-si[l]+w2?"B\n":"E\n"));
    }
    return 0;
}

