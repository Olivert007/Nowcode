//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

#include   <iostream> 
#include   <vector> 
#include <string>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		string newString;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				//newString+=iniString[i];
				newString = newString + "%20";
				continue;
			}
			newString += str[i];
		}
		cout << newString << endl;
	}
};

int   main()
{
	char *str = "We are happy";
	int l = strlen(str);

	Solution sol;
	sol.replaceSpace(str, l);

	getchar();
	return 0;

}
