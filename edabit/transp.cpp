//--------------------------------MY SOLUTION---------------------------------------//
std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> arr) {
	int arr_rows = arr.size();
	int arr_cols = arr[0].size();
	
	std::vector<int> tempVector;
	
	std::vector<std::vector<int>> transp;
	
    for (int jj=0; jj<arr_cols; ++jj){
	    for (int ii=0; ii<arr_rows; ++ii){
	 	    tempVector.push_back(arr[ii][jj]);
	    }

        transp.push_back(tempVector);
        tempVector.clear();		
	}
	
	return transp;
}

//-------------------------ALTERNATIVE SOLUTION-------------------------------------//
using namespace std; 

vector<vector<int>> transposeMatrix(vector<vector<int>> arr) {
	vector<vector<int>> res(arr[0].size(),vector<int>(arr.size()));
	for(int i=0;i<arr.size();++i)
		for(int j=0;j<arr[i].size();++j)
			res[i][j]=arr[j][i];
	return res;
}