#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ii cv(string s){
    string _s=s;
    ll k=-1;
    fore(i,0,SZ(s)){
        if(s[i]=='/'){
            k=stoll(s.substr(i+1));
            s=s.substr(0,i);
            break;
        }
    }
    ll v=0;
    string t;
    fore(j,0,SZ(s)){
        if(s[j]=='.'){
            v=(v<<8)|stoll(t);
            t.clear();
        }
        else t.pb(s[j]);
    }
    v=(v<<8)|stoll(t);
    t.clear();
    if(k==-1){
        // cout<<_s<<": "<<v<<","<<v+1<<"\n";
        return {v,v+1};
    }
    ll p=1ll<<(32-k);
    // cout<<_s<<": "<<v<<","<<v+p<<"\n";
    return {v,v+p};
}

int main(){FIN;
    #ifdef ONLINE_JUDGE
    freopen("access.in","r",stdin);     freopen("access.out","w",stdout);
    #endif
    ll n; cin>>n;
    vector<pair<ll,ii>>lg(n);
    // cv("94.85.160.176/29");
    fore(i,0,n){
        string s; cin>>s;
        lg[i].fst=(s=="allow");
        cin>>s; cin>>s;
        lg[i].snd=cv(s);
    }
    ll m; cin>>m;
    set<ii>st;
    fore(i,0,m){
        string s; cin>>s;
        st.insert({cv(s).fst,i});
    }
    vector<ll>res(m,1);
    fore(i,0,n){
        auto [val,p1]=lg[i];
        auto [l,r]=p1;
        vector<ii>pop;
        for(auto it=st.lower_bound(ii({l,-1}));
        it!=st.end()&&(it->fst)<r;it++){
            res[it->snd]=val;
            pop.pb(*it);
        }
        for(auto i:pop)st.erase(i);
    }
    for(auto i:res){
        if(i)cout<<"A";
        else cout<<"D";
    }
    cout<<"\n";
    return 0;
}

/*


94.85.160.176/29: 1582670000,1582670008
10.0.0.1: 167772161,167772162
10.0.0.0/8: 167772160,184549376
192.168.0.0/16: 3232235520,3232301056
192.168.0.1: 3232235521,3232235522
10.0.0.1: 167772161,167772162
10.0.0.2: 167772162,167772163
194.85.160.133: 3260391557,3260391558
192.168.0.1: 3232235521,3232235522
192.168.0.2: 3232235522,3232235523
AAAAA

*/
