//
//  main.cpp
//  erchashu_leetcode
//
//  Created by mingliang on 2020/11/9.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World! erchashu \n";
    
     TreeNode *A = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *B = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *C = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *D = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *E = (TreeNode *) malloc(sizeof(TreeNode));
     TreeNode *F = (TreeNode *) malloc(sizeof(TreeNode));
    
     A->val = 1;
     B->val = 2;
     C->val = 3;
     D->val = 4;
     E->val = 5;
     F->val = 6;
    
     A->left = B;
     A->right = C;
     B->left = D;
     B->right = NULL;
     C->left = F;
     C->right = E;
     D->left = NULL;
     D->right = NULL;
     E->left = NULL;
     E->right = NULL;
     F->left = NULL;
     F->right = NULL;
    return 0;
}
