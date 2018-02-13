/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/20 19:30:20 by JianMing                                 */
/*   Updated: 2017/10/24 15:51:34 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

//print the warehouse infomation and the price of order
void	ft_print_ware(ofstream& cout, Warehouse* loc, int n, double price)
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);

	cout << "Warehouse stock updated: " << endl;
	cout << loc[n].name << "\t";
	for(int i = 0; i < 3; i++)
		cout << loc[n].amt[i] << "\t";
	if(price)
		cout << endl << "Price of Order: $" << price;
	cout << endl;
}

//print the new card information
void	ft_print_card(ofstream& cout, Card* loc)
{
	cout << loc->type << " " << loc->name << "\t";
	for(int i = 0; i < 3; i++)
		cout << loc->amt[i] << "\t";
	cout << endl;
}

//does the calculation and print the shippment informations
double	print_shippment(ofstream& cout, Warehouse* list, string name, int amt[],int amt_pos, int n_pos, double p_list[])
{
	double	price;
	price = 0;

	//if any warehouse have enough stock items then do calculation
	if(n_pos != -1)
	{
		list[n_pos].amt[amt_pos] -= amt[amt_pos];
		//check if this city is not equal to its warehouse 
		if(list[n_pos].name != name) 
		{
			cout << amt[amt_pos] << " of item " << amt_pos + 1;
			cout << " shipped from " << list[n_pos].name;
			cout << " to " << name << endl;
			ft_print_ware(cout, list, n_pos, price);
			price += p_list[amt_pos] * amt[amt_pos] * 1.1;
		}
		//only if this city its warehouse have enough stock items
		else
			price += p_list[amt_pos] * amt[amt_pos];
	} 
	//only if any warehouse do not have enough stock items
	else
		cout << "Item " << amt_pos + 1 << " order unfilled." << endl;
	return (price);
}
