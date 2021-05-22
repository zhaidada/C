#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*宏定义标准时间*/
#define RYEAR 1 //公园1年
#define RDAY 1 //1.1日星期一
//-----------------------------------函 数 定 义 区------------------------------------------
int calc_year(int year)
//判断平年还是闰年;返回1则为闰年,一年366天
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
//获取月份天数
{
    int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(calc_year(year)==1)
    {
        monthday[2]=29;
    }
    return monthday[month];
}
int calc_day(int year)
//获取输入年份所在年 到基准年的天数  计算当前年份一月一日是星期几   p_count平年数量   r_count闰年数量
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
////////////节日///////////////
void holiday_day(int month,int ii,int i)
{
    switch (month)
    {
        case 1:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d  元旦 |", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d  元旦 ", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 2:
        {
            if(i==6)
            {
                if(ii==14)printf("| %d 情人节|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==14)printf("| %d 情人节",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 3:
        {
            if(i==6)
            {
                if(ii==8)printf("| %d%d 妇女节|", 0,ii);
                else if(ii==14)printf("| %d 植树节|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==8)printf("| %d%d 妇女节", 0,ii);
                else if(ii==14)printf("| %d 植树节",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 4:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d 愚人节|", 0,ii);
                else if(ii==22)printf("| %d 地球日|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 愚人节", 0,ii);
                else if(ii==22)printf("| %d 地球日",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 5:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d 劳动节|", 0,ii);
                else if(ii==12)printf("| %d 护士节|",ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 劳动节", 0,ii);
                else if(ii==12)printf("| %d 护士节",ii);
                else if(ii>=7&&ii<15&&i==0)
                {
                    if(ii<10)printf("| %d%d 母亲节",0,ii);
                    else printf("| %d 母亲节",ii);
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
                if(ii==1)printf("| %d%d 儿童节|", 0,ii);
                else if(ii==5)printf("| %d%d 环境日|",0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 儿童节", 0,ii);
                else if(ii==5)printf("| %d%d 环境日",0,ii);
                else if(ii>15&&ii<21&&i==0)printf("| %d 父亲节",ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;
        case 7:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d 建党节|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 建党节", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;

        case 8:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d 建军节|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 建军节", 0,ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;

        case 9:
        {
            if(i==6)
            {
                if(ii==10)printf("| %d 教师节|", ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==10)printf("| %d 教师节", ii);
                else if(ii<10)printf("|    %d%d    ", 0,ii);
                else printf("|    %d    ",ii);
            }
        }
            break;    
        case 10:
        {
            if(i==6)
            {
                if(ii==1)printf("| %d%d 国庆节|", 0,ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==1)printf("| %d%d 国庆节", 0,ii);
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
                if(ii==25)printf("| %d 圣诞节|", ii);
                else if(ii<10)printf("|    %d%d    |", 0,ii);
                else printf("|    %d    |",ii);
            }
            else
            {
                if(ii==25)printf("| %d 圣诞节", ii);
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
//计算输入月份一号是周几
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
//绘制表头
{
    printf(" _____________________________________________________________________________\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|    日    |    一    |    二    |    三    |    四    |    五    |    六    |\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|__________|__________|__________|__________|__________|__________|__________|\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|          |          |          |          |          |          |          |\n");
}
void chart_day(int month,int i,int monthday)
//表格内填充数字
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
//空余表格绘制
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
//绘制表格尾部
{
    printf("\n");
    printf("|          |          |          |          |          |          |          |\n");
    printf("|__________|__________|__________|__________|__________|__________|__________|\n");
}
void get_time_now(void)
//----------------------------------------主函数-----------------------------------------------
{
    //获取当前时间
    time_t time_now;
    struct tm tm1;
    tzset();
    time(&time_now);
    tm1 = *gmtime(&time_now);
    printf("本地时间：%s", asctime(&tm1));
}
int main()
{
    system("color f2");
    system(" mode con cols=80 lines=80");
    system("title = c语言日历小程序");
    get_time_now();
    start:while(1)
    {
        int year = 0,month = 0;
        int dayday = 0,monthday = 0,kong = 0,i = 0;
        printf("输入年份:");
        scanf("%d", &year);
        printf("\n");
        printf("输入月份:");
        scanf("%d", &month);
        while(month>12||month<1)
        {
            printf("%s\n","月份超过范围");
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
