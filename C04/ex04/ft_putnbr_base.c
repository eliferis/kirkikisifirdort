
#include <unistd.h>

void	ft_putnbr_base_rec(int nbr, char *base, int size)
{
	unsigned int	n;
	char			a;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size) //eger baseden buyukse bolerek devam et
		ft_putnbr_base_rec(n / size, base, size);
	a = base[n % size]; //kalan degeri karakter olarak bul
	write(1, &a, 1); 
}

int		ft_ver_bas(char *base) //bu fonksiyon base gecerli mi diye kontrol eder
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1]) //bosluk, arti eksi veya ayni karakterden iki kez varsa gecersiz
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int s;

	s = 0;
	if (ft_ver_bas(base) == 1) //base gecerliyse
	{
		while (base[s] != '\0') //base uzunlugu hesapla
			s++;
		ft_putnbr_base_rec(nbr, base, s);
	}
}
