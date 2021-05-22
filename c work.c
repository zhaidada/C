#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*�궨���׼ʱ��*/
#define RYEAR 1 //��԰1��
#define RDAY 1 //1.1������һ
//-----------------------------------�� �� �� �� ��------------------------------------------
int calc_year(int year)
//�ж�ƽ�껹������;����1��Ϊ����,һ��366��
{
    if( year%400==0 || ( year%4==0 && year%100!=0 ))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int calc_month(int year,int month) 
//��ȡ�·�����
{
    int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(calc_year(year)==1)
    {
        monthday[2]=29;
    }
    return monthday[month];
}
int calc_day(int year)
//��ȡ������������� ����׼�������  ���㵱ǰ���һ��һ�������ڼ�   p_countƽ������   r_count��������
{
    int day = 0;
    int weekday = 0;
    int i = 0;
    int r_count = 0;
    int p_count = 0;
    if(year>=1)
    {
        for(i = RYEAR; i<year; i++)
        {
            if(calc_year(i)==1)
            {
                r_count = r_count + 1;
            }
            else
            {
                p_count = p_count + 1;
            }
        }
        day = day + p_count*365 + r_count*366;
        weekday = day%7;
        return weekday+RDAY;
    }
    else
    {
        for(i = RYEAR; year<i; year++)
        {
            if(calc_year(year)==1)
            {
                r_count = r_count + 1;
            }
            else
            {
                p_count = p_count + 1;
            }
        }
        day = day + p_count*365 + r_count*366;
        weekday = day%7;
        return 7-weekday+RDAY;  
    }

}
////////////����///////////////
void holiday_day(int month,int ii,int i)
{
    switch (month)
    {
        case 1:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d  Ԫ�� |", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d  Ԫ�� ", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 2:
        {
            if(i==6)
            {
                if(ii==14)printf("| %d ���˽�|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==14)printf("| %d ���˽�",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 3:
        {
            if(i==6)
            {
                if(ii==8)printf("| %d%d ��Ů��|", 0,ii);
                else if(ii==14)printf("| %d ֲ����|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==8)printf("| %d%d ��Ů��", 0,ii);
                else if(ii==14)printf("| %d ֲ����",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 4:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d ���˽�|", 0,ii);
                else if(ii==22)printf("| %d ������|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d ���˽�", 0,ii);
                else if(ii==22)printf("| %d ������",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 5:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d �Ͷ���|", 0,ii);
                else if(ii==12)printf("| %d ��ʿ��|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d �Ͷ���", 0,ii);
                else if(ii==12)printf("| %d ��ʿ��",ii);
                else if(ii>=7&&ii<15&&i==0)
                {
                    if(ii<10)printf("| %d%d ĸ�׽�",0,ii);
                    else printf("| %d ĸ�׽�",ii);
                }
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 6:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d ��ͯ��|", 0,ii);
                else if(ii==5)printf("| %d%d ������|",0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d ��ͯ��", 0,ii);
                else if(ii==5)printf("| %d%d ������",0,ii);
                else if(ii>15&&ii<21&&i==0)printf("| %d ���׽�",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 7:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d ������|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d ������", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;

        case 8:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d ������|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d ������", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;

        case 9:
        {
            if(i==6)
            {
                if(ii==10)printf("| %d ��ʦ��|", ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==10)printf("| %d ��ʦ��", ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;    
        case 10:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d �����|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d �����", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 11:
        {
            if(i==6)
            {
                if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 12:
        {
            if(i==6)
            {
                if(ii==25)printf("| %d ʥ����|", ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==25)printf("| %d ʥ����", ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        default:
            break;
    }
}
int which_day(int month,int year)
//���������·�һ�����ܼ�
{
    int date_day=0,month2=0;
    int week_day=0;
    for(month2 = 0; month2<month; month2++)
    {
        date_day = date_day + calc_month(year,month2);
    }
    week_day = (date_day%7 + calc_day(year))%7;
    return week_day;
}
void head()
//���Ʊ�ͷ
{
    printf(" _____________________________________________________________________________\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|    ��    |    һ    |    ��    |    ��    |    ��    |    ��    |    ��    |\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|__________|__________|__________|__________|__________|__________|__________|\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|          |          |          |          |          |          |          |\n");
}
void chart_day(int month,int i,int monthday)
//������������
{
    for(int iii=0;iii<i;iii++)
    {
        printf("|          ");
    }
    for(int ii=1;ii<=monthday;ii++)
    {
        i = i%7;
        if(i==6)
        {
            holiday_day(month,ii,i);
            printf("\n");
            printf("|          |          |          |          |          |          |          |\n");
            printf("|__________|__________|__________|__________|__________|__________|__________|\n");
            printf("|          |          |          |          |          |          |          |\n");
            printf("|          |          |          |          |          |          |          |\n");        
        }
        else
        {
            holiday_day(month,ii,i);
        }
        i = i+1;
    }
}
void last_chart(int year,int month)
//���������
{
    int kong=0;
    int dayday=0,w=0;
    w = which_day(month,year);
    dayday = calc_month(year,month);
    kong = 35-dayday-w;
    dayday = calc_month(year,month);
    kong = 35-dayday-w;
    if(kong>0)
    {
        for(int ddd = 0;ddd<=kong;ddd++)
        {
            printf("|          ");
        }
    }
    else if(kong<=0)
    {
        kong = 42-dayday-w;
        for(int ddd = 0;ddd<=kong;ddd++)
        {
            printf("|          ");
        }
    }
}
void tail(void)
//���Ʊ��β��
{
    printf("\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|__________|__________|__________|__________|__________|__________|__________|\n");
}
void get_time_now(void)
//----------------------------------------������-----------------------------------------------
{
    //��ȡ��ǰʱ��
    time_t time_now;
    struct tm tm1;
    tzset();
    time(&time_now);
    tm1 = *gmtime(&time_now);
    printf("����ʱ�䣺%s", asctime(&tm1));
}
int main()
{
    system("color f2");
    system(" mode con cols=80 lines=80");
    system("title = c��������С����");
    get_time_now();
    start:while(1)
    {
        int year = 0,month = 0;
        int dayday = 0,monthday = 0,kong = 0,i = 0;
        printf("�������:");
        scanf("%d", &year);
        printf("\n");
        printf("�����·�:");
        scanf("%d", &month);
        while(month>12||month<1)
        {
            printf("%s\n","�·ݳ�����Χ");
            goto start;
        }
        printf("\n");
        i = which_day(month,year);
        monthday = calc_month(year,month);
        head();
        chart_day(month,i,monthday);
        last_chart(year,month);
        tail();
    }
    return 0;
    system("pause");
}
