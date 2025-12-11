#include <stdio.h>
#include "dict.h"

int main(void) {
	Dict *myDict = createDict();
	addWordToDict(myDict, "arbre", "Un truc en bois");
	addWordToDict(myDict, "arme", "Un truc qui tue");
	printf("%s\n", findWordInDict(myDict, "arbre"));
	printf("%s\n", findWordInDict(myDict, "arme"));
	deleteDict(myDict);
	return 0;
}
