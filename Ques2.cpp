#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); 
    int maxLength = 0;
    int start = 0; 

    for (int end = 0; end < s.length(); ++end) {
     
        if (lastIndex[s[end]] >= start) {
            start = lastIndex[s[end]] + 1;
        }
        lastIndex[s[end]] = end;
        maxLength = max(maxLength, end - start + 1); 
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}

