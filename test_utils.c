void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
		free(ptr);
	}
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
