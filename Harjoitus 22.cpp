/*Harjoitus 22 (Palautus vko 49)
Tee ohjelma, joka toimii henkilörekisterinä(max 10).
Ohjelma antaa käyttäjälle seuraavan valikon :

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta kaikki henkilot

Tallenna henkilöiden tiedot tietuetaulukkoon.
Tallennettavia tietoja ovat
etunimi(merkkijono)
koulumatka(liukuluku)
hatun koko(kokonaisluku)

Toteuta ensin koko ohjelma pääohjelmana.

Tämän jälkeen lisää seuraavat aliohjelmat :
a) int Valikko(void);

b) void TulostaHenkilo(TIEDOT);
c) void TulostaKaikkiHenkilot(TIEDOT[], int lkm);
d) void LisaaHenkilo(TIEDOT[], int *lkm);*/
//************************
//Tapio Pekkarinen
//Harjoitus 22
//27.11.2014
//versio 1.0
#include <iostream>
using namespace std;

const int MAX_TAULU = 10;
struct hlot
{
	char etunimi[10];
	float koulumatka;
	int hattu;
};
void TulostaHenkilo(hlot);
void TulostaKaikkiHenkilot(hlot [], int lkm);
void LisaaHenkilo(hlot [], int *lkm);
int Valikko(void);
int main()
{
	hlot i[MAX_TAULU];
	int ind1 = 0;
	
	
	int valinta;
	do
	{
		valinta = Valikko();
		

		switch (valinta)
		{
		case 0: cout << "Loppu";
			break;

		case 1:
			LisaaHenkilo(i,&ind1);
			/*cout << "Anna etunimi, koulumatkan pituus ja hatun koko ";
			cin >> i[ind1].etunimi >> ws >> i[ind1].koulumatka >> ws >> i[ind1].hattu;
			ind1++;*/
			break;

		case 2:
			int luku;
			cout << "Valitse henkilö 1-10 ";
			cin >> luku;
			TulostaHenkilo(i[luku - 1]);
			//cout << "Nimi: " << i[luku - 1].etunimi << "\n" << "Koulumatka: " << i[luku - 1].koulumatka << "\n" << "Hatun koko: " << i[luku - 1].hattu << endl;
			break;

			
		case 3:
			TulostaKaikkiHenkilot(i,ind1);
			//for (int ind = 0; ind<kpl; ind++)
				//cout << "Nimi: " << i[ind].etunimi << "\n" << "Koulumatka: " << i[ind].koulumatka << "\n" << "Hatun koko: " << i[ind].hattu << endl;

			break;

		default:	cout << "\nVirhe: ei ko. toimintoa!";
			break;
		}

	} while (valinta != 0);

	return 0;

}	
void TulostaHenkilo(hlot p_i)
{
	cout << "\nHenkilon tiedot" << endl;
	cout << "Nimi: " << p_i.etunimi << "\n" << "Koulumatka: " << p_i.koulumatka << "\n" << "Hatun koko: " << p_i.hattu << endl;
}

int Valikko(void)
{
	int valinta;
	cout << "VALIKKO";
	cout << "\n\n1 Lisää henkilo ";
	cout << "\n2 Näytä henkilo";
	cout << "\n3 Näytä kaikki henkilot";
	cout << "\n0 Lopeta ";
	cin >> ws >> valinta;
	return valinta;
}

void TulostaKaikkiHenkilot(hlot i[], int kpl)
{
	
	for(int ind = 0; ind<kpl; ind++)
		cout << "Nimi: " << i[ind].etunimi << "\n" << "Koulumatka: " << i[ind].koulumatka << "\n" << "Hatun koko: " << i[ind].hattu << endl;
}

void LisaaHenkilo(hlot i[], int *kpl)
{
	
	cout << "Anna etunimi, koulumatkan pituus ja hatun koko ";
	cin >> i[*kpl].etunimi >> ws >> i[*kpl].koulumatka >> ws >> i[*kpl].hattu;
	(*kpl)++;
	
}
