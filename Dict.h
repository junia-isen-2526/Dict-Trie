//
// Created by JAD on 11/12/2025.
//

#ifndef TRIE__DICT_H_
#define TRIE__DICT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LETTERS_COUNT 26

typedef struct Node {
  struct Node *children[LETTERS_COUNT];
  char letter;
  char *definition;

} Node;

typedef Node Dict;

Dict *createDict();
void deleteDict(Dict *dict);

void addWordToDict(Dict *dict, const char *word, const char *definition);
char *findWordInDict(Dict *dict, const char *word);
void exportMMD(Dict *dict, const char *fileName);
#endif //TRIE__DICT_H_
