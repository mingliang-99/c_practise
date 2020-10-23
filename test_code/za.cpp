//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************

 
 
 
 复杂度解析：
 
 
 
 其他解法：
 
 
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


/*
 队列使用 queue
 队列是先进先出
 push()  队尾部插入
 pop()   最靠前的元素拿掉
 size()  队列中元素的个数
 empty() 判断队列是否为NULL
 front() 返回队列中最先入队的元素
 back()  返回队列中最晚入队的元素
 */

/*
 栈的使用 stack
 栈是先进后出
 empty() 栈为空则返回null
 pop()  移除栈顶元素
 push()  在栈顶增加元素
 size()  返回栈中元素数目
 top() 返回栈顶元素，不删除
 */

/*
 杂题目一 ：  栈相关
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/min-stack
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 示例:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
 
 解题思路：
 
 参考1718ZhangYQ的题解“Python[数据栈+辅助栈]”，设计了主栈和辅助栈，辅助栈中存放的是每个位置所对应的栈内的最小值，因此pop()和getMin()可以直接得到，当push()的时候，判断msta.top()和元素x的关系，进而决定该加入哪个元素，实现如下：
 
 作者：Tangzixia
 链接：https://leetcode-cn.com/problems/two-sum/solution/zui-xiao-zhan-by-tangzixia/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        sta.push(x);
        
        if(msta.empty()||x<=msta.top()){
            msta.push(x);
        }
        
        /*
        if(msta.empty() || x <= msta.top){
            msta.push(x); //辅助栈为null,压栈第一个元素
        }else{ // 目的入栈的元素最小值
            if(x >= msta.top()){
                msta.push(msta.top()); // 压栈的元素 如果 大于 栈顶的元素，将栈顶的元素重新压入栈中
            }else{
                msta.push(x); //压栈的元素
            }
        }
        sta.push(x);
         */
    }
    
    void pop() {
        if(sta.empty())
            return;
        if(sta.top() <= msta.top()){
            msta.pop();
            sta.pop();
        }else{
            sta.pop();
        }
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return msta.top();
    }
private:
    stack<int> sta;  //标准栈
    stack<int> msta;  // 辅助栈 记录最小数值
};



/*
 多个栈实现一个队列
 
 队列是先进先出
 
 */

//栈是先进后出
stack<int> stack1;
stack<int> stack2;
//入队列
void push(const int &data){
    stack1.push(data);
}
//出队列
void Pop()
{
    //如果两个栈都是空栈，此时说明队列是空的
    if (stack1.empty() && stack2.empty())
        cout << "this queue is empty" << endl;
    //如果栈2中有元素，那出队列就出栈2中的
    if (!stack2.empty()){
        stack2.pop();
    }
    //此时表明栈2已是空栈，再要出队列的话，那就需要把栈1中的所有元
    //素入栈到栈2中,注意一定要是栈1中的所有元素都入栈到栈2中
    else{
        while (stack1.size() > 0){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.pop();
    }
}
int & Front()//获取队头元素，此时队头位于栈2的栈顶
{
    // assert(!stack1.empty() || !stack2.empty());
    if (stack2.empty()){
        while (!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    return stack2.top();
}



/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 
 示例 1:
 
 输入: "()"
 输出: true
 示例 2:
 
 输入: "()[]{}"
 输出: true
 
 作者：p12bbb
 链接：https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-p12bbb/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 */
class Solution_isValid {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()&&(s[i]==')'||s[i]=='}'||s[i]==']'))
                return false;    //栈空，遇到右边的括号，直接返回false
            if(s[i]==')'||s[i]=='}'||s[i]==']')  //遇到右边的括号，判断栈顶是否
            {                                 //是对应的左边的括号。
                if(s[i]-st.top()==1||s[i]-st.top()==2)
                    st.pop();   //对应的话，栈顶元素退栈。
                else
                    return false;  //不对应的话，直接返回false。
            }
            else
                st.push(s[i]);   //遇到左边的括号，进栈。
        }
        return st.empty();  //栈空，说明括号都匹配了。
    }
};

/*
  回文数 1221 
 */

class Solution_isPalindrome {
    
       bool isPalindrome(int x) {
        //边界判断
        if (x < 0) return false;
        int div = 1;
        //
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
}



//second 电话号码的字符串组合
/*
 方法：回溯
 
 回溯是一种通过穷举所有可能情况来找到所有解的算法。如果一个候选解最后被发现并不是可行解，回溯算法会舍弃它，并在前面的一些步骤做出一些修改，并重新尝试找到可行解。
 
 给出如下回溯函数 backtrack(combination, next_digits) ，它将一个目前已经产生的组合 combination 和接下来准备要输入的数字 next_digits 作为参数。
 
 如果没有更多的数字需要被输入，那意味着当前的组合已经产生好了。 如果还有数字需要被输入： 遍历下一个数字所对应的所有映射的字母。 将当前的字母添加到组合最后，也就是 combination = combination + letter 。 重复这个过程，输入剩下的数字： backtrack(combination + letter, next_digits[1:]) 。
 
 作者：LeetCode
 链接：https://leetcode-cn.com/problems/two-sum/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class SolutionBack {
public:
    vector<string> output;
    map<char, string> a = { { '2', "abc" },{ '3', "def" }, { '4', "ghi" },
        { '5', "jkl" },{ '6', "mno" },{ '7', "pqrs" },
        { '8', "tuv" },{'9', "wxyz"} };//哈希表存放数字字母对应关系
    void backtrack(string combination, string nextdigits) {
        printf("combination = %s nextdigits %s \n ",combination.c_str(),nextdigits.c_str());
        if (nextdigits.length() == 0) {
            output.push_back(combination);
        }
        else {
            string digits = nextdigits.substr(0, 1);
            string letters = a[digits[0]];
            for (int i = 0; i < letters.length(); i++) {
                string letter = letters.substr(i, 1);
                printf("letter = %s combination %s \n ",letter.c_str(),combination.c_str());
                printf("nextdigits=%s \n ",nextdigits.substr(1,nextdigits.size()-1).c_str());
                
                backtrack(combination+letter, nextdigits.substr(1,nextdigits.size()-1));
            }
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return{};
        backtrack("", digits);
        return output;
    }
};

//整数转罗马数字
//作者：charles10
//链接：https://leetcode-cn.com/problems/two-sum/solution/c-hao-shi-zhan-sheng-100de-jian-dan-ti-jie-by-char/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class SolutionIntToRoman {
public:
    string intToRoman(int num) {
        vector<int> value = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        vector<string> dic = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        string str;
        int i = 0;
        while (num > 0 && i < dic.size()) {
            if (num >= value[i]) {
                str += dic[i]; //字符串拼接
                num -= value[i];//查询数组，做减法，找到所有对应的数值
            }
            else
                i++;
        }
        return str;
    }
    
};

/*
 
 third
 
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 
 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 
 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 
 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/roman-to-integer
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

class SolutionRomanToInt {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i=1; i<s.size(); ++i){
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};


/*
 汉明距离
 */

int hammingDistance(int x, int y) {
    int ans = 0;
    while(x != 0 || y != 0){
        if((x & 1) != (y & 1))
            ans++;
        x>>=1;
        y>>=1;
    }
    return ans;
}





















