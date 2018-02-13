/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/25 11:22:43 by JianMing                                 */
/*   Updated: 2017/10/25 11:22:47 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <fstream>
#include <iostream>
 
using namespace std;

struct	Warehouse
{
	string		name;
	int		amt[3];
	Warehouse(void);
	Warehouse(ifstream& infile);
};

struct	Card
{
	char		type;
	string		name;
	int 		amt[3];
	Card(void);
	Card(ifstream& infile);
};

#endif
