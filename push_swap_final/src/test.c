char *is_valid(char **s)
{
    int i;
    int sign;

	i = 0;
    if (**s == '-' || **s == '+')
    {
        if (**s == '-')
            sign = -1;
        (*s)++;
    }
    while (**s == '0' && *(*s + 1) != '\0')
    {
        (*s)++;
        // if (sign == -1)
        // *s[0] = '-';
    }
    i = 0;
    while ((*s)[i] != '\0')
    {
        if ((*s)[i] == '-' || (*s)[i] == '+')
            return ("no");
        if ((*s)[i] < '0' || (*s)[i] > '9')
            return ("no");
        i++;
    }
    return (*s);
}
