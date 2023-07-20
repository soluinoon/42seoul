/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:56:26 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 13:50:26 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	count_strs2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	bubble2(char **tab, int size, int(*cmp)(char *, char*))
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{	
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	str_count;

	str_count = count_strs2(tab);
	bubble2(tab, str_count, cmp);
}
