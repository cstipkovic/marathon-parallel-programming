#include <complex>
#include <iostream>

using namespace std;

int main(){
	int max_row, max_column, max_n;
	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	char **mat = (char**)malloc(sizeof(char*)*max_row);
    
    #pragma omp parallel for
	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);

	for(int r = 0; r < max_row; ++r){
        #pragma omp parallel for
		for(int c = 0; c < max_column; ++c){
			complex<float> z= 0;
			int n = 0;
			while(abs(z) < 2.0 && ++n < max_n)
				z = z*z + complex<float>(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}

	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r][c];
		cout << '\n';
	}	
}


