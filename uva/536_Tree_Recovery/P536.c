/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  536  C++  "Binary Tree" */
#include <stdio.h>
#include <string.h>

void go(int n, char *preorder, char *inorder, char *postorder) {
	if(n <= 0) return;
	int p = strchr(inorder, preorder[0])-inorder;
	go(p,preorder+1,inorder,postorder);
	go(n-p-1,preorder+p+1,inorder+p+1,postorder+p);
	postorder[n-1] = preorder[0];
}

int main(int argc, char *argv[]) {
	char *s1="DBACEGF";
	char *s2="ABCDEFG";
	char ans[10];
 	go(strlen(s1),s1,s2,ans);
	ans[10] = '\n';
 	printf("%s\n",ans);

}
/* @END_OF_SOURCE_CODE */

