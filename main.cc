/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/20 19:56:17 by JianMing                                 */
/*   Updated: 2017/10/24 15:41:42 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_print.h"

int	main(void)
{
	ifstream	ca_cin;
	ofstream	ca_out;
	int		pos;
	int		temp;
	double*		p_list;
	double		price;
	Warehouse*	locat;
	Card*		ca_tx;	

	ca_cin.open("data.txt");
	ca_out.open("statement.txt");

	//goes to get_fist_line function to put the prices into an arrays.
	p_list = get_first_line("data.txt", ca_cin);
	locat = new Warehouse[5];
	pos = 0;
	temp = 0;
	price = 0;
	while(ca_cin)
	{
		ca_tx = new Card(ca_cin);
		//check if type is 'E' mean out of data and out of while loop
		if(ca_tx->type == 'E')
			break;
		//print the new card just read in.
		ft_print_card(ca_out, ca_tx);
		temp = in_list(locat, ca_tx->name);

		//only if new card type is s and temp equal to -1.
		//temp equal to -1 mean city nanme is not in warehouse
		if(ca_tx->type == 's' && temp == -1)		
		{		
			locat = put_in_warehouse(pos, locat, ca_tx->name, ca_tx->amt);
			ft_print_ware(ca_out, locat, pos, price);
			pos++;
		}

		//only if new card type is s and the city is on the warehouse list.
		//temp equal to certain position
		else if(ca_tx->type == 's')
		{
			locat = put_in_warehouse(temp, locat, ca_tx->name, ca_tx->amt);
			ft_print_ware(ca_out, locat, temp, price);	
		}

		//only if new card type is o
		else
		{
			price = check_cur_ware(ca_out, locat, ca_tx->name, ca_tx->amt, temp, p_list);
			ft_print_ware(ca_out, locat, temp, price);
			price = 0;			
		}
		ca_out << endl;
		delete ca_tx;
	}
	ca_cin.close();
	ca_out.close();
	return (0);
}			
