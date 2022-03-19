#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
using namespace std;

int hInit(unsigned int strLen)
{
	int d = 31;
	int p = 65713;

	int h = 1;
	for (unsigned int i = 1; i < strLen; i++)
	{
		h = (h * d) % p;
	}
	return h;
}

int ringHash(char *str, unsigned int strLen, int prevHash, int *h)
{
	int d = 31;
	int p = 65713;
	if (*h == 0)
	{
		*h = hInit(strLen);
	}
	if (prevHash == 0)
	{
		for (unsigned int i = 0; i < strLen; i++)
		{
			prevHash += (d * prevHash + (int)str[i]) % p;
		}
		if (prevHash < 0)
 		{
			prevHash += p;
		}
		return prevHash;
	}
	else 
	{
        int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
        if(hash < 0) {
            hash += p;
        }
	}
}
int rabin(char *text, char *str)
{
	unsigned int strLen = strlen(str) - 1;
	unsigned int textLen = strlen(text) - 1;
	int h = 0;
	int result = 0;
	int index;
	int strHash = ringHash(str, strLen, 0, &h);
	int textHash = ringHash(text, strLen, 0, &h);

	for (unsigned int k = 0; k <= (textLen - strLen); k++)
	{
		if (strHash == textHash)
		{
			for (unsigned int i = 0; i < strLen; i++)
			{
				if (str[i] == text[i + k - 1])
					result = result + 1;
				else
					result = result * 0;
			}
		}
		if (result == strLen)
			return k;
		textHash = ringHash(&text[k], strLen, 0, &h);
	}
	if (result != 0)
		return result;
	else
		return -1;
}

int main()
{
	char text[100], str[100];
	text[0] = str[0] = NULL;
	try
	{
		cout << "Enter string: ";
		fgets(text, sizeof(text), stdin);
		if (int(text[0]) == 10)
			throw 1;
		cout << "Enter line to find: ";
		fgets(str, sizeof(str), stdin);
		if (int(str[0] == 10))
			throw 1;
		if (strlen(text) < strlen(str))
			throw 2;
	}
	catch (int e)
	{
		if (e == 1)
			cout << "Empty input!" << endl;
		if (e == 2)
			cout << "String not found!" << endl;
		exit(e);
	}
	int result = (int(text[0]) == 32 && int(str[0] == 32)) ? 1 : rabin(text, str);
	if (result == -1)
		cout << "String not found\n";
	else
		cout << "Line found at " << result << " position\n";
	system("pause");
	return 0;
}