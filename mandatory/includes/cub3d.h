/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/20 22:59:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defines.h"
# include "structs.h" 
# include <mlx.h>
# include "stdlib.h"
# include "math.h"
# include "../../libft/libft.h"

// =============================================================================
// INIT MLX
// =============================================================================
int		init_mlx(t_cub3d *cub3d);

// =============================================================================
// ERROR HANDLER
// =============================================================================
void	print_error(char *message);
int		exit_with_message(int status_code, char *message);

#endif
