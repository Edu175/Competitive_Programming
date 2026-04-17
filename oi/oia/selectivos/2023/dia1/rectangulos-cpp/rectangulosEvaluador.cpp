#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int rectangulos(vector<int> x, vector<int> y);

int evaluadorE;
vector<int> evaluadorX, evaluadorY;

int consulta(int i,int W,int H)
{
    cout << "consulta(" << i << ", " << W << ", " << H << ") = ";
    int ret = 2 * abs(evaluadorX[i-1] - evaluadorX[evaluadorE-1]) <= W && 2 * abs(evaluadorY[i-1] - evaluadorY[evaluadorE-1]) <= H;
    cout << ret << endl;
    return ret;
}

int main() {
    int N;
    cin >> N >> evaluadorE;
    evaluadorX.resize(N);
    evaluadorY.resize(N);
    for (int i=0;i<N;i++)
        cin >> evaluadorX[i] >> evaluadorY[i];
    int ret = rectangulos(evaluadorX, evaluadorY);
    cout << ret << endl;
    return 0;
}
