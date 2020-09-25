int ft_isspace(int c)
{
    if ((c >= 9 && c <= 13) || c == ' ')
        return (1);
    else
        return (0);
    
}