#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int l;
    scanf("%d",&l);
    char a[l];
    //���һ����Ч�ַ�---�س�
    getchar();
    //�����ַ���a
    gets(a);
    //����b��26�������ֱ��Ӧ26����ĸ
    int b[26]={0},i;
    //ͳ���ַ����и���ĸ���ֵĴ���
    for(i=0;i<l;i++)
    {
        b[a[i]-'a']++;
    }
    //ͳ�Ƴ��ִ���Ϊ��������ĸ����
    int k=0;
    for(i=0;i<26;i++)
    {
        if(b[i]%2!=0)
            k++;
    }
    //������2�������ϴ���Ϊ��������ĸ
    if(k>=2)
    {
        printf("Impossible");
        exit(0);
    }
    else
    {
        //h���γɻ������������
        //m�������ַ���ʱ��������ĸ�����е�λ���������
        //g���ڸı佻��λ�ó���
        int h=0,g=l,m=0;
        for(i=0;i<(l+1)/2;i++)
        {
            int j;
            //�����Ƿ���ڲ�ͬλ�õ���ͬ��ĸ
            for(j=g-1;j>i;j--)
            {
                //����
                if(a[i]==a[j])
                {
                    while(j<g-1)
                    {
                        //��������Ӧλ��
                        char t;
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                        j++;
                        h++;//��¼����
                    }
                    g--;
                    break;
                }
            }
            //�����ڣ���Ϊ������ĸ
            if(j==i)
                m=(l-1)/2-i;
        }
        printf("%d",h+m);
    }
    return 0;

}
