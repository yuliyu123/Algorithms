//
// Created by looperX on 7/18/21.
//

#ifndef ALGORITHMMS_UNIONFIND_H
#define ALGORITHMMS_UNIONFIND_H

/*
 * union_find 并查集
 * 合并子树 && 在树上查找节点祖先
 * */
using namespace std;

class UnionFind {
public:
    UnionFind(int maxSize):parent_(new int[maxSize]), rank_(new int[maxSize]) {
        for (int i = 0; i < maxSize; ++i) {
            parent_[i] = i;
            rank_[i] = 0;
        }
    }

    ~UnionFind() {
        delete[] parent_;
        delete[] rank_;
    }

    int find(int x) {
        return parent_[x] == x ? x : find(parent_[x]);
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }

    void unionNode(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        // 高度小的树的根节点指向高度大的树的节点.
        if (aRoot != bRoot) {
            if (rank_[aRoot] > rank_[bRoot]) {
                parent_[bRoot] = aRoot;
            }
            else if (rank_[aRoot] < rank_[bRoot]) {
                parent_[aRoot] = bRoot;
            }
            else {
                parent_[aRoot] = bRoot; rank_[bRoot] += 1;  // 秩加一
            }
        }
    }

private:
    int *parent_;   // 该节点父节点的关系
    int *rank_;  // 按秩(高度)合并，记录节点和该节点的高度
};

#endif //ALGORITHMMS_UNIONFIND_H

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

//output:
//0
//5
//5
//0
//1
