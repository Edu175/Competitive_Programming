#include "bits/stdc++.h"
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        map<char,ll> ch = {{'L',0},{'I',1},{'T',2}};
        set<string> vis;
        vis.insert(s);
        queue<string> q;
        q.push(s);
        string lit = "LIT";
        string ans = "-1";
        while(SZ(q)){
            if(SZ(s)>3*n)break;
            string priti = q.front();q.pop();
            vector<ll> qq(3);
            fore(i,0,SZ(priti)){
                qq[ch[priti[i]]]++;
            }
            sort(ALL(qq));
            if(qq[0]==qq[2]){
                ans=priti;
                break;
            }

            fore(i,0,SZ(priti)-1){
                if(priti[i]==priti[i+1])continue;

                char c;
                fore(j,0,3){
                    if(lit[j]!=priti[i] && lit[j]!=priti[i+1])c=lit[j];
                }
                if(!vis.count(priti.substr(0,i+1)+c+priti.substr(i+1,SZ(priti)-i-1))){
                    vis.insert(priti.substr(0,i+1)+c+priti.substr(i+1,SZ(priti)-i-1));
                    q.push(priti.substr(0,i+1)+c+priti.substr(i+1,SZ(priti)-i-1));
                }
            }
        }
		if(ans=="-1")cout<<ans<<"\n";
		else cout<<"PINGA\n",cerr<<ans<<"\n";
        // cout<<ans<<'\n';
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/