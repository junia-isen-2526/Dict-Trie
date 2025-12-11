//
// Created by JAD on 11/12/2025.
//

#include "Dict.h"

struct Node *createNode(char letter, const char *definition);
int getIndexFromLetter(char index);
void deleteNode(Node *node);
void addToMMD(Dict *dict, FILE *file, int currentId);

struct Node *createNode(const char letter, const char *definition) {
	Node *newNode = malloc(sizeof(Node));
	newNode->letter = letter;
	newNode->definition = NULL;
	for (int i = 0; i < LETTERS_COUNT; i++) {
		newNode->children[i] = NULL;
	}
	return newNode;
}

Dict *createDict() {
	return createNode(' ', NULL);
}

void deleteNode(Node *node) {
	if (node == NULL) return;
	for (int i = 0; i < LETTERS_COUNT; i++) {
		deleteNode(node->children[i]);
	}
	free(node);
}

void deleteDict(Dict *dict) {
	deleteNode(dict);
}

void addWordToDict(Dict *dict, const char *word, const char *definition) {
	if (dict == NULL) return;
	const unsigned int wordLen = strlen(word);
	if (wordLen < 1) return;
	if (dict->children[getIndexFromLetter(word[0])] == NULL) {
		dict->children[getIndexFromLetter(word[0])] = createNode(word[0], NULL);
	}
	if (wordLen == 1) {
		dict->children[getIndexFromLetter(word[0])]->definition = definition;
	} else {
		addWordToDict(dict->children[getIndexFromLetter(word[0])], word + 1, definition);
	}
}

int getIndexFromLetter(const char index) {
	return index - 'a';
}

char *findWordInDict(Dict *dict, const char *word) {
	if (dict == NULL) return NULL;
	const unsigned int wordLen = strlen(word);
	if (wordLen < 1) return dict->definition;
	if (dict->children[getIndexFromLetter(word[0])] == NULL) return NULL;
	return findWordInDict(dict->children[getIndexFromLetter(word[0])], word + 1);
}

void exportMMD(Dict *dict, const char *fileName) {
	if (dict != NULL) {
		FILE *file = fopen(fileName, "w");
		if (file != NULL) {
			fprintf(file, "graph \n", 0);
			fprintf(file, "    0[ROOT]\n");
			addToMMD(dict, file, 0);
			fclose(file);
		}
	}

}

void addToMMD(Dict *dict, FILE *file, int currentId) {
	static int id = 0;
	if (dict != NULL) {
		for (int i = 0; i < LETTERS_COUNT; i++) {
			if (dict->children[i] != NULL) {
				fprintf(file,
						"    %i --> %i(%c)\n",
						currentId,
						++id,
						dict->children[i]->letter);
				if (dict->children[i]->definition != NULL) {
					fprintf(file,
							"    %i -.- %i[%s]\n",
							id, id + 1000,
							dict->children[i]->definition);
				}
				addToMMD(dict->children[i], file, id);
			}
		}
	}
}





