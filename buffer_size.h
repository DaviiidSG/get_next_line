/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_size.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:26:44 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/21 16:20:25 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE_H
# define BUFFER_SIZE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 2147483646 || BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

#endif
