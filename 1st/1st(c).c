#include<stdio.h>
#include<malloc.h>
#include<string.h>

int judge(char a[], int b);

typedef struct
{
	char data[50];      //Õ»ÖÐÔªËØ´æ´¢¿Õ¼ä
	int top;               //Õ»¶¥Ö¸Õë
}SeqStack;

int num = 0;
char save[500];
SeqStack *s;

void main()
{
	int i;
	s = (SeqStack *)malloc(sizeof(SeqStack));
	printf("ÊäÈë\n");
	fgets(save);
	num = strlen(save);
	i = judge(save, num);
	if (i == 1)
		printf("true");
	if (i == 0)
		printf("false");
}

int judge(char a[], int b)
{

	s->top = -1;
	int n;
	for (n = 0; n < b; n++)
	{
		if (a[n] == '(' || a[n] == ')' || a[n] == '{' || a[n] == '}' || a[n] == '[' || a[n] == ']')
		{
			s->top++;
			s->data[s->top] = a[n];
			printf("%d\n", s->top);
			if ((s->data[s->top] == '}'&& s->data[s->top - 1] == '{') || (s->data[s->top] == ')' && s->data[s->top - 1] == '(') || (s->data[s->top] == ']' && s->data[s->top - 1] == '['))
			{
				s->top = s->top - 2;
			}
		}
	}
	if (s->top == -1)
		return 1;
	else
		return 0;
}