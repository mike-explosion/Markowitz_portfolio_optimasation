#ifndef Readdata_h
#define Readdata_h

#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "csv.h"

#include <iostream>


using namespace std;

double string_to_double( const std::string& s )
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}

void readData(double **data,string fileName)
{
	char tmp[20];
	ifstream file (strcpy(tmp, fileName.c_str()));
	Csv csv(file);
	string line;
	if (file.is_open())
	{
		int i=0;
		while (csv.getline(line) != 0) {
         	for (int j = 0; j < csv.getnfield(); j++)
            {
               double temp=string_to_double(csv.getfield(j));
               //cout << "Asset " << j << ", Return "<<i<<"="<< temp<<"\n";
               data[j][i]=temp;
            }
            i++;
		}

		file.close();
	}
	else {cout <<fileName <<" missing\n";exit(0);}
                                                                 }

#endif
