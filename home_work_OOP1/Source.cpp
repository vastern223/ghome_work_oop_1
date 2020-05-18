#include<iostream>
#include<fstream>

using namespace std;

#define CLEAR system("cls");

const string filename = "Weapon.txt";

enum Numbers { ZERO = 0, ONE, TWO, THREE, FOUR, FIVE };

class Weapon {

	int range_shot;
	float caliber_weapon;
	int bullets_in_store;
	int maximum_number_of_bullets;

public:

	void Initialize(int range, float caliber, int maxSize, int bullets)
	{
		if (range < ZERO)
		{
			cout << "the range of the shot cannot be negative" << endl;
			return;
		}
		else
		{
			range_shot = range;
		}

		if (caliber < ZERO)
		{
			cout << "caliber cannot be negative" << endl;
			return;
		}
		else
		{
			caliber_weapon = caliber;
		}

		if (maxSize < ZERO)
		{
			cout << "there can be no bullets less than 0 in the store" << endl;
			return;
		}
		else
		{
			maximum_number_of_bullets = maxSize;
		}

		if (bullets < ZERO && bullets > maxSize)
		{
			cout << "there can be no bullets less than 0 in the store and more clamps" << endl;
			return;
		}
		else
		{
			bullets_in_store = bullets;
		}
	}

	bool Shot()
	{
		bool shot = true;

		if (bullets_in_store == ZERO)
		{
			shot = false;
		}
		else
		{
			--bullets_in_store;
		}
		return shot;
	}

	void Recharge()
	{
		bullets_in_store = maximum_number_of_bullets;
	}

	void Save()const
	{
		ofstream fout;
		fout.open(filename);
		bool isOpen_fout = fout.is_open();
		if (isOpen_fout == false)
		{
			cout << " File not open" << endl;
			return;
		}
		else
		{
			fout << range_shot << endl;
			fout << caliber_weapon << endl;
			fout << bullets_in_store << endl;
			fout << maximum_number_of_bullets << endl;
		}
		fout.close();
	}

	void Load()
	{
		ifstream fin;
		fin.open(filename);
		bool isOpen_fin = fin.is_open();
		if (isOpen_fin == false)
		{
			cout << " File not open" << endl;
			return;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> range_shot;
				fin >> caliber_weapon;
				fin >> bullets_in_store;
				fin >> maximum_number_of_bullets;
			}
		}
		fin.close();
	}

};

int main()
{
	Weapon gun;

	int chois = 0;
	do//меню робив для перевірки роботи програми
	{
		cout << ONE << "-Initialize" << endl;
		cout << TWO << "-Shot" << endl;
		cout << THREE << "-Save" << endl;
		cout << FOUR << "-Load" << endl;
		cout << ZERO << "-Exit" << endl;
		cout << ">";
		cin >> chois;
		CLEAR;
		switch (chois)
		{
		case ONE:
		{
			int range_shot_sw = 0;
			float caliber_weapon_sw = 0;
			int bullets_in_store_sw = 0;
			int maximum_number_of_bullets_sw = 0;
			cout << "Enter range shot :";
			cin >> range_shot_sw;
			cout << "Enter caliber weapon :";
			cin >> caliber_weapon_sw;
			cout << "Enter maximum number of bullets :";
			cin >> maximum_number_of_bullets_sw;
			cout << "Enter bullets in store :";
			cin >> bullets_in_store_sw;
			gun.Initialize(range_shot_sw, caliber_weapon_sw, bullets_in_store_sw, maximum_number_of_bullets_sw);
			CLEAR
		}
		break;
		case TWO:
		{
			bool chek = true;

			chek = gun.Shot();

			if (chek == true)
			{
				cout << "the shot was confirmed" << endl;
			}
			else
			{
				cout << "there was no shot confirmed" << endl;
			}

		}
		break;
		case THREE:
		{
			gun.Save();

		}
		break;
		case FOUR:
		{
			gun.Load();
		}
		break;
		case FIVE:
		{
			gun.Recharge();
		}
		case ZERO:
		{
			cout << "Bye";
		}
		break;
		}
	} while (chois != 0);

	system("pause");
	return 0;
}