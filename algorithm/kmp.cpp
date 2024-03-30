#include <iostream>
#include <vector>
using namespace std;


/*
next数组是 后缀==前缀的最长长度
*/

// 构建匹配表
vector<int> buildNext(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);

    // j 是模板串，i 是需要进行匹配
    // i = 0时 j 如果不匹配则从头开始，依旧为0，所以 i 从 1 开始
    for (int i = 1, j = 0; i < m - 1; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            //如果当前 j 不相等
            //next[j - 1] 存的是，j - 1为结尾 后缀=前缀 的最长长度，
            //j 这个位置是用来比较的，并不在next数组的相等范围内
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            // 此时有匹配的前缀
            ++j;
        } // 否则没有匹配的前缀

        next[i] = j;
    }

    for (int i = 0; i < m; i++) {
        cout << next[i] << " ";
    }cout << endl;
    return next;
}

// KMP搜索函数
void kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // 如果模式串为空直接返回
    if (m == 0) {
        cout << "Pattern is empty" << endl;
        return;
    }

    vector<int> next = buildNext(pattern);

    for (int i = 0, j = 0; i < n; i++) {
        // 如果当前字符不匹配，回溯到模式串中匹配的位置
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index: " << i - m + 1 << endl;
            j = next[j - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "text: ";
    cin >> text;
    cout << "pattern: ";
    cin >> pattern;
    kmpSearch(text, pattern);
    return 0;
}