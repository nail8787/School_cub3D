#include "cub3d.h"

static void	swap_sprt(t_sprt **head, t_sprt *first, t_sprt *second)
{
	t_sprt	*tmp;
	t_sprt	*root;

	root = *head;
	if (root == first)
	{
		tmp = second->next;
		second->next = first;
		first->next = tmp;
		*head = second;
	}
	else
	{
		while (root->next != first)
			root = root->next;
		tmp = second->next;
		second->next = first;
		first->next = tmp;
		root->next = second;
	}
}

void		sort_sprt(t_img *img)
{
	t_sprt	*tmp;
	int		flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		tmp = img->sprt;
		while (tmp->next != NULL)
		{
			if (tmp->len < tmp->next->len)
			{
				swap_sprt(&img->sprt, tmp, tmp->next);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}

void		find_len_sprt(t_img *img)
{
	t_sprt	*tmp;

	tmp = img->sprt;
	while (tmp != NULL)
	{
		tmp->len = sqrt(pow(img->plr.px - tmp->sx, 2) +
			pow(img->plr.py - tmp->sy, 2));
		tmp = tmp->next;
	}
}
