#ifndef Backtest_h
#define Backtest_h
#include "Portfolio_Optimisation.h"

#include <iostream>

using namespace std;

class BackTest : public Portfolio_Optimisation
{
	private:
		double **returnMatrix;
		vector <double > TargetReturns;
	public:

        int numberAssets = 83;
		int numberReturns= 700;

		void Set_Return_Matrix(double **returnMatrix_){returnMatrix=returnMatrix_;} //define return matrix
		void Set_Target_Return(vector <double > TargetReturns_) {TargetReturns = TargetReturns_;} //define target returns
		vector< vector<double > > Backtest(int start_date, int end_date, int testing_oss);
};

#endif
