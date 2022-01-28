#include <unistd.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int check_buff(const char *str, const char symb)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == symb)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	int k = 0;
	int strlen1 = ft_strlen(argv[1]);
	int strlen2 = ft_strlen(argv[2]);
	const int N = strlen1 + strlen2;
	char result[N + 1];
	for (int i = 0; i < N + 1; i++)
		result[i] = '\0';
	for (int i = 0; i < strlen1; i++)
	{
		if (check_buff(result, argv[1][i]) == 1)
		{
			result[k] = argv[1][i];
			k++;
		}
	}
	for (int i = 0; i < strlen2; i++)
	{
		if (check_buff(result, argv[2][i]) == 1)
		{
			result[k] = argv[2][i];
			k++;
		}
	}
	i = 0;
	while(result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}