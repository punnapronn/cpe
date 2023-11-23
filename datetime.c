#include <stdio.h>
typedef struct datetime {
int date; // 1-31
int month; // 1-12
int year; // 1970++
int dayOfWeek; // 0-6
int hour; // 0-23
int minute; // 0-59
int second; // 0-59
} datetime_t;
int is_leapyear(int y)
{
    if (y % 400 == 0)
        return 1;
    if (y % 100 != 0 && y % 4 == 0)
        return 1;
    return 0;
}
datetime_t createDate(int time) {
    datetime_t start;
    start.month=1;
    start.year=1970;
    start.dayOfWeek=(3+(time/86400))%7;
    int day=time/86400;
    int t=time%86400;
    int month_d[12]={31,28,31,30,31,30,31,31,30,31,30};
    while (day>365){
        if (is_leapyear(start.year)){
            day-=366;
        } else{
            day-=365;
        }
        start.year++;
    }
    if (is_leapyear(start.year)){
        month_d[1]=29;
    }
    for (int i=0;i<12;i++){
        if (day>=month_d[i]){
            day-=month_d[i];
            start.month++;
            printf("%d\n",day);
        } else{
            start.date=1+day;
            break;
        }
    }
    start.hour=t/3600;
    start.minute=(t/60)%60;
    start.second=t%60;
    return start;
}
void printDate(datetime_t start) {
    char day[7][4]={"Mon","Tue" , "Wed", "Thu", "Fri","Sat","Sun"};
    char month[12][4]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("%s %d %s %d %02d:%02d:%02d\n",day[start.dayOfWeek],start.date,month[start.month-1],start.year,start.hour,start.minute,start.second);
}
int main(void) {
datetime_t inputDate;
int timestamp;
scanf("%d", &timestamp);
inputDate = createDate(timestamp);
//printf("%d\n",inputDate.dayOfWeek);
//printf("%d\n",inputDate.date);
//printf("%d\n",inputDate.month);
//printf("%d\n",inputDate.year);
printDate(inputDate);
return 0;
}