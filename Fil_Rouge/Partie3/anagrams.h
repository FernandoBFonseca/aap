#include "avl_dic.h"
#include "list_v2.h"
#include "../include/check.h"

typedef struct anagramNode {
	T_list words;
	struct anagramNode *pNext;
} T_anagramNode, * T_anagramList;

T_anagramList sortAddAnaNodeRec(T_node *e, T_anagramList l);
void getAnagrams(T_avl root, T_anagramList *l);
void printAnagrams(T_anagramList anagramsList);
void freeAnagrams(T_anagramList l);