// https://leetcode.com/problems/word-search/
// https://1o24bbs.com/t/topic/9656/4

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        if (index >= word.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return false;
        
        bool result = false;
        if (board[i][j] == word[index])
        {
            ++index;
            char tmp = board[i][j];
            board[i][j] = '#';  // 找到了做个标记
            result = dfs(board, word, i+1, j, index) || dfs(board, word, i-1, j, index)
                || dfs(board, word, i, j-1, index) || dfs(board, word, i, j+1, index);
            
            board[i][j] = tmp; // 找到word[index]并且递归完后还原回去，防止其他递归再次找
        }
        
        return result;
    }
};
