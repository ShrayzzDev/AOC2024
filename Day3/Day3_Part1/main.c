#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int ParserNumber(FILE *file, char *firstChar)
{
    int num = 0;
    char *current = firstChar;
    char curr_num[3] = "";
    // printf("KASANE TETO !!!!");
    while(isdigit(*current))
    {
        // printf("%c", *current); printf("\n");
        curr_num[num] = *current;
        num++;
        *current = fgetc(file);
    }
    // printf("%d ", atoi(curr_num));
    return atoi(curr_num);
}

int main()
{
    FILE *file = fopen("./dataset.txt", "r");
    if (file == 0)
    {
        perror("ERROR: Could not open file.");
        return 1;
    }
    char* valid_char = "mul(";
    unsigned short current_index = 0;
    char current;
    unsigned long long result = 0;
    int x = 0, y = 0;
    while ((current = fgetc(file)) != EOF)
    {
        // printf("%c %d\n", current, current_index);
        if (!(current == valid_char[current_index]))
        {
            if (current_index == 4)
            {
                // printf(" sag\n");
                x = ParserNumber(file, &current);
                if (current != ',')
                {
                    current_index = 0;
                    continue;
                }
                printf("miku %d\n", x);
                current = fgetc(file);
                y = ParserNumber(file, &current);
                if (current != ')')
                {
                    current_index = 0;
                    continue;
                }
                printf("%d, %d hatsune\n", x, y);
                result += (x * y);
                current_index = 0;
            }
            else
                current_index = 0;
        }
        else
            current_index++;

    }
    printf("%lu\n", result);
    return 0;
}
