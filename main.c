#include <stdio.h>
#include "dict.h"

int main(void) {
	Dict *myDict = createDict();
	addWordToDict(myDict, "arbre", "Un truc en bois");
	addWordToDict(myDict, "arme", "Un truc qui tue");
	addWordToDict(myDict, "armee", "des gens qui tuent");
	addWordToDict(myDict, "armure", "Un truc qui protège");
	addWordToDict(myDict, "balle", "Un truc rond");
	addWordToDict(myDict, "ballon", "Un truc qui vole");
	printf("%s\n", findWordInDict(myDict, "arbre"));
	printf("%s\n", findWordInDict(myDict, "arme"));
	exportMMD(myDict, "dict.mmd");
	deleteDict(myDict);
	return 0;
}
