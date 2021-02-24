//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

/*
 2.Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
 fve characters, including the null character.)
 编写代码以反转C字符串。 (C-String意味着“abcd”表示为fve字符，包括空字符。)
 */

class SolutionReverse{
    public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
    
    void reverseStr(char *str){
        char *end = str;
        char tmp;
        if (str){
            while(*end){
                ++end;
            }
            --end;
            while(str < end){
                tmp = *str;
                *str++ = *end;
                *end-- = tmp;
            }
        }
    }
};


