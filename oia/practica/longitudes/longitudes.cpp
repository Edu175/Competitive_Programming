#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b)for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
typedef long long ll;
using namespace std;

vector<int> dameLongitudes(vector<string> v)
{
    vector<int> res;
    for(auto i:v)res.pb(SZ(i));
    return res;
}
