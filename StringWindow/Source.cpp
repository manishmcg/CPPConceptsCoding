#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
	Solution() {
		for (int i = 0; i < 26; i++)
			charMap[i] = 0;
	}
	vector<int> findSubStrWindow(string str, string substr)
	{
		vector<int> subStrWindow;
		int strLen = str.size();
		int substrLen = substr.size();
		if (strLen == 0 || substrLen == 0)
			return subStrWindow;
		int start_pos;
		int end_pos;
		int windowSize = 0;
		
		for (int i = 0; i < strLen; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				charMap[str[i] - 'a'] += 1;
		}
		//check if exist 
		if (!isExist(charMap, substr, substrLen))
		{
			return subStrWindow;
		}
		{
			for (start_pos = 0; start_pos < strLen; start_pos++)
			{
				if (str[start_pos] >= 'a' && str[start_pos] <= 'z')
					charMap[str[start_pos] - 'a'] -= 1;
				if (!isExist(charMap, substr, substrLen))
				{
					charMap[str[start_pos] - 'a'] += 1;
					break;
				}
			}
			for (end_pos = strLen - 1; end_pos >= start_pos; end_pos--)
			{
				if (str[end_pos] >= 'a' && str[end_pos] <= 'z')
					charMap[str[end_pos] - 'a'] -= 1;
				if (!isExist(charMap, substr, substrLen))
				{
					break;
				}
			}
			windowSize = end_pos - start_pos + 1;
			subStrWindow.push_back(start_pos);
			subStrWindow.push_back(end_pos);
		}
		{
			for (int i = 0; i < 26; i++)
			{
				charMap[i] = 0;
			}
			for (int i = 0; i < strLen; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					charMap[str[i] - 'a'] += 1;
			}

			for ( end_pos = strLen - 1; end_pos >= 0; end_pos--)
			{
				if (str[end_pos] >= 'a' && str[end_pos] <= 'z')
					charMap[str[end_pos] - 'a'] -= 1;
				if (!isExist(charMap, substr, substrLen))
				{
					charMap[str[end_pos] - 'a'] += 1; 
					break;
				}
			}
			for ( start_pos = 0; start_pos <= end_pos; start_pos++)
			{
				if (str[start_pos] >= 'a' && str[start_pos] <= 'z')
					charMap[str[start_pos] - 'a'] -= 1;
				if (!isExist(charMap, substr, substrLen))
				{
					charMap[str[start_pos] - 'a'] += 1;// no need of this
					break;
				}
			}
			
			if (windowSize > (end_pos - start_pos + 1)) {
				subStrWindow[0] = start_pos;
				subStrWindow[1] = end_pos;
			}
		}
		return subStrWindow;
	}
private:
	int charMap[26];
	bool isExist(int charMap[], string substr, int substrLen)
	{
		for (int i = 0; i < substrLen; i++)
		{
			if (charMap[substr[i] - 'a'] == 0 )
				return false;
		}
		return true;
	}
};
int main()
{
	Solution obj;
	string str = "my name is manish chanmeisdra";
	string substr = "meis";
	vector<int> subStrWindow = obj.findSubStrWindow(str, substr);
	if (subStrWindow.size() > 0)
		cout << subStrWindow[0] << " " << subStrWindow[1] << endl;
	return 0;
}