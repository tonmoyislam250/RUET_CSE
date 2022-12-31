#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

char *readline();

int minimumNumber(int n, char *password)
{
    int min[] = {97, 122};
    int maisc[] = {65, 90};
    int num[] = {48, 57};
    int boolea[] = {false, false, false, false};

    for (int i = 0; i < n; i++)
    {
        if (password[i] >= min[0] && password[i] <= min[1])
        {
            boolea[0] = true;
        }
        else if (password[i] >= maisc[0] && password[i] <= maisc[1])
        {
            boolea[1] = true;
        }
        else if (password[i] >= num[0] && password[i] <= num[1])
        {
            boolea[2] = true;
        }
        else
        {
            boolea[3] = true;
        }
    }

    int b = 0;
    int i = 0;

    while (b < 4)
    {
        if (boolea[b] == false)
        {
            i++;
        }
        b++;
    }

    return 6 - n > i ? 6 - n : i;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *n_endptr;
    char *n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char *password = readline();

    int answer = minimumNumber(n, password);

    fprintf(fptr, "%d\n", answer);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data)
        {
            break;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}