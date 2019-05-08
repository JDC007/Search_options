#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
string printoptions()
{
    cout << "Please select a search option from below: " << endl;
    cout << "1. Search all parameters by a city name" << endl;
    cout << "2. Search all data of a specific parameter" << endl;
    cout << "3. Search all parameters' data by a specific date" << endl;
    cout << "4. Search all parameters' data by a year" << endl;
    cout << "5. Search all parameters' data by a month" << endl;
    cout << "6. Search all parameters' data by a date" << endl;
    cout << "7. Exit the program" << endl;

    string op;
    cout << "Enter your choice: ";
    getline(cin, op);

    if (op[op.length()-1] == '\n')
        op.erase(op.length()-1);

    return op;
}

int main()
{
    ifstream ip("data.csv");
    if(!ip.is_open())
        cout << "ERROR: File not found!" << '\n';

    string dt, cty, temp, lgt, airq, sd, hd, ds;
    vector <string> date;
    vector <string> city;
    vector <string> temperature;
    vector <string> light;
    vector <string> airquality;
    vector <string> sound;
    vector <string> humidity;
    vector <string> dust;

    //int cnt = 0; for loading specific amount of data
    while(ip.good())
    {
        getline(ip, dt, ',');
        getline(ip, cty, ',');
        getline(ip, temp, ',');
        getline(ip, lgt, ',');
        getline(ip, airq, ',');
        getline(ip, sd, ',');
        getline(ip, hd, ',');
        getline(ip, ds, '\n');

        date.push_back(dt);
        city.push_back(cty);
        temperature.push_back(temp);
        light.push_back(lgt);
        airquality.push_back(airq);
        sound.push_back(sd);
        humidity.push_back(hd);
        dust.push_back(ds);
/*
        cnt++;
        if(cnt == 35)
           break; */
    }
/*
    for(int i=0; i<20; i++)
    {
        cout << date[i] << " " << city[i] << " " << temperature[i] << endl;
    }
*/

    while(1)
    {
        string opt = printoptions();

        if(opt == "1")
        {
            string user_city;
            cout << "Please enter a city name (ex: Geneva): ";
            getline(cin, user_city);
            cout<<"\nAll the environmental data of " << user_city << ":" <<endl;
            int flag = 0;
            cout << "    " << date[0] << "             " << city[0] << "       " << temperature[0] << " " << light[0] << " " << airquality[0] << " " << sound[0] << " " << humidity[0] << " " << dust[0] << endl;

            for (int i=0; i<city.size(); i++)
            {
                if(city[i] == user_city)
                {
                    cout << date[i] << " " << city[i] << "     " << temperature[i] << "  " << light[i] << "   " << airquality[i] << "  " << sound[i] << " " << humidity[i] << " " << dust[i] << endl;
                }
                else
                {
                    flag++;
                }
            }
            if (flag == city.size())
            {
                cout << "Invalid city name!" << endl;
            }
            cout << endl;
        }
        else if(opt == "2")
        {
            string para;
            cout << "Please enter a specific parameter: ";
            getline(cin, para);
            cout<<"\nAll the data of " << para << ":" <<endl;

            if (para == temperature[0])
            {
                for(int i=0; i<temperature.size(); i++)
                {
                    cout << temperature[i] << endl;
                }
            }
            else if (para == light[0])
            {
                for(int i=0; i<light.size(); i++)
                {
                    cout << light[i] << endl;
                }
            }
            else if (para == airquality[0])
            {
                for(int i=0; i<airquality.size(); i++)
                {
                    cout << airquality[i] << endl;
                }
            }
            else if (para == sound[0])
            {
                for(int i=0; i<sound.size(); i++)
                {
                    cout << sound[i] << endl;
                }
            }
            else if (para == humidity[0])
            {
                for(int i=0; i<humidity.size(); i++)
                {
                    cout << humidity[i] << endl;
                }
            }
            else if (para == dust[0])
            {
                for(int i=0; i<dust.size(); i++)
                {
                    cout << dust[i] << endl;
                }
            }
            else
            {
                cout << "Invalid parameter!" << endl;
            }
            cout << endl;
        }
        else if(opt == "3")
        {
            string user_sp_date;
            cout << "Please enter a date (ex: 2015-01-07): ";
            getline(cin, user_sp_date);
            cout <<"\nAll the environmental data of " << user_sp_date << ":" <<endl;
            cout <<"               "<<city[0] << "       " << temperature[0] << " " << light[0] << " " << airquality[0] << " " << sound[0] << " " << humidity[0] << " " << dust[0] << endl;
            for(int i=0; i<date.size(); i++)
            {
                string timestamp = date[i];
                string date = timestamp.substr(0,10);

                if(date == user_sp_date)
                {
                    cout << date <<" "<< city[i] << " " << temperature[i] << " " << light[i] << " " << airquality[i] << " " << sound[i] << " " << humidity[i] << " " << dust[i] << endl;
                }
            }
            cout << endl;
        }
        else if(opt == "4")
        {
            string user_year;
            cout << "Please enter a year (ex:2015): ";
            getline(cin, user_year);
            cout <<"\nAll the environmental data of " << user_year << ":" <<endl;
            cout << "          " << city[0] << "       " << temperature[0] << " " << light[0] << " " << airquality[0] << " " << sound[0] << " " << humidity[0] << " " << dust[0] << endl;
            int flag = 0;

            for(int i=0; i<date.size(); i++)
            {
                string timestamp = date[i];
                string date = timestamp.substr(0, 4);

                if(date == user_year)
                {
                    cout << date << " " << city[i] << " " << temperature[i] << " " << light[i] << " " << airquality[i] << " " << sound[i] << " " << humidity[i] << " " << dust[i] << endl;
                }
            else
                {
                    flag++;
                }
            }
            if (flag == date.size())
            {
                cout << "No data of " << user_year <<"!"<< endl;
            }
            cout << endl;
        }
        else if(opt == "5")
        {
            string user_month;
            cout << "Please enter the a month (ex: 01 for January, 02 for February and so on.): ";
            getline(cin, user_month);
            cout <<"\nAll the environmental data of " << user_month << ":" <<endl;
            cout << "       " << city[0] << "       " << temperature[0] << " " << light[0] << " " << airquality[0] << " " << sound[0] << " " << humidity[0] << " " << dust[0] << endl;
            int flag = 0;

            for(int i=0; i<date.size(); i++)
            {
                string timestamp = date[i];
                string date = timestamp.substr(5, 2);

                if(date == user_month)
                {
                    cout << date << " " << city[i] << " " << temperature[i] << " " << light[i] << " " << airquality[i] << " " << sound[i] << " " << humidity[i] << " " << dust[i] << endl;
                }
            else
                {
                    flag++;
                }
            }
            if (flag == date.size())
            {
                cout << "No data of " << user_month <<"!"<< endl;
            }
            cout << endl;
        }
        else if(opt == "6")
        {
            string user_date;
            cout << "Please enter a date (ex: 01-31) to retrieve data for all the same dates from each month and year: ";
            getline(cin, user_date);
            cout <<"\nAll the environmental data of " << user_date << ":" <<endl;
            cout << "       " << city[0] << "       " << temperature[0] << " " << light[0] << " " << airquality[0] << " " << sound[0] << " " << humidity[0] << " " << dust[0] << endl;

            for(int i=0; i<date.size(); i++)
            {
                string timestamp = date[i];
                string date = timestamp.substr(8, 2);

                if(date == user_date)
                {
                    cout << date << " " << city[i] << " " << temperature[i] << " " << light[i] << " " << airquality[i] << " " << sound[i] << " " << humidity[i] << " " << dust[i] << endl;
                }
            }
            cout << endl;
        }
        else if(opt == "7")
        {
            cout << "\nThank you! See you later!";
            cout << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input option! Please enter a valid input!\n";
            cout << endl;
        }

    }

    return 0;
}
