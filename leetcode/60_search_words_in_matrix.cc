#include <string>
#include <vector>

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    if (board.empty()) {
      return word.empty();
    }
    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (exist(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }

  bool exist(std::vector<std::vector<char>> &board, std::string word,
             int current_index, int current_row, int current_col) {
    if (current_row < 0 || current_row >= board.size() || current_col < 0 ||
        current_col >= board[0].size()) {
      return false;
    }
    // 不能够匹配当前字符
    if (board[current_row][current_col] != word[current_index]) {
      return false;
    }
    // 当前字符已经匹配，且已经到达尾部
    if (current_index == word.size() - 1) {
      return true;
    }
    // 当前字符已经匹配，继续向下匹配
    char tmp = board[current_row][current_col];
    board[current_row][current_col] = '#'; // 标记已经访问过
    // 在周围寻找是否存在一个位置匹配下一个字符
    bool is_exist =
        exist(board, word, current_index + 1, current_row + 1, current_col) ||
        exist(board, word, current_index + 1, current_row - 1, current_col) ||
        exist(board, word, current_index + 1, current_row, current_col + 1) ||
        exist(board, word, current_index + 1, current_row, current_col - 1);

    // 恢复
    board[current_row][current_col] = tmp;
    return is_exist;
  }
};