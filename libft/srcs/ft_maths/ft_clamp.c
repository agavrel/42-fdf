int		ft_clamp(int n, int min, int max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
