#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet =b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

void fail(){
    cout<<"*\n";
    exit(0);
}

int main(){
    JET
    ll n,L; cin>>n>>L;
    vector<ii> a(n);
    set<ll> st;
    fore(i,0,n){
        ll v; cin>>v; v--;
        a[i].fst=v;
        if(st.count(v))fail();
        st.insert(v);
    }
    st.clear();
    fore(i,0,n){
        ll v; cin>>v; v--;
        a[i].snd=v;
        if(st.count(v))fail();
        st.insert(v);
    }

    ll ans=INF;
    sort(ALL(a));
    fore(ty,0,2){
        // for(auto [x,y]:a)cout<<x<<","<<y<<" ";;cout<<"\n";
        ll pri=a[0].snd;
        if(pri<a[0].fst)pri+=L;
        ll res=pri-a[0].fst; // derecha
        ll ult=pri;
        ll bad=0;
        fore(i,1,n){
            if(a[i].fst<a[i-1].fst){
                assert(ty);
                a[i].fst+=L;
            }
            ll now=a[i].snd;
            // while(now<a[i].fst)now+=L; // free
            ll cant=0;
            while(now<ult)now+=L,cant++;
            if(cant>3){bad=1;break;}
            ll cur=abs(now-a[i].fst);
            res=max(res,cur);
            // cerr<<i<<": "<<now<<" "<<cur<<"\n";
            ult=now;
        }
        bad|=ult-pri>=L;
        if(!bad)ans=min(ans,res);
        for(auto &i:a){
            i.fst=L-1-i.fst;
            i.snd=L-1-i.snd;
        }
        reverse(ALL(a));
        rotate(a.begin(),a.begin()+n-1,a.end());
        // cout<<res<<"\n\n";
    }
    if(ans>=INF)fail();
    else cout<<ans<<"\n";
    return 0;
}

