#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

//#define BASE_SCORE 6

enum class SupportedType
{
    Type1 = 1,
    Type2 = 2,
    Type3 = 3,
    Type4 = 4,
};



struct CellWithFreq
{
    string cellDn;
    SupportedType supportedType;
    bool isMatchCbrsFreqType;
    int priotity;
};

// 这里不考虑资源析构，仅实现算法代码
int main(void)
{
    int base_score = 6;
    int priotity_base = 3;
    auto caclCellsPriorityScore = [&](const vector<CellWithFreq>& requestCells) -> uint64_t
            {
                int score = 0;
                std::for_each(requestCells.begin(), requestCells.end(), [&](const CellWithFreq& cellWithFreq){
                    cout << cellWithFreq.cellDn << endl;
                    if (cellWithFreq.isMatchCbrsFreqType)
                    {
                        score += pow(base_score - cellWithFreq.priotity, base_score - (int)cellWithFreq.supportedType) * 1000;
                    }
                    else
                    {
                        score += pow(base_score - cellWithFreq.priotity, base_score - (int)cellWithFreq.supportedType);
                    }
                });

                return score;
            };

//    CellWithFreq cell_01;
//    cell_01.supportedType = SupportedType::Type1;
//    cell_01.isMatchCbrsFreqType = true;
//    cell_01.priotity = 1;
//    cell_01.cellDn = "CELL_01";
//
//    CellWithFreq cell_01_notMatched;
//    cell_01_notMatched.supportedType = SupportedType::Type1;
//    cell_01_notMatched.isMatchCbrsFreqType = false;
//    cell_01_notMatched.priotity = 1;
//    cell_01_notMatched.cellDn = "CELL_01";
//
//    vector<CellWithFreq> cachedResults;
//    cachedResults.push_back(cell_01);
//    vector<CellWithFreq> finalResults;
//    finalResults.push_back(cell_01_notMatched);

    CellWithFreq cell_01, cell_02, cell_03, cell_04;
    cell_01.supportedType = SupportedType::Type1;
    cell_01.isMatchCbrsFreqType = true;
    cell_01.priotity = 1;
    cell_01.cellDn = "CELL_01";

    cell_02.supportedType = SupportedType::Type1;
    cell_02.isMatchCbrsFreqType = true;
    cell_02.priotity = 2;
    cell_02.cellDn = "CELL_02";

    cell_03.supportedType = SupportedType::Type3;
    cell_03.isMatchCbrsFreqType = true;
    cell_03.priotity = 2;
    cell_03.cellDn = "CELL_03";

//    cell_04.supportedType = SupportedType::Type1;
//    cell_04.isMatchCbrsFreqType = false;
//    cell_04.priotity = 2;
//    cell_04.cellDn = "CELL_04";

    vector<CellWithFreq> cachedResults;
    cachedResults.push_back(cell_01);
//    cachedResults.push_back(cell_02);
//    cachedResults.push_back(cell_03);


    CellWithFreq cell_05, cell_06, cell_07, cell_08;
    cell_05.supportedType = SupportedType::Type1;
    cell_05.isMatchCbrsFreqType = true;
    cell_05.priotity = 2;
    cell_05.cellDn = "CELL_06";

    cell_06.supportedType = SupportedType::Type1;
    cell_06.isMatchCbrsFreqType = true;
    cell_06.priotity = 3;
    cell_06.cellDn = "CELL_07";

    cell_07.supportedType = SupportedType::Type3;
    cell_07.isMatchCbrsFreqType = true;
    cell_07.priotity = 1;
    cell_07.cellDn = "CELL_05";
    vector<CellWithFreq> finalResults;
    finalResults.push_back(cell_05);
    finalResults.push_back(cell_06);
    finalResults.push_back(cell_07);

    uint64_t cachedScore = caclCellsPriorityScore(cachedResults);
    uint32_t finalScore = caclCellsPriorityScore(finalResults);
    cout << "cachedScore: " << cachedScore << ", finalScore: " << finalScore << endl;
    assert(cachedScore > finalScore);
}
