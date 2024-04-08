#ifndef HEADER_H
#define HEADER_H

typedef struct s_list{
	int numb;
	struct s_list *next;
}				t_list;

typedef struct s_map
{
	char sym;
	int next_to_active;
}				t_map;

#endif
