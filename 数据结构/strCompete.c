#include<string.h>

int strCompete(String *s, String*t) //比较串大小
{
	if (s && t) //传入的两个串都不为空（健壮性判断）
	{
		int sl = s->length, tl = t->length; //记录两个串的长度
		while (*(s->str) != '\0' && *(t->str) != '\0')
		{
			if (*(s->str) < *(t->str))
				return -1;
			if (*(s->str) == *(t->str))
			{
				s->str++;
				t->str++;
			}
			if (*(s->str) > *(t->str))
				return 1;
			s->str++;
			t->str++;
		}
		//如果循环结束，即有一个串已经到尾部
		//那么这种情况，必有一个是子串一个是主串
		//此时比较两个串的长度大小
		if (sl < tl)
			return -1;
		if (sl == tl)
			return 0;
		if (sl > tl)
			return 1;
	}
}
