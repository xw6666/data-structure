#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TreeDataType;

typedef struct BTNode
{
	TreeDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

void GreatBiTree();