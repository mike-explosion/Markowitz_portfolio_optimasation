#include "csv.h"
#include "Readdata.h" // included in sample main, relocated in header to make the program more effficient
#include "Parameter_Estimation.h"
#include "Portfolio_Optimisation.h"
#include "Backtest.h"

#include<iostream>

using namespace std;

int  main (int  argc, char  *argv[])
{
    BackTest backtest; //class BackTest

    int numberAssets=83;
    int numberReturns=700;

	double **returnMatrix=new double*[numberAssets]; // a matrix to store the return data
    //allocate memory for return data
    for(int i=0;i<numberAssets;i++){
		returnMatrix[i]=new double[numberReturns];
    }
    //read the data from the file and store it into the return maatrix
	readData(returnMatrix,"asset_returns.csv");
	// returnMatrix[i][j] stores the asset i, return j value

    vector<double> Target_returns (20); //setting target returns
    double return_increments = (0.1/20); //setting return increments
    Target_returns[19] = 0.1;
    for(int j=0; j<19; j++){
            Target_returns[j] = (return_increments*j);
    }

    backtest.Set_Return_Matrix(returnMatrix);
    backtest.Set_Target_Return(Target_returns);
    backtest.Backtest(0, 100, 12);

    for(int i=0;i<numberAssets;i++)
		delete[] returnMatrix[i];
	delete[] returnMatrix;

	return 0;
}




