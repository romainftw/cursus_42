/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:07:15 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/04 18:02:34 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int arc, char **arg)
{
	if (arc != 2)
		return (0);
		if(pars_first(arg[1]))
			printf("DOPE\n");
		else 
			printf("NOPE");
	return (0);
}
