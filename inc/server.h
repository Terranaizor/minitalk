/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:16:07 by nradin            #+#    #+#             */
/*   Updated: 2023/01/28 15:26:26 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>
# include <sys/signal.h>

typedef struct s_temp_state{
	int		i;
	char	prog_char;
	int		client_pid;
}t_temp_state;

#endif
