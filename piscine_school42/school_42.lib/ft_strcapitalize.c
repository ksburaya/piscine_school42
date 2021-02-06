/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:18:23 by machanse          #+#    #+#             */
/*   Updated: 2021/01/23 19:28:03 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	if (*str >= '0' && *str <= '9')
	{
		return (1);
	}
	return (0);
}

int		ft_str_is_alpha(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		return (1);
	}
	if (*str >= 'A' && *str <= 'Z')
	{
		return (1);
	}
	return (0);
}

int		ft_is_word(char *str)
{
	if (ft_str_is_numeric(str) || ft_str_is_alpha(str))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int				is_prev_alpha_numeric_char;
	unsigned int	i;

	is_prev_alpha_numeric_char = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (!is_prev_alpha_numeric_char && ft_str_is_alpha(str + i))
		{
			str[i] -= 32;
			is_prev_alpha_numeric_char = 1;
		}
		else if (ft_is_word(str + i))
		{
			is_prev_alpha_numeric_char = 1;
		}
		else
		{
			is_prev_alpha_numeric_char = 0;
		}
		i += 1;
	}
	return (str);
}
