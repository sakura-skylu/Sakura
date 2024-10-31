#include <stdio.h>

// 函数用于判断是否为闰年
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int y, d;
    int daysOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i ;
    int month = 1;

    // 读取输入的年份和天数
    scanf_s("%d %d", &y, &d);
    int day = d;

    // 如果是闰年，2月有29天
    if (isLeapYear(y)) {
        daysOfMonth[1] = 29;
    }

    // 遍历月份，直到天数小于当前月的天数
    for (i = 0; i < 12; i++) {
        if (day <= daysOfMonth[i]) {
            month = i + 1;
            printf("%d %d\n", month, day);
            break;
        }
        else {
            day -= daysOfMonth[i];
        }
    }

    return 0;
}