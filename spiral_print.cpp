#include<iostream>

using namespace std;

 void spiral_print(int arr[][3],int row,int col){
	int count=0;
	int total=row*col;
	//index
	int startingRow=0;
	int startingCol=0;
	int endingRow=row-1;
	int endingCol=col-1;
	while(count<total){
		//printing starting row
		
		for(int index=startingCol;count<total && index<=endingCol;index++){
			cout<<arr[startingRow][index];
			count++;
		}
		startingRow++;
		
		//print ending column
		
		for(int index=startingRow;count<total && index<=endingRow;index++){
			cout<<arr[index][endingCol];
			count++;
		}
		endingCol--;
		
		//print ending row
		for(int index=endingCol;count<total && index>=startingCol;index--){
			cout<<arr[endingRow][index];
			count++;
		}
		endingRow--;
		
		//print starting col
		for(int index=endingRow;count<total && index>=startingRow;index--){
			cout<<arr[index][startingCol];
			count++;
		}
		startingCol++;
	}
}
int main(){
	int arr[3][3];
	
	cout<<"enter elements"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	spiral_print(arr,3,3);
}
