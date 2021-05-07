#include <stdio.h>
#include <string.h>

int main(void)
{
    char name2[32] = "admin";
    char name[32];
    int length;
    int res;
    printf("请输入你的名字\n");
    // gets(name);
    fgets(name, sizeof(name), stdin);
    length = strlen(name) - 1;
    printf("你名字的长度是%d\n", length);
    //对比两个值是否相等 strncmp的结果0代表相等
    res = strncmp(name, name2, strlen(name2));
    printf("%d\n", res);
    if (res == 0)
    {
        printf("用户名正确欢迎回来%lu\n", sizeof(name2));
    }
    else
    {
        printf("用户名%lu错误%lu\n", sizeof(name), sizeof(name2));
    }

    return 0;
}
