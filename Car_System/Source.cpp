#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>

using namespace std;

class Cars
{
private:
		int id;
		string model, name,color;
		double price;

	
public:
		void insert_car()
		{
			cout << "Enter ID of the Car    :  " << endl;
			cin >> id;
			cout << "Enter Name of the Car  :  " << endl;
			cin >> name;
			cout << "Enter Model of the Car :  " << endl;
			cin >> model;
			cout << "Enter Color of the Car :  " << endl;
			cin >> color;
			cout << "Enter Price of the Car :  " << endl;
			cin >> price;
		}
		void show_car_info()
		{
			cout << "ID Of the Car	   :	 " << id << endl;
			cout << "Name Of the Car   :	 " << name << endl;
			cout << "Model Of the Car  :	 " << model << endl;
			cout << "Color Of the Car  :	 " << color << endl;
			cout << "Price Of the Car  :	 " << price << endl;

		}
		int car_id()
		{
			return id;
		}
		string car_name()
		{
			return name;
		}
		string car_model()
		{
			return model;
		}
		string car_color()
		{
			return color;
		}
		double car_price()
		{
			return price;
		}
};
Cars car;

    void write_car()
	{
		fstream fc;
		fc.open("shop.txt", ios::in | ios::app);
		car.insert_car();
		fc.write((char*)&car, sizeof(Cars));
		fc.close();

	}
	void show_car()
	{
		fstream fc;
		//fc.read((char*)&car, sizeof(Cars));
		cout << "The ALL Car In The Office :" << endl;
		fc.open("shop.txt", ios::in );
		while (fc.read((char*)&car, sizeof(Cars)))
		{
			car.show_car_info();
			cout << "\n\n************************************************\n\n";
		}
		fc.close();
	}
	void search_car(int num)
	{
		fstream fc;
		int cou = 0;
		fc.open("shop.txt", ios::in);
		while (fc.read((char*)&car, sizeof(Cars)))
		{
			if (car.car_id() == num)
			{
				car.show_car_info();
				cout << "\n\n************************************************\n\n";
				cou = 1;
			}
		}
		if (cou == 0)
			cout << "Un Found !" << endl;
		fc.close();
	}
	void sell_car(int num)
	{
		fstream fc1, fc2;
	
		//cout << "Enter The ID Car You Went To Buy :	 " << endl;
	   //cin >> num;
		fc1.open("shop.txt", ios::in | ios::out);
		fc2.open("office.txt", ios::out);
		fc1.seekg(0, ios::beg);
		while (fc1.read((char*)&car, sizeof(Cars)))
		{
			if (car.car_id() != num)
			{
				fc2.write((char*)&car, sizeof(Cars));
			}
		}
		fc2.close();
		fc1.close();
		remove("shop.txt");
		rename("office.txt", "shop.txt");
		//cout << " The Car Buied Successfully !" << endl;
	}
	void reblace_car(int num)
	{
		fstream fc1 ,fc2;
		int cou = 0;
		fc1.open("shop.txt",ios::in );
		fc2.open("office.txt", ios::out );
		
		//fc1.seekg(0, ios::beg);
		while (fc1.read((char*)&car, sizeof(Cars)))
		{
			if (car.car_id() != num)
			{
				fc2.write((char*)&car, sizeof(Cars));
				
			}
			else
			{
				cout << "Your Car is Found ! \n Enter The Data of A New Car : \n";
				write_car();
				cout << "Updated Successd !" << endl;
				cou = 1;
				
				//break;
			}
			
		}
         if (cou == 0)
			cout << "\n Car Not Found ! \n ";
		fc2.close();
		fc1.close();
	    remove("shop.txt");
	    rename("office.txt", "shop.txt");
	}
	void main()
	{
		char ch ,choice;
		int num ,id1 ,id2;
		cout << "\n";    //welcome screen
		cout << "              **      :::::::  !!!!!!!!           \n";
		cout << "           _____  **      ::       !!    !!         _____  \n";
		cout << "                **      ::       !!    !!                \n";
		cout << "              ******  :::::::  !!!!!!!!            \n";
		cout << "\n\n";
		cout << "	       ~ __  ~ __  ~ __                  \n";
		cout << "	        |==|  |==|  |==|                 \n";
		cout << "	      __|__|__|__|__|__|_                \n";
		cout << "	    _|___________________|___            \n";
		cout << "    __|__[]__[]__[]__[]__[]__[]__|___        \n";
		cout << "    |..........................o........./ \n";
		cout << "    \\...................................../ \n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << " ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
		cout << "  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n";
		cout << "    ~    ~     ~    ~    ~    ~    ~    ~    ~  \n";
		cout << "=====================================================================================================================\n";
		cout << "\n Do you Want to Start [Y-N]  :  ";
		cin >> ch;

		while (ch == 'Y' || ch == 'y' )
		{
		


			cout << "\t\t\n\n The Aveliable Option In Our Office :-  ";
			cout << " \n\n\t [1] - BUY A CAR    :  ";
			cout << " \n\n\t [2] - SELL A CAR   :  ";
			cout << " \n\n\t [3] - SEARCH A CAR :  ";
			cout << " \n\n\t [4] - Reblace A CAR:  ";
			cout << " \n\n\t [5] - EXIT         :  ";

			cout << " \n\n\t  * Your Choice From (1 ~ 5) \n\n";
			cin >> choice;

			switch (choice)
			{
	   		case '1':
				 {
					write_car();
					cout << "\n Buy of a Car Successd ! \n";
					break;
				 }
			case '2':
				 {
					show_car();
					cout << "Enter The ID Car You Went To sell :	 "<< endl;
					cin >> id1;
					sell_car(id1);
					cout << " The Car Selled Successfully !" << endl;
					break;
	       		}
			case '3':
	    		{
					//int num;
					cout << "Enter The ID Car You Went To Search it  :	 " << endl;
					cin >> num;
					search_car(num);
					break;
	    		}
			case '4':
	     		{
					cout << "Enter The Id of  A car You went Rablace :  " << endl;
					cin >> id2;
					reblace_car(id2);
					break;
				}
			default:
			   {
					cout << " Your Choice is UnFound !" << endl;
					exit(0);
				}
				cout << "Return to the Aveliable Option [Y-N]";
				cin >> ch;
			
			}

		} 

		system("pause");

	}
	