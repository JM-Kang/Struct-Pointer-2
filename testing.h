/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/15 20:15:50 by JianMing                                 */
/*   Updated: 2017/10/23 19:38:13 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

#include "struct.h"

using namespace std;

double*		get_first_line(string, ifstream&);
int		in_list(Warehouse*, string);
Warehouse*	put_in_warehouse(int, Warehouse*, string, int[]);
double		check_cur_ware(ofstream&, Warehouse*, string, int[], int, double[]);
int		check_other_ware(ofstream&, Warehouse*, string, int[], int);

#endif
