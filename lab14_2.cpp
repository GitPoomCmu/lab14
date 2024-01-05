#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool input[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << input[i][j] << " ";
        }
        cout << "\n";
    }
}

void inputMatrix(double input[][N]){
    for(int i=0; i<N; i++){
        cout << "Row " << i+1 << ": ";
        cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3] >> input[i][4];
    }
}

void findLocalMax(const double mA[][N], bool mB[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            double b = mA[i][j];
            if(i==0 || i==N-1 || j==0 || j==N-1){
                mB[i][j] = false;
            }
            else if(mA[i+1][j] > b || mA[i-1][j] > b || mA[i][j+1] > b || mA[i][j-1] > b){
                mB[i][j] = false;
            }
            else{
                mB[i][j] = true;   
            }
        }
    }
}
