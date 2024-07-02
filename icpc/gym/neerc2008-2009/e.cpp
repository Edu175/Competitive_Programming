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

int main(){FIN;
#ifdef ONLINE_JUDGE
freopen("enchanted.in","r",stdin);     freopen("enchanted.out","w",stdout);
#endif

    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int n=SZ(s1);
    vector<pair<char,int>> v[26];
    fore(i,0,n){
        v[s1[i]-'A'].pb({s2[n-(i+1)],0});
    }
    fore(i,0,n){
        int aux=s3[i]-'A';
        bool b=false;
        fore(j,0,SZ(v[aux])){
            if(v[aux][j].fst==s4[n-(i+1)] && v[aux][j].snd==0){
                b=true;
                v[aux][j].snd=1;
                break;
            }
            
        }
        if(!b){
                cout<<"No\n";
                return 0;
            }
    }
    cout<<"Yes\n";
    return 0;
}
