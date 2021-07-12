
/*
技术2题目
堆栈
请用C语言数组实现一个简单栈的基础功能（最大100，数据为int），包括：
初始化一个栈
实现数据入栈功能
查询数据出栈功能
查询栈中的数据个数
获取栈顶元素
释放栈

*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NUM     100


typedef struct  Stackh_
{
	int size;
	int* s;
	int top;
}Stackh;


int initStack(Stackh* st) {
	memset(st,0,sizeof(Stackh));

	int* val = (int*)malloc(sizeof(int)* MAX_NUM);
	if (val) {
		st->s = val;
	}
	else {
		printf("malloc failed");
		return -1;
	}

	st->size = MAX_NUM;
	st->top = -1;
	return 0;

}


int pushInStack(Stackh* st,int val) {
	if (st->top < st->size -1) {
		st->top++;
		st->s[st->top] = val;
	}
	else {
		printf("stack is full max=%d\n",MAX_NUM);
		return -1;
	}
	return 0;

}

int popOutStack(Stackh* st) {
	if (st->top>=0) {
		
		return st->s[st->top--];
	}
	else {
		printf("stack is empty\n");
		return -1;
	}
}


int getTop(Stackh* st) {
	if (st->top>=0) {
		return st->s[st->top];
	}
	else {
		printf("stack is empty\n");
		return -1;
	}
}


int getSize(Stackh* st) {
	return st->top + 1;
}

void UninitStack(Stackh* st) {
	if (st->s) {
		free(st->s);
	}
}