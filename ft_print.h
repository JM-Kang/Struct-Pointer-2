/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.h                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/20 20:26:50 by JianMing                                 */
/*   Updated: 2017/10/23 19:39:19 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

#include "testing.h"
#include "struct.h"

using namespace std;

void	ft_print_ware(ofstream&, Warehouse*, int, double);
void	ft_print_card(ofstream&, Card*);
double	print_shippment(ofstream&, Warehouse*, string, int[], int, int, double[]);

#endif
