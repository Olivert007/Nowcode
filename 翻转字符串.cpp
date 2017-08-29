#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++, pEnd--;
	}
}

char* ReverseSentence(char *pData)
{
	if (pData == nullptr)
		return nullptr;

	char *pBegin = pData;

	char *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			//pBegin = ++pEnd;
			pEnd++;
			pBegin=pEnd;
		}
		else
			pEnd++;
	}

	return pData;
}

int main() {
	char input[] = "We are the World";
	cout << input << endl;
	ReverseSentence(input);
	cout << input << endl;
	system("pause");
	return 0;
}
