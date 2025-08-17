

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648) //integer minimum = -2147483648
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648; / Kalanını yazmak için sayıyı değiştir
	}
	if (nb < 0) //sign changing
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10) //'0' chars ascii value is equal to 48. we turn the number to char. Sayı tek basamaklıysa (0-9) direkt karaktere cevirilip yazilir.
	{
		ft_putchar(nb + 48);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}



int main(void)
{
	ft_putnbr(42);         // 42
	write(1, "\n", 1);
	ft_putnbr(-123);       // -123
	write(1, "\n", 1);
	ft_putnbr(0);          // 0
	write(1, "\n", 1);
	ft_putnbr(-2147483648); // -2147483648
	write(1, "\n", 1);
	ft_putnbr(2147483647);  // 2147483647
	write(1, "\n", 1);
}
