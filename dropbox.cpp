#include "stdc++.h"

using namespace std;


int main(){


	return 0;
}










bool isSamePatternHelper(string& pattern, int pIndex, string& input, int iIndex, unordered_map<char, string>& hash, unordered_map<string, char>& hashString) {  
    if (pIndex == pattern.size() && iIndex == input.size()) {  
        return true;  
    }  
    if (pIndex == pattern.size() || iIndex == input.size()) {  
        return false;  
    }  
    char c = pattern[pIndex];  
    if (hash.find(c) != hash.end()) {  
        string toMatch = hash[c];  
        for (int i = 0; i < toMatch.size(); i++) {  
            if (iIndex >= input.size() || input[iIndex] != toMatch[i]) {  
                return false;  
            }  
            iIndex++;  
        }  
        if (hashString.find(toMatch) == hashString.end() || c != hashString[toMatch]) {  
          return false;  
        }  
        return isSamePatternHelper(pattern, pIndex + 1, input, iIndex, hash, hashString);  
    } else {  
        // try all possible  
        bool flag = false;  
        for (int i = iIndex; i < input.size(); i++) {  
            string toMatch = input.substr(iIndex, i - iIndex + 1);  
            hash[c] = toMatch;  
            hashString[toMatch] = c;  
            flag |= isSamePatternHelper(pattern, pIndex + 1, input, i + 1, hash, hashString);  
            hash.erase(c);  
            hashString.erase(toMatch);  
            if (flag) {  
                return true;  
            }  
        }  
        return false;  
    }  
}  
   
bool isSamePattern(string& pattern, string& input) {  
    int patternSize = pattern.size();  
    int inputSize = input.size();  
    if (inputSize < patternSize)  
        return false;  
    unordered_map<char, string> hash;  
    unordered_map<string, char> hashString;  
    return isSamePatternHelper(pattern, 0, input, 0, hash, hashString);  
}  
   






