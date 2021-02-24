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
 tracking code
 */
/*
1.Implement an algorithm to determine if a string has all unique characters. What if you
can not use additional data structures
 
实现一个算法来确定字符串是否具有所有唯一的字符。 如果不能使用额外的数据结构怎么办
 
 思路：
 26 个 字母 ，大小写 可以用 16进制进行对应 65-122
 默认字母对应的数组的值为 0;
 遍历存在第一次赋予数值，第二次遍历将其返回
 */

class SolutionOnlyOne{
public:
    int funcOnly(string str)
    {
        //string str = "dhAra";
        bool arr[128] = {0};
        for (unsigned int i = 0; i < str.length() ; i++){
            int val = str[i];  //i think something needs to change here
            cout << val << endl;
            
            if(arr[val]){
                cout << " not unique" ;
                return 0;
            }else{
                arr[val] = 1;
            }
        }
        cout << "unique" ;
        return 0 ;
    }
};






/*
 5.Write a method to replace all spaces in a string with ‘%20’.
 编写一个方法来用“”替换字符串中的所有空格。
 
 思路：
 1. 计算原数组的大小
 2. 重新扩展数组size
 3. 后往前计算数组
 */


class SolutionReplaceSpace {
public:
    string replaceSpace(string s){
        int count = 0; // 统计空格的个数
        int sOldSize = (int)s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        int sNewSize = (int)s.size();
        // 从后先前将空格替换为"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

/*
 6.
 Given an image represented by an NxN matrix, where each pixel in the image is 4
 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
 给定一幅由NxN矩阵表示的图像，其中图像中的每个像素为4字节，编写一种方法将图像旋转90度。 你能把这个做到位吗？
 */

/*
 7.
 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
 column is set to 0.
 编写一个算法，如果MxN矩阵中的一个元素为0，则它的整个行和列被设置为0
 */


/*
 8.
 Assume you have a method isSubstring which checks if one word is a substring of
 another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
 only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
 
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    SolutionOnlyOne *testOne =  new SolutionOnlyOne();
//    string str = "abcda";
//    testOne->funcOnly(str);
    
    SolutionRemoveDuplicates *test =  new SolutionRemoveDuplicates();
    string str = "aabbcc";
    test->removeDuplicates2((char *)str.c_str());
    
}
