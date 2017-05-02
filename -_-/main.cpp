#include<iostream>
#include<cstdlib>
using namespace std;
int x, y;                   //wspó³rzêdne planszy
int odlicz = 0;    //wyœwietlanie wspó³rzêdnych planszy
int k = 0;
class pole
{
public:
	enum stan
	{
		zywe = 1,
		martwe = 0
	};
	stan stan_pola;
	pole()
	{
		stan_pola = stan::martwe;
	}
	
};
pole plansza[20][20];
void rysuj()
{
	cout << "    ------------------ " << endl;
	cout << "   | by Aneta Brzycka |" << endl;
	cout << "    ------------------ " << endl << endl;
	odlicz = 0;
	cout << "  ";
	for (int i = 1; i < 21; i++)
	{
		if (i < 10)
		{
			cout << "  " << i;
		}
		else
		{
			cout << " " << i;
		}
	}
	cout << endl;
	for (int y = 0; y < 20; y++)
	{
		odlicz++;
		if (odlicz < 10)
		{
			cout << " " << odlicz << " ";
		}
		else
		{
			cout << odlicz << " ";
		}
		for (int x = 0; x < 20; x++)
		{
			if (plansza[x][y].stan_pola == pole::stan::martwe)
			{
				cout << "   ";
			}
			if (plansza[x][y].stan_pola == pole::stan::zywe)
			{
				cout << " * ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	rysuj();
	while (k == 0)
	{
		cout << endl;
		cout << "Podaj wspolrzedne [x y]: ";
		cin >> x;
		if ((x < 0) || (x > 10))
		{
			system("cls");
			main();
		}
		cout << " ";
		cin >> y;
		if ((y < 0) || (y > 20))
		{
			system("cls");
			main();
		}
		if (plansza[x - 1][y - 1].stan_pola == pole::stan::martwe)
		{
			system("cls");
			plansza[x - 1][y - 1].stan_pola = pole::stan::zywe;
			rysuj();
		}
		else
		{
			system("cls");
			plansza[x - 1][y - 1].stan_pola = pole::stan::martwe;
		}


	}
	cin.get();
	return 0;
}