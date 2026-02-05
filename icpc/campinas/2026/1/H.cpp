#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
void tle(bool a){
    if(!a){
        auto start=clock();
        while(clock()-start<30*CLOCKS_PER_SEC);
        cerr<<"chota\n";
    }
}
ll ask(string a){
    cout<<"? "<<a<<endl;
    ll ret; cin>>ret;
    return ret;
}

int main(){
    // JET
    ll t; cin>>t;
    while(t--){
        vector<char> good,bad;
        map<char,ll> is;
        fore(i,0,7){
            char c='a'+i;
            ll ret=ask(string(2,c));
            (ret?good:bad).pb(c);
            is[c]=ret;
        }
        tle(SZ(good)==4);
        map<pair<char,char>,bool> mp;

        auto comp=[&](char a, char b){
            assert(is[a]==is[b]);
            if(a==b)return false;
            if(mp.count({a,b}))return mp[{a,b}];
            auto &res=mp[{a,b}];
            string s=string(1+is[a],a)+string(1+is[b],b);
            res=ask(s);
            mp[{b,a}]=!res;
            return res;
        };

        stable_sort(ALL(good),comp);
        stable_sort(ALL(bad),comp);
        cout<<"! ";
        fore(i,0,4){
            cout<<good[i];
            if(i<SZ(bad))cout<<bad[i];
        }
        cout<<endl;
    }
    return 0;
}
