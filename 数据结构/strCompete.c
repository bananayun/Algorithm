#include<string.h>

int strCompete(String *s, String*t) //�Ƚϴ���С
{
	if (s && t) //���������������Ϊ�գ���׳���жϣ�
	{
		int sl = s->length, tl = t->length; //��¼�������ĳ���
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
		//���ѭ������������һ�����Ѿ���β��
		//��ô�������������һ�����Ӵ�һ��������
		//��ʱ�Ƚ��������ĳ��ȴ�С
		if (sl < tl)
			return -1;
		if (sl == tl)
			return 0;
		if (sl > tl)
			return 1;
	}
}
