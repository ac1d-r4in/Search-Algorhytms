#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main()
{
	int con, result = 1, count=0;
	char input[100], check[100];
	try
    {
        if (cin.fail()) throw "Wrong input!";
        
		cout << "Enter string: ";
		fgets(input, sizeof(input), stdin);
		cout << "Enter line to search: ";
		fgets(check, sizeof(check), stdin);
    }
    catch (string e)
    {
        cerr << e;
        exit(1);
    }

	if (strlen(check) - 1 > strlen(input) - 1)
	{
		cout << "Line too long!\n";
	}
	else
	{
		int ptmax = strlen(check) - 2;
		for (con = ptmax; con < strlen(input)-1; con++)
		{
			if (check[ptmax] == input[con])
			{
				for (int i = ptmax; i >=0; i--)
				{
					if (check[i] != input[con-ptmax+i])
						result = result * 0;
					else 
                        result = result * 1;
				}
				if (result == 1)
				{
					cout << "Line found at "<<con-ptmax+1<<" position."<<"\n";
					count++;
					break;
				}
				else result = 1;
			}
		}
		if (count == 0)
			cout << "Line not found!\n";
	}
	return 0;
}