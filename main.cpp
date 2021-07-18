#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "ds/UnionFind.h"

using namespace std;

int main(void)
{
    UnionFind uf(6);
    cout << uf.isConnected(1, 5) << endl;
    uf.unionNode(1, 5);
    cout << uf.find(1) << endl;
    cout << uf.find(5) << endl;
    cout << uf.find(6) << endl;
    cout << uf.isConnected(1, 5) << endl;
    return 0;
}
