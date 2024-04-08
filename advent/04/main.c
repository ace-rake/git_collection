
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "../../libft/header/libft.h"

void	ft_print_lst(t_list *list)
{
	while (list)
	{
		printf("[%i]", list->content);
		list = list->next;
	}
}


int	func(char *str)
{
	int result = 0;
	t_list *winning = NULL;
	t_list *numbers = NULL;
	if (*str == '\n')
		return (0);
	while (*str &&*str != ':')
		str++;
	while (*str && *str != '|')
	{
		if (isdigit(*str))
		{
			ft_lstadd_back(&winning, ft_lstnew(atoi(str)));
			while (isdigit(*str))
				str++;
		}
		else
			str++;
	}
	str++;
	while (*str)
	{
		if (isdigit(*str))
		{
			ft_lstadd_back(&numbers, ft_lstnew(atoi(str)));
			while (str && isdigit(*str))
				str++;
		}
		else
			str++;
	}
	t_list *tmp;
	while (winning)
	{
		tmp = numbers;
		while (tmp)
		{
			if (tmp->content == winning->content)
			{
		//		printf("found [%i]\n", tmp->content);
				result++;
			}
			tmp = tmp->next;
		}
		winning = winning->next;
	}
	return (result);

}

void	multi(t_list *lst, int retval,int amount)
{
	while (retval > 0)
	{
		if (!lst->next)
			lst->next = ft_lstnew(1);
		lst = lst->next;
		lst->content += amount;
		retval--;
	}
}



int	main(void)
{
	FILE *file = fopen("text.txt", "r");	
	int	result = 0;
	char *str;
	str = NULL;
	t_list *winnings = ft_lstnew(1);
	t_list *prev;
	t_list *head = winnings;
		
	size_t n = 0;
	int retval;
	while (getline(&str, &n ,file) != -1)
	{
		printf("\n%s\n",str);
		retval = func(str);
		multi(winnings, retval, winnings->content);
		printf("retval [%i]\n", retval);
//		ft_lstadd_back(&winnings, ft_lstnew(retval));
		printf("\n");
		if (!winnings->next)
			winnings->next = ft_lstnew(1);
		prev = winnings;
		winnings = winnings->next;
		ft_print_lst(head);
		printf("\n");
		printf("\n");
	}
	prev->next = NULL;
	ft_print_lst(head);
	winnings = head;
	while (winnings)
	{
		result += winnings->content;
		winnings = winnings->next;
	}
	printf("\n%i\n", result);
}
