class Solution {
public:

    bool solve(vector<vector<char>>& board,    //Original grid
               int row,
               int col,        //Current cell
               string& word,           //Word to search
               int index)        //Current character of word to match
    {

        if(index == word.length())  // Pruning    , Entire word matched
            return true;

        // Out of bounds
        if(row < 0 || row >= board.size() ||       // Pruning
           col < 0 || col >= board[0].size())
            return false;

        // Already visited
        if(board[row][col] == '#')
            return false;

        // Character doesn't match
        if(board[row][col] != word[index])
            return false;

        // Choose
        // Mark current cell visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Search all 4 directions
        // index + 1 -> Match next character
        bool found =
            solve(board, row - 1, col, word, index + 1) || // Up
            solve(board, row + 1, col, word, index + 1) || // Down
            solve(board, row, col - 1, word, index + 1) || // Left
            solve(board, row, col + 1, word, index + 1);   // Right

        // Undo (Backtracking)
        // Restore original character
        board[row][col] = temp;

        // Return whether word was found
        return found;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        // Try every cell as starting point
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                // Start matching from first character
                if(solve(board, i, j, word, 0))
                    return true;
            }
        }

        // Word not found anywhere
        return false;
    }
};