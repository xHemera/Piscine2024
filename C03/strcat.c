char *ft_strcat(char *dest, char *src)
{
  int i = 0;
  int j = 0;

  while (dest[i])
    i++;
  while (src[j])
  {
    dest[i + j] = src[j];
  }
}
