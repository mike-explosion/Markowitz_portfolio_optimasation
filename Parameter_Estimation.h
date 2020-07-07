#ifndef Parameter_Estimation_h
#define Parameter_Estimation_h

#include <vector>
#include <iostream>

using namespace std;

class Parameter_Estimation
{
	private:
		int numberReturns;
		int numberAssets;
		double **returnMatrix;
		vector<double> asset_means;
		vector< vector<double> > covariance_matrix;

	public:
		void ReturnMatrix(double **returnMatrix_){
		    returnMatrix=returnMatrix_;
        }
		void NumberReturns(int numberReturns_){
		    numberReturns=numberReturns_;
        }
		void NumberAssets(int numberAssets_){
		    numberAssets=numberAssets_;
        }

		double Get_Assets();
		vector<double> Get_Mean();
		vector< vector<double> > Get_Cov();
		double mean_returns(int start_date, int end_date);
		double cov_matrix(int start_date, int end_date);
};

#endif
