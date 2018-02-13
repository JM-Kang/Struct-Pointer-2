/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/11 11:46:01 by JianMing                                 */
/*   Updated: 2017/10/24 16:01:15 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "ft_print.h"

//check if file can be accessiable and put prices into an arrays
double*	get_first_line(string filename, ifstream& cin)
{
	char		c;
	int		n;
	double*		price;
	
	if(!cin)
		cout << filename << " cannot open, please check." << endl;
	n = 0;
	price = new double[3];	
	while(cin.get(c))
	{
		if(c == '$')
			cin >> price[n++];		
		if(c == '\n')
			break;		 
	}
	return (price);
}

//check if the city is in warehouse and return the position
int	in_list(Warehouse* list, string name)
{
	for(int i = 0; i < 5; i++)
	{
		if(list[i].name == name)
			return (i);
	}
	return (-1);
} 

//put the city into an arrays and put 3 amount of items into an arrays
Warehouse*	put_in_warehouse(int n, Warehouse* list, string name, int amt[])
{
	list[n].name = name;
	for(int i = 0; i < 3; i++)
		list[n].amt[i] += amt[i];
	return (list);
}

//check if the city's warehouse have enough items stock
double	check_cur_ware(ofstream& cout, Warehouse* list, string name, int amt[], int temp, double p_list[])
{
	int	best_fit;
	double	price;

	best_fit = 0;
	price = 0;
	for(int i = 0; i < 3; i++)
	{
		//only is city's warehouse have enough stock
		if(list[temp].amt[i] >= amt[i])
			best_fit = temp; 
		//check other warehouse
		else
			best_fit = (check_other_ware(cout, list, name, amt, i));
		//calculate the price
		price += (print_shippment(cout, list, name, amt, i, best_fit, p_list));
	}
	return (price);	
}

//check other warehouse have enough stock items and return the city position of an arrays
int	check_other_ware(ofstream& cout, Warehouse* list, string name, int amt[], int pos)
{
	int temp;
	int n;

	temp = 0;
	n = -1;
	for (int i = 0; i < 5; i++)
	{
		if(list[i].amt[pos] >= amt[pos])
		{
			if(list[i].amt[pos] > temp)
			{
				temp = list[i].amt[pos];
				n = i;
			}
		}	
	}
	//only if any warehouse do not have enough stock then return -1
	if(n == -1)
		return (-1);
	else
		return (n);
}						
