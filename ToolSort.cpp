/*	Author: Timothy Player
 *		Tool Sort
 *			Description:
 *				The goal of ToolSort is to sort the elements of the toolbar in both a 
 *				level based ie all level spells are sorted together in ascending order, 
 *				but also it enables 
 *
 *			Technical:
 *				Tool Sort takes a couple of arguments Firstly an image
 *				avg. pixel value for each RGB pixel then a 4th value
 *				as the MSB the level of the spell (for potions it's like 20 idk just not in the range of 0-10).
 *				You could expand it to a larger key but for me this is enough to demonstrate how it would work.
 *
 *				NOTE: no order is guranteed for the output of identical keys (example LVL 1 spell with same 
 *				RGB avg pixel value of another LVL 1 spell) so two sorts would not place elements with identical keys 
 *				in the same order every time. This is rare but nonetheless should be noted.
 * */

#include <cstring>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;


int main(int argc, char **argv)
{
	char SpellName[256];
	unsigned int key;
	char *c;
	memset(SpellName,0,256);

	//     LvL|R|G|B Spell Name
	multimap<unsigned int, char *> m;
	multimap<unsigned int, char *>::const_iterator mit;

	//I used fread because it's easier than bit shifting.
	while (fread(&key,4,1,stdin))
	{
		c = (char *) &key;
		fread(SpellName,1,1,stdin);
		SpellName[1] = c[3]+'0';
		printf("Key:%u\nSpell Name: %s\n",key,SpellName);
		m.insert(pair<unsigned int, char *>(key,strdup(SpellName)));
	}

	//Printout the characters
	for (mit = m.begin(); mit != m.end(); ++mit)
		 printf("%s\n",((*mit).second));

	for (mit = m.begin(); mit!= m.end(); ++mit)
		free((*mit).second);

	return 0;

}

