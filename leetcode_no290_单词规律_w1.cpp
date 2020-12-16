/* ------------------------------------------------------------------|
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了15.33%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool wordPattern(string pattern, string s) {
    vector<string> str;
    string tmp;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            str.emplace_back(tmp);
            tmp = "";
            continue;
        }
        else {
            tmp.push_back(s[i]);
        }
    }

    if (str.size() != pattern.size()) {
        return false;
    }

    unordered_map<char, string> char2str;
    unordered_map<string, char> srt2char;
    for (int i = 0; i < pattern.size(); i++) {
        if (char2str[pattern[i]] == "") {
            char2str[pattern[i]] = str[i];
        }
        else {
            if (char2str[pattern[i]] != str[i]) {
                return false;
            }
        }

        if (!srt2char[str[i]]) {
            srt2char[str[i]] = pattern[i];
        }
        else {
            if (srt2char[str[i]] != pattern[i]) {
                return false;
            }
        }
    }
    return true;
}