//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int min = rotateArray[0];
		for (int i = 0; i<rotateArray.size(); i++)
		{
			if (rotateArray[i]<min)
				min = rotateArray[i];
		}
		return min;
	}
};

int   main()
{
	vector<int> a = {3,4,5,1,2};

	Solution sol;
	int output;
	output=sol.minNumberInRotateArray(a);
	cout << output << endl;

	getchar();
	return 0;

}

//class Solution {
//public:
//    int minNumberInRotateArray_inOrder(vector<int> rotateArray,int left,int right){
//        int res=rotateArray[left];
//        for(int i=left;i<right;i++){
//            if(res<rotateArray[i])
//                res=rotateArray[i];
//        }
//        return res;
//    }
//    
//    int minNumberInRotateArray(vector<int> rotateArray) {
//		int left=0;
//        int right=rotateArray.size()-1;
//        int mid=left;
//        while(rotateArray[left]>=rotateArray[right]){
//            if(right==left+1){
//                mid=right;
//                break;
//            }
//            mid=(left+right)/2;
//            if(rotateArray[left]==rotateArray[right]&&rotateArray[mid]==rotateArray[left]){
//                return minNumberInRotateArray_inOrder(rotateArray,left,right);
//            }
//            if(rotateArray[mid]>=rotateArray[left])
//                left=mid;
//            else if(rotateArray[mid]<=rotateArray[right])
//                right=mid;
//        }
//        return rotateArray[mid];
//    }
//};
