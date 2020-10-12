/*	Timothy Player
 *		MakeTest
 *			Description:
 *				Makes test case to be sorted for ToolSort
 *				this includes having like a color  and then some
 *				Corresponding Colors So I randomly take a color 
 *				and a level then put it on an array 
 * */

#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	char lvl,r,g,b,tmp, normalizedLVL;
	char key[4];
	string rgb = "wrygb";
	
	//So this makes a test file for tool sort pretty simple code imo
	for (int i = 0; i < 10; ++i)
	{
		lvl = rand()%10;
		tmp = rgb[rand()%5];
		switch (tmp)
		{
			case 'w':
				r = 0xFF;
				g = 0xFF;
				b = 0xFF;
				break;			
			case 'r':
				r = 0xFF;
				g = 0;
				b = 0;
				break;		
			case 'b':
				r = 0;
				g = 0;
				b = 0xFF;
				break;		
			case 'y':
				r = 0xFF;
				g = 0xFF;
				b  = 0;
				break;		
			case 'g':
				r = 0;
				g = 0xFF;
				b = 0;
				break;
		}

		key[3] = lvl;
		key[2] = r;
		key[1] = g;
		key[0] = b;

		//To check the level ranges we have to offset 0x01 with the char '0'
		fwrite(key,1,4,stdout);
		printf("%c",tmp);
	}

	return 0;
}

