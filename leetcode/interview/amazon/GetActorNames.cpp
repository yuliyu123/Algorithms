#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include <unordered_map>
#include <vector>
#include <condition_variable>

using namespace std;

/*
 * Jason - {2,9},{15-20}
    Jasica - {7,10}
 * */
void getActorNames(int x)
{
    map<string, vector<vector<int> >> nameMap;
    nameMap["Jason"] = {{2, 9}, {15, 20}};
    nameMap["Jasica"] = {{7, 10}};

    for (auto& item : nameMap)
    {
        for (int i = 0; i < item.second.size(); ++i) {
            auto& tmpVec = item.second[i];
            int low = tmpVec.begin()[0];
            int high = tmpVec.begin()[1];
            if (x >= low and x <= high)
            {
                cout << item.first << endl;
            }
        }
    }
}

int main()
{
    getActorNames(8);
    cout << endl;
    getActorNames(20);
    cout << endl;
    getActorNames(25);
    cout << endl;
}
