#include <stdio.h>
//统计文件的字符数
int count_char(char file[])
{
    int char_num = 0;
    char ch;
    freopen(file, "r", stdin); //重定向输入
    while ((ch = getchar()) != EOF)
    {
        //if (ch != ' '&&ch != '\n'&&ch != '\t')
        char_num++;
    }
    fclose(stdin);
    return char_num;
}

int main(int argc, char *argv[])
{
    //对单个.c文件的统计
    int num_para;
    for (num_para = argc - 1; num_para > 1; num_para--)
    {
        if (strcmp(argv[num_para], "-s") == 0 || strcmp(argv[num_para], "-x") == 0 || strcmp(argv[num_para], "-c") == 0 || strcmp(argv[num_para], "-w") == 0 || strcmp(argv[num_para], "-l") == 0 || strcmp(argv[num_para], "-a") == 0)
        {
            break;
        }
    }
    char filename[500] = {0};
    strcat(filename, argv[num_para + 1]);
    for (int i = num_para + 2; i < argc; i++)
    {
        strcat(filename, " ");
        strcat(filename, argv[i]);
    }
    int flag_3 = check_file_name(filename);
    if (flag_3 == -1)
    {
        printf("Error:The file does not exist !\n");
        return 0;
    }
    else if (flag_3 == -2)
    {
        printf("Error:The file has no read permissions !\n");
        return 0;
    }
    printf("%s:\n", filename);
    for (int i = 1; i <= num_para; i++)
    {
        if (check_command(argv[i]) == 1)
            basic_command(argv[i], filename);
        else
            printf("Command parameter error !\n");
    }
    return 0;
}