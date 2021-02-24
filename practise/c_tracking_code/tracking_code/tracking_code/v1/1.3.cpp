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
 3.
 Design an algorithm and write code to remove the duplicate characters in a string
 without using any additional bufer. NOTE: One or two additional variables are fne.
 An extra copy of the array is not.
 FOLLOW UP
 Write the test cases for this method
 
 设计一个算法并编写代码来删除字符串中的重复字符，而不使用任何额外的bufer。 注：一个或两个附加变量是FNE。 数组的额外副本不是 。 后续编写此方法的测试用例
 
 思路：
 从第二个元素开始遍历数组，与前面子数组中的元素比较，
 如果有相等的元素，跳到下一个元素比较，
 否则把元素插入到前面子数组的后面，标记向后加一，（tail 为不相等的数组的末尾）
 在最后还要在子数组后面添加字符结束标记 ‘0’
 
 比如： aabbcc  ,
 第一次匹配后  abbbcc
 第二次匹配后  abcbcc
 最后在在tail 位置的后面加上‘\0’ 字符串为 “abc”
 */

class SolutionRemoveDuplicates{
    public:
    void removeDuplicates(string str){
        int len = (int)str.length();
        if(len < 2) return;
        int tail = 1;
        for(int i = 1; i < len; ++i){
            int j;
            for(j = 0; j < tail; ++j){
                
                if(str[i] == str[j]){
                    break;
                }
            }
            if(j == tail) // no dumplicate ,move str[i] to str[tail]
            {
                str[tail] = str[i];
                ++tail;
            }
        }
        str[tail] = 0;// end
        
        return;
    }
    
   void removeDuplicates2(char *str)
   {
       if(str==NULL)
           return;
       int len=(int)strlen(str);
       if(len<2)
           return;
       int tail=1;
       for(int i=1;i<len;++i){
           int j;
           for(j=0;j<tail;++j){
               if(str[i]==str[j])
                   break;
           }
           if(j==tail) //把相等的字符串的最后一个放到，tail的位置，
           {
               str[tail]=str[i];
               ++tail;
           }
           
       }
       str[tail]=0;
       printf("%s\n",str);
   }
};



