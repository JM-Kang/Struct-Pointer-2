/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.cc                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/11 11:18:37 by JianMing                                 */
/*   Updated: 2017/10/23 14:41:58 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

Warehouse::Warehouse(void)
{
	name = " ";
	amt[0] = 0;
	amt[1] = 0;
	amt[2] = 0;
}

Warehouse::Warehouse(ifstream& infile)
{
	string f_name;

	infile >> name;
	if(name == "New" || name == "Los")
	{
		infile >> f_name;	
		name = name + " " + f_name;
	}
	else
		name = name ;
	for(int i = 0; i < 3; i++)
		infile >> amt[i];
}

Card::Card(void)
{
	type = 'x';
	name = " ";
	amt[0] = 0;
	amt[1] = 0;
	amt[2] = 0;
}	

Card::Card(ifstream& infile)
{
	string f_name;

	infile >> type;
	infile >> name;
	if(name == "New" || name == "Los")
	{
		infile >> f_name;
		name = name + " " + f_name;
	}
	else
		name = name;
	for(int i = 0; i<3; i++)
		infile >> amt[i];
}
