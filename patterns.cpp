#include<iostream>

using namespace std;

int main(){
	/*pattern 1
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<"*";
		}
		cout<<endl;
	}*/
	
	
	
	
	
	
	//pattern 2
	/*for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cout<<i;
		}
		cout<<endl;
	}*/
	
	
	
	
	
	//pattern 3
	/*for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cout<<j;
		}
		cout<<endl;
	}*/
	
	
	
	
	//pattern 4
	/*for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cout<<3-j+1;
		}
		cout<<endl;
	}*/
	
	
	
	
	//pattern 5
/*	int n;
	cin>>n;
	int count=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<count<<" ";
			count=count+1;
		}
		cout<<endl;
		
	}*/
	
	
	
	
	//pattern6
	/*	int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout<<"*";
		}
		cout<<endl;
    }*/
    
    
    
    
    
    
    //pattern 7
    
    
    /*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout<<row;
		}
		cout<<endl;
    }*/
    
    
    
    
    //pattern8
    
    /*int n;
	cin>>n;
	int count=1;
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout<<count<<" ";
			count=count+1;
		}
		cout<<endl;
    }*/
    
    
    
    //pattern 9
    
    /*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		int value=row;
		for(int j=1;j<=row;j++){
			cout<<value;
			value=value+1;
		}
		cout<<endl;
	}*/
	
	
	//pattern 10
	
	/*int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<(i-j)+1;
		}
		cout<<endl;
    }*/
    
    
    
    //pattern 11
    
    /*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n;col++){
			char ch='A'+row-1;
			cout<<ch;
		}
		cout<<endl;
    }*/
    
    
    
    //pattern 12
	
	/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n;col++){
			char ch='A'+col-1;
			cout<<ch;
		}
		cout<<endl;
}*/



  //pattern 13
  
  /*int n;
	cin>>n;
	char start='A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n;col++){
			cout<<start;
			start++;
		}
		cout<<endl;
	
}*/


   //pattern 14
   
   /*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n;col++){
			char ch='A'+row+col-2;
			cout<<ch;
			
		}
		cout<<endl;
}*/


//pattern 15


/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			char ch='A'+row-1;
			cout<<ch;
		}
		cout<<endl;
}*/



//pattern 16


/*int n;
	cin>>n;
	char start='A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout<<start;
			start++;
		}
		cout<<endl;
}*/


//pattern 17


/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			char ch='A'+row+col-2;
			cout<<ch;
		}
		cout<<endl;
}*/


//pattern 18


/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		char start='A'+n-row;
		for(int col=1;col<=row;col++){
		cout<<start;
		start++;
		}
		cout<<endl;
	}*/
	
	
	//pattern 19
	
	
	/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		
		//space print karlo
		int space=n-row;
		
		while(space){
			cout<<" ";
			space--;
		}
		for(int col=1;col<=row;col++){
			//stars print karlo
			cout<<"*";	
		}
		cout<<endl;
}*/



//pattern 20


/*int n;
	cin>>n;
	
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n-row;col++){
			cout<<"*";
		}
		cout<<endl;}*/
		
//pattern 21		
/*int n;

cin>>n;

for(int i=1;i<=n;i++){
	int space=i-1;
	while(space){
		cout<<" ";
		space--;
	}
	
	for(int j=1;j<=n-i+1;j++){
		cout<<"*";
	}
	cout<<endl;
}*/



//pattern 22

int n;

cin>>n;

for(int i=1;i<=n;i++){
	//print space
	int space=n-i;
	
	while(space){
		cout<<" ";
		space--;
	}
	//print 1st triangle
	for(int j=1;j<=i;j++){
		cout<<j;
	}
	
	//print 2nd triangle
	
	int start=i-1;
	while(start){
		cout<<start;
		start--;
	}
	cout<<endl;
}

}
