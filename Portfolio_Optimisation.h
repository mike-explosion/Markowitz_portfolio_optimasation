#ifndef Portfolio_opt_h
#define Portfolio_opt_h
#include "Parameter_Estimation.h"
#include <cmath>

#include <iostream>

using namespace std;

class Portfolio_Optimisation : public Parameter_Estimation
{
	private:

		double epsilon = 10e-6;
		double TargetReturns;
		double **returnMatrix;
		int numberAssets;
		int numberReturns;

	public:
		void SetReturns(int numberReturns_){
		    numberReturns=numberReturns_;
        }
		void SetAssets(int numberAssets_){
		    numberAssets=numberAssets_;
        }
		void SetReturnMatrix(double **returnMatrix_){
		    returnMatrix=returnMatrix_;
        }
		void Set_TargetReturns(double TargetRet_) {
		    TargetReturns = TargetRet_;
        }

        //Functions defined with class Portfolio Optimization

		vector<double> MatrixVectorMult( const vector< vector<double> > &Q, const vector<double> &V );
		vector<double> VectorComb( double a, const vector<double> &U, double b, const vector<double> &V );
		double InnerProd( const vector<double> &U, const vector<double> &V );
		vector<double> Conjugate_Gradient_Solver(int start_date, int end_date);
};

#endif




