/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 18:38:17 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 19:49:52 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "biggest_pal.h"

int		ft_check_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_pal(int *beginw, int *len, char *str, int nb, int start)
{
	int		g;
	int		d;
	int		cpt;

	cpt = 0;
	d = start + (nb / 2);
	if (nb % 2)
		g = start + (nb / 2);
	else
		g = start + (nb / 2) - 1;
	while (g >= 0 && str[g] == str[d])
	{
		if (g == d)
			cpt += 1;
		else
			cpt += 2;
		g--;
		d++;
	}
	if (*len <= cpt)
	{
		*beginw = g + 1;
		*len = cpt;
	}
}

void	ft_biggest_pal(char *str)
{
	char	c;
	int		i;
	int		start;
	int		nb;
	int		len;
	int		beginw;

	i = 0;
	nb = 0;
	beginw = 0;
	len = 0;
	c = str[i];
	if (!(ft_check_str(str)) || !(str[i]))
		return ;
	while (str[i])
	{
		start = i;
		while (str[i] == c)
		{
			nb++;
			i++;
		}
		ft_check_pal(&beginw, &len, str, nb, start);
		nb = 0;
		c = str[i];
	}
	i = beginw;
	while (i < beginw + len)
		write(1, &str[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
