#include<iostream>
#include<queue>
#include<stack>
#include <fstream>
using namespace std;
class Node{  
public: 
	int value;
	char pos;
	Node* Next;
	Node() {

	} 

	Node(int b, Node* c,char p)
	{
		value=b;
		pos=p;
		Next=c;

	}
};
class Linkedlist{
	public:
	Node* head=NULL;
	int* cutArray;
	
public:
	
	void Insert(int A) { 
		if (head) {
			Node* current = head;
			while (current->Next != NULL)
			{
				current = current->Next;
			}
		
			current->Next = new Node(A, NULL,'l');
		}
		else
		{  
		
				head = new Node(A, NULL,'l');
		}
		
	
	}
	int countCuts(int a){    // as iam doing this with respect to nodes so max cut can't be calculated here
		int cut=0;   //it will cpntain cuts that are fromed because of first edge
		int k=0; 
		k=a+1;   // adding 1 as my indexing starting from zero
			Node* temp = head;
		if(head){
		
		while (temp != NULL) {
			if(  temp->value+1>k)
			{  
				//	cout<<"\ncase 1"<<"k="<<k<<"   node="<<temp->value+1<<endl;
				cut+=temp->value+1-k;
			}
			else if ( temp->value+1<k )
		{
				//	cout<<"\ncase 2"<<"k="<<k<<"   node="<<temp->value+1<<endl;
					cut+=k-(temp->value+1);
				
			}
			temp = temp->Next;
		}
	}
	
	else
	{
		cout<<"->No List"<<endl;
	}
		//cout<<cut<<"   ";
		return cut;
		
	}
	int  *maxcut(int numNode,int presentNode){ // it will return an array
		cutArray= new int[numNode];
		for(int i=0;i<numNode;i++){
			
			cutArray[i]=0;
		}
			Node* temp = head;
			int start,end=0,k;
			int tempval;
		if(head){
		k=presentNode+1;
		while (temp != NULL) {
			
		tempval=temp->value+1;
		if(tempval== k+1){
		//	cout<<"case1 k"<<k<<"  tempval"<<tempval<<endl;
			cutArray[k-1]+=1; 
		}
		else if(tempval+1== k){
		//	cout<<"case2 k"<<k<<"  tempval"<<tempval<<endl;
			cutArray[tempval-1]+=1;
		}   
		else if(tempval>k){
		//	cout<<"case3 k"<<k<<"  tempval"<<tempval<<endl;
			start=k;
			end=tempval;
				for(int i=start;i<end;i++){
			if(i+1<=end){
				cutArray[i-1]+=1;
			//	cout<<"lllllll"<<i-1<<endl;
			}
			
		}
		
		}
			else if(tempval<k){
			start=tempval;
			end=k; 
		//	cout<<"case4 k"<<k<<"  tempval"<<tempval<<endl;
				for(int i=start;i<end;i++){
			if(i+1<=end){
				cutArray[i-1]+=1;
			}
			
		}
		
		}
				temp = temp->Next;

		
	}
			
	
}
			return  cutArray;
}

int getMaxSize(){
		int MaxLinkSize=0;
		Node* temp = head;
		if(head){
		while (temp != NULL) {
			//cout << temp->value+1<<temp->pos<<"     ";
			MaxLinkSize+=1;
			temp = temp->Next; 
		}
	//	cout<<"/////////"<<MaxLinkSize;
		return MaxLinkSize;		
	}
		else
	{
		cout<<"->No List"<<endl;
	}
		
	}
int*  getArray(int size){
		int *arrayy; 
		arrayy=new int[size];
		int index=0;
		Node* temp = head;
		for(int i=0;i<size;i++){
			arrayy[i]=0;
			//cout<<"pppp"<<arrayy[i]<<"     ";
		}
		if(head){
		
		while (temp != NULL) {
			//cout << temp->value+1<<temp->pos<<"     ";
			arrayy[index]=temp->value+1;
			index++;
			temp = temp->Next; 
		}
		
	}
		else
	{
		cout<<"->No List"<<endl;
	}
	
	return arrayy;
}

void Display() {

		Node* temp = head;
		if(head){
		
		while (temp != NULL) {
			cout << temp->value+1<<temp->pos<<"     ";
			temp = temp->Next;
		}
	}
		else
	{
		cout<<"->No List"<<endl;
	}
	
	//	cout << "Size of linked list : " << count << endl;

	}

};
class  Graph{
	Linkedlist* arrayu;
	//Linkedlist* arrayl;
	int size;
	public:
	Graph(int a ){
		arrayu=new Linkedlist[a];
	//	arrayl=new Linkedlist[a];
		size=a; 
	}
	
	void checkTotalCuts(){
		int totalCuts;
		int maxcuts=0;
		int node=0;
		int temp;
		for(int i=0;i<size;i++){
			temp=arrayu[i].countCuts(i);
				totalCuts+=temp;
			if(maxcuts<temp){
				maxcuts=temp;
				node=i;
			}
			//cout<<"----->"<<temp<<"  ";
			
		}	
		cout<<"totalCuts="<<totalCuts<<endl;
		cout<<"MAX CUT THAT IS FORMED BY SINGLE EDGE:"<<node+1<<":"<<maxcuts<<endl;
	}
	void addEdge (int src, int dest){
		//cout<<src<<"  "<<dest<<endl;
		arrayu[src].Insert(dest);
	//	arrayu[dest].Insert(src);
		
	}	
	
	void showGraphStructure (){ 
		
		for(int i=0;i<size;i++){
			cout<<i+1<<" ";
			arrayu[i].Display();
			cout<<endl;
			
		}	
	}
	
void Mcut(){  
			int maxsize=0,k=0,rows=0;

		for(int i=0;i<size;i++){ // for loop to calculate max link size
			//cout<<i+1<<" ";
			k=arrayu[i].getMaxSize();
			if(k>maxsize){
				maxsize=k;
			} 
		}
			int MaCut[size][maxsize];
			int *temp;
			for(int i=0;i<size;i++){
			//cout<<i+1<<" ";
			temp=arrayu[i].maxcut(size,i);
		//	cout<<endl;
			for(int j=0;j<maxsize;j++){
				
				MaCut[i][j]=temp[j];
			}
		}
		int store[maxsize];	
		for(int i=0;i<maxsize;i++){
			store[i]=0;
		}	
		for(int i=0;i<size;i++){
			for(int j=0;j<maxsize;j++){
			
			store[j]+=MaCut[i][j];
			}
			
		}
		int var1=0;
	for(int i=0;i<maxsize;i++){
			if(store[i]>var1)
			var1=store[i];
		}
		
		cout<<"MAXCUT="<<var1<<endl;
		}
		
	
void crosses(){
		int maxsize=0,k=0,rows=0;
		// max number of connections
		for(int i=0;i<size;i++){ // for loop to calculate max link size
			//cout<<i+1<<" ";
			k=arrayu[i].getMaxSize();
			if(k>maxsize){
				maxsize=k;
			} 
		}
		
		int *temp;
		temp=new int[maxsize+1];
		for(int i=0;i<maxsize;i++){ // for loop to get array
			//matrix store
			temp[i]=0; 
		} 
		int matrix[size][maxsize+1];//	cout<<"size"<<size<<"maxsize"<<maxsize+1<<endl;
		for (int i=0;i<size;i++){ //matrix creation
			for(int j=0;j<maxsize+1;j++){
				if(j==0)
				matrix[i][j]=i+1;
				else
				matrix[i][j]=0;	
			}
		} 
		
		for(int i=0;i<size;i++){ 
			//matrix store
			temp=arrayu[i].getArray(maxsize);
			
				for(int j=1;j<maxsize+1;j++){ // storing 
					matrix[rows][j]=temp[j-1];
					
				}  
				rows++;
		
	
	}
		
		int UCN=0,LCN=0,LN=0,UN=0,rowcheck=0,total_crosses=0;
			for (int i=0;i<size;i++){ //matrix to check
			UCN=matrix[i][0];
			for(int j=1;j<maxsize+1;j++){
					LCN=matrix[i][j];
					if(LCN>0){ 		   // comparisons
						
						for (int K=0;K<size;K++){ 
				UN=matrix[K][0];
				for(int L=1;L<maxsize+1;L++){
						LN=matrix[K][L];
						
						if(LN!=LCN && UCN!=UN && LN>0){
						//cout<<"1111111";
						if(LN<LCN && UN>UCN ) {
							total_crosses++;
						}
						
					
					}
			}
		} 	
					}			
			}
		}
			cout<<"total_crosses="<<total_crosses<<endl;
	}
	
	
	
void MinSortAlgorithim(){
		int maxsize=0,k=0,rows=0;
		int 	keyRow,keyValue,pastvalue;
		int checkvalue,check3,count3=0,rowsize=0;
		bool loopCheck1=true,loopCheck2=true;
		for(int i=0;i<size;i++){ // for loop to calculate max link size
			//cout<<i+1<<" ";
			k=arrayu[i].getMaxSize();
			if(k>maxsize){
				maxsize=k;
			} 
		}
		int *temp;
		temp=new int[maxsize+1];
		cout<<endl;
		for(int i=0;i<maxsize;i++){ // for loop to get array
			//matrix store
			temp[i]=0; 
		} 
		maxsize+=4;
		int matrix[size][maxsize];
	//	cout<<"size"<<size<<"maxsize"<<maxsize<<endl;
		for (int i=0;i<size;i++){ //matrix creation
			for(int j=0;j<maxsize;j++){
				if(j==1)
				matrix[i][j]=i+1;
				else if(j==maxsize-2){
					//cout<<"hhh"<<i<<" "<<j;
						matrix[i][j]=i+1;
				}
				else
				matrix[i][j]=0;	
			}
		} 
		
		for(int i=0;i<size;i++){ 
			//matrix store
			temp=arrayu[i].getArray(maxsize);
			
				for(int i=0;i<size;i++){  // to display array that is returned from function
				//	cout<<temp[i]<<"  ";
				}
				for(int j=2;j<maxsize-2;j++){ // storing 
					matrix[rows][j]=temp[j-2];
					
				}  
				rows++;
				//cout<<endl;
		
	
	}
			
		int flag =0;
		int count=1,count2=0,check2=0;
			int newMatrix2[size][maxsize];
				int newMatrix3[size][maxsize];
		cout<<"\nGRAPH BEFORE SORTING:\n";
		for (int i=0;i<size;i++){ //matrix display
	
			for(int j=0;j<maxsize;j++){
				cout<<matrix[i][j]<<"   ";
				
			}
			cout<<endl;
		}
		//cout<<"WHILE LOOP START:";
		while(  loopCheck1 and loopCheck2 ){
			// first labelling acording to the upper layer 
			for (int i=0;i<size;i++){ //matrix display
					matrix[i][0]=count;
			for(int j=0;j<maxsize;j++){
			if(j!=0){
				if(matrix[i][j]!=0 && j< maxsize-2&& j>1){ // because at maxsize-2 loca there is label of the lower layer 
				//and at 0 and in 1 col  there is the label of upper layer 
					count++;
				}
			}  }	
		}   // upper layer labelling done 
		
		for (int k=0;k<size;k++){
			check2=0;
			count2=0;
		for(int i=0;i<size;i++){    // now labelling lower layer 
			for(int j=0;j<maxsize;j++){
				if(j>1 && j<maxsize-2){
					if(matrix[i][j]!=0 and check2==0){
						count2++;
						if( matrix[i][j]==matrix[k][maxsize-2])
						check2=1;
						matrix[k][maxsize-1]=count2;
						
					}
					
			}	}	
			}
		}    // now sorrting according to lower layer
		
		int newMatrix[size][maxsize];
		for (int i=0;i<size;i++){ // initializing with zero
			for(int j=0;j<maxsize;j++){
				newMatrix[i][j]=0;	
			}
		//	cout<<endl;
	}
			
		//now sorting the matrix according to lower layer 
	
	//	cout<<endl;
			keyRow=-1;keyValue=0,pastvalue=-1;   //////////////////sorting
			for(int k=0;k<size;k++){
					keyValue=1000000;
			for (int i=0;i<size;i++){ //
				
			for(int j=0;j<maxsize;j++){
				
				if(j==maxsize-1 ){ 
				if(  (matrix[i][j]>pastvalue)){
				
				if(matrix[i][j]<keyValue )
				{
						keyValue=matrix[i][j];
					 keyRow=i;
				}
				} 	
			}  }
			//cout<<endl;
		}
		pastvalue=keyValue;
		for(int m=0;m<maxsize;m++){
			newMatrix[k][maxsize-2]=matrix[keyRow][maxsize-2];
			if(m>0 && m<maxsize-2)
			newMatrix[k][m]=matrix[k][m];
		}
		
	}
	

	
		for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
				newMatrix2[i][j]=newMatrix[i][j];
			//	cout<<newMatrix2[i][j]<<"  lll  ";	
			}
		//cout<<endl;
	}
		flag+=2;
//	cout<<"Matrix2\nfirst labelleing and sorting done according to upper layer\n";  // new matrix and new matrix 2 are same till now...newmatrix2 will be stored 
	// other will be used further 
/*	for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
				cout<<newMatrix[i][j]<<"   ";	
			}
			cout<<endl;
	}*/
	cout<<endl;
		for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
			//	cout<<newMatrix2[i][j]<<"   ";	
			}
		//	cout<<endl;
	}
	//working fine
	//////////data is now sorted and now it have to label according to lower layer 
	checkvalue=0,check3=0;
	count3=0;
	for(int k=0;k<size;k++){
		//count3=0;
		check3=0;
		checkvalue=newMatrix[k][maxsize-2];
	//	cout<<"checkvalue="<<checkvalue<<endl;
		for(int i=0;i<size;i++){
			for(int j=0;j<maxsize;j++){
				if(j>1 && j<maxsize-2){
					if( newMatrix[i][j]!=0)
					{
						 //	cout<<"  in matrix"<<checkvalue<<"  "<<endl;
						if(newMatrix[i][j]==checkvalue)
						{
								count3++;
							if(check3==0){
								newMatrix[k][maxsize-1]=count3;
								check3=1;
							}
						}
					}	
				}	
			}
		}  
		
	}    // for loo ends
	
	////////////////////////////////
//	cout<<"labelling Acording to lower layer\n";
			for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
			//	cout<<newMatrix[i][j]<<" ***   ";
	
		}
	//	cout<<endl;
				}
			
			/// now trying to label upper layer according to lower 1 
		// for this we will make a matrix of pairs that are formed b lower layer 2			
			rowsize=0;
			for (int i=0;i<size;i++){ //calculating pairs 
			for(int j=2;j<maxsize-2;j++){
			
				if(newMatrix[i][j]!=0)	{
					rowsize++;
				}
			}
		//	cout<<rowsize<<"NNNNn"<<endl;
	}
	  		
		int edgeMatrix[rowsize][2];
		int edgevalue,rowcount=0;
		for(int k=0;k<size;k++){	
		edgevalue=newMatrix[k][maxsize-2];
		for (int i=0;i<size;i++){ //matrix display
				
			for(int j=2;j<maxsize-2;j++){
			
				if(edgevalue== newMatrix[i][j])	{
				
				edgeMatrix[rowcount][0]=edgevalue;
				edgeMatrix[rowcount][1]=newMatrix[i][1];
				rowcount++;
				
				}
			}
	}
	  }
	  for( int j=0;j<rowsize;j++){
	  	for(int k=0;k<2;k++){
	  //	cout<<"   "<<edgeMatrix[j][k];
	  		
		  }
	  //	cout<< endl;
	  	
	  }
	  for(int i=0;i<size;i++){
	  	
	  	newMatrix[i][0]=-1;
	  }
		///////////////////////////////////////////
		int count4=0,layerVal=0;
		for (int i=0;i<size;i++){ //matrix display
				layerVal=newMatrix[i][1];
				count4=0;
			for(int j=0;j<rowsize;j++){
				count4++;
				if(edgeMatrix[j][1]==layerVal){
					
					break;
				}
			
			}
			if(newMatrix[i][0]==-1)
			newMatrix[i][0]=count4;
		//	cout<<endl;
	}
//	  cout<<"labeeling done of upper layer according to the lower one\n:";
	for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
			//	cout<<newMatrix[i][j]<<"   ";	
			//	matrix[i][i]=newMatrix3[i][j];
			}
		//	cout<<endl;
	}
	
		
	//	int matrrixToBeSort[][];
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
				newMatrix3[i][j]=0;	
				if(j==maxsize-2){
					newMatrix3[i][j]=newMatrix[i][j];
					
				}
			}
		//	cout<<endl;
	}
			
		//now sorting the matrix according to upper layer 
	
		//cout<<endl;
			keyRow=-1;keyValue=0,pastvalue=-1;   //////////////////sorting
			for(int k=0;k<size;k++){
					keyValue=1000000;
			for (int i=0;i<size;i++){ //
				
			for(int j=0;j<maxsize;j++){
				
				if(j==0 ){ 
				if(  (newMatrix[i][j]>pastvalue)){
				
				if(newMatrix[i][j]<keyValue )
				{
						keyValue=newMatrix[i][j];
					 keyRow=i;
				}
				} 	
			}  }
			//cout<<endl;
		}
		pastvalue=keyValue;
		for(int m=0;m<maxsize;m++){
			newMatrix3[k][1]=newMatrix[keyRow][1];
			if(m>1 && m<maxsize-2)
			newMatrix3[k][m]=newMatrix[keyRow][m];
		}
		
	}    
//	cout<<"\nmatrix sorted according to upper layer\n";
	
	
			for(int i=0;i<size;i++){
				for(int j=0;j<maxsize;j++){
					if(j==1){
						if(newMatrix3[i][j]==newMatrix2[i][j]){	
						loopCheck1=false;
						break;	
						}
						if(j==maxsize-2){
						if(newMatrix3[i][j]==newMatrix2[i][j]){
							loopCheck2=false;
							break;
					} }  	}	}	}
	
		

		flag+=2;
	
	  }   
	  	cout<< "ITERATIONS="<<flag<<endl;
	  cout<<"GRAPH AFTER APPLYING MINSROT ALGORITHIM\n";
	  for (int i=0;i<size;i++){ //matrix display
			for(int j=0;j<maxsize;j++){
				cout<<newMatrix3[i][j]<<"   ";	
			//	matrix[i][i]=newMatrix3[i][j];
			}
			cout<<endl;
	}
	
	  ////////////// NOW GARPH IS SORTED AND MINIMIZED
	  /////////////NOW WE WILL FIND CUTS
	  /// MATRIX THAT WE WILL USE -------------->newMatrix3
	  int CHECKVALUE=0;
	  int toSubtract1,cutsCount=0,cutsCountB=0,cutsCountA=0;
	  bool found=true;
	  for(int i=0;i<size;i++){
	  	
	  	for(int j=2;j<maxsize-2;j++){
	  		if(newMatrix3[i][j]!=0){ 
	  	//	cout<<"New Iteration"<<newMatrix3[i][j]<<endl;;
	  		cutsCountB=0,cutsCountA=0;
	  		found=true;
	  			CHECKVALUE=newMatrix3[i][j];
	  			toSubtract1=newMatrix3[i][maxsize-2];
	  			if(i==0){
	  				for(int k=0;k<size;k++ ){
	  					//	cout<<"vvvvvvvvvvvvvvvvvvv"<<cutsCount<<endl;
	  					if(CHECKVALUE==newMatrix3[k][maxsize-2]){	
	  				//	cout<<"breakes";
	  						break;
						  }
						  
						  cutsCount++;	
					  }
	  				
				  }
				  else{
				  //	cout<<"case2\n";
				  		for(int k=i;k>=0;k-- ){
				  			
	  					if(CHECKVALUE==newMatrix3[k][maxsize-2]){
	  						found=false;
	  					//	cout<<endl<<"breakA"<<endl;
	  						break;
						  }
						  cutsCountA++;
					}
					
	  					if(found){
	  						//cout<<"case3\n";
	  						for(int k=i;k<maxsize;k++ ){
	  					if(CHECKVALUE==newMatrix3[k][maxsize-2]){
	  						break;
	  						
						  }
	  						cutsCountB++;
						  }
					  }
				  	if(found==false){
				  		cutsCount+=cutsCountA;
					  }
					else{
						cutsCount+=cutsCountB;
					}
				  	
				  } // else ended 
				  
			  }
	  		
	  		
		  }
	  }
	  cout<<"\nCUTS CALCULATED AFTER APPLICATION OF MINSORT ALGORITHIM\n"<<"TOTAL CUTS:"<<cutsCount<<endl;
	  
	  cout<<"\nCalculating Crosses AFTER APPLICATION OF MINSORT ALGORITHIM\n";
	  int UCN,LCN,UN,LN,crossess;
	  bool flag1=false,flag2=false,flag3=true,flag4=true,flag5=true,flag6=true,flag7=true;
	  for(int i=0;i<size;i++){ //rows 
	  	for(int j=2;j<maxsize-2;j++){   //cols 
	  		UCN=newMatrix3[i][1];
	  		LCN=newMatrix3[i][j];
	  		flag3=true;
	  		flag4=true;
	  		if(i>0)
	  		{for(int w=i-1;w>=0;w--){
	  			if(LCN==newMatrix3[w][6] )
	  			flag3=false;
			  }  }
			  if(i==0 ||i==size-1){
			  	if(LCN==newMatrix3[i][6])
			  			flag4=false;
			  	
			  } 
			  
	  		if(LCN!=0 && flag4==true && flag3==true ){
	  			cout<<"\n\n-->pairs  "<<UCN<<"   "<<LCN;  // forward pairs 
	  			for(k=i+1;k<size;k++){  /// for checking
	  				UN=newMatrix3[k][1];
	  				//cout<<"      llllllllllll"<<UN<<endl;
	  				for(int l=2;l<maxsize-2;l++){
	  				LN=newMatrix3[k][l];   // new pairs will be formed 
					  	//temp=i;
					  
					  	flag1=false;
						  flag2=false;
						  flag5=false;
						  flag6=false;
						  flag7=false;
						 // if( )
					  	for(int p=0;p<1;p++){
						  
					  	for(int m=i;m<size;m++){   // checking lower values of first col  1
							  if(UN==newMatrix3[m][1])
					  		{   //cout<<"\ncase1  "<<UN<<"   "<<newMatrix3[m][1]<<"  \n";
					  			flag1=true;
					  			break;
							  }
						  }
					//	for(int m=i+1;m>=0;m--){   // checking upper values of col 6
					for(int m=i+1;m>=0;m--){  
					//cout<<"kkkkk"<<endl;
						if(LN==newMatrix3[m][maxsize-2])
					  		{ // cout<<"\ncase2  "<<LN<<"   "<<newMatrix3[m][maxsize-2]<<" \n";
					  			flag2=true;
					  				break;
							  }
					  }
					  ///////////////////
					 for(int m=i;m<size;m++){   
					  	if(LN==newMatrix3[m][maxsize-2]){
					  		for(int f=m+1;f<size;f++){
							  if(newMatrix3[f][maxsize-2]==LCN){  
							  flag5=true;
						}
							  
							  }
					  		
						  }
					  	
					  	
					  }
					  
					  for(int m=i;m<size;m++){   
					  	if(UCN==newMatrix3[m][1]){
					  		for(int f=m+1;f<size;f++){
							  if(newMatrix3[f][1]==UN){  
							  flag6=true;
						}
							  
							  }
					  		
						  }
					  	
					  	
					  }
					  
					  ////////////// 
					  if(LN==LCN){
					  	flag1=false;
					  }
					if(LN==newMatrix3[i-1][1] && UN==newMatrix3[i+1][j] ){
						  //	if(i==size-2)
						  	flag7=true;
						  }
					  if(flag1==true && flag2==true)
					  {		
					  cout<<"\ncut by  "<<UN<<"   "<<LN;
					  	crossess++;
						  }  
						 // cout<<"\nFlag5"<<flag5<<"flag6"<<flag6<<endl;
					 else if( flag5==true && flag6==true){
							
						//	cout<<"aa";
							crossess++;
						} 
				/*	else if(flag7==true){
						if(i==size-1)
						crossess++;
					}	*/
					  	
					  }   
	  				
	  			}
	  				
				  }
	  			
	  			
	  			
			  }
	  		
	  		
		  }
	  	
	  }
	  
	  cout<<"\n\nTOTAL CROSSES:"<<crossess<<endl;
}
};

int main(){
	int num;
	int check=0,src,dest;
	ifstream readData;
	cout<<"READING DATA FROM FILE\n";
	readData.open("Input-Graph1.txt");
	readData>>num;
	Graph g1(num);
   while ( !readData.eof() ) {   
      readData >> src; 
      readData >> dest; 
      g1.addEdge(src-1,dest-1); 
       cout<<src<<"  "<<dest << endl;
   }
 
  	readData.close(); 
  
  	cout<<"BIPARTITE GRAPH HAS BEEN FORMED\n";
	g1.showGraphStructure();
	cout<<"\nCHECKING TOTAL CUTS IN THE GRAPH BEFORE SORTING\n";
	g1.checkTotalCuts();
	cout<<"\nCHECKING MAX CUTs IN THE GRAPH BEFORE SORTING\n";
	g1.Mcut();
	cout<<"\nCHECKING CROSSESS/INTERSECTIONS IN THE GRAPH BEFORE SORTING\n";
	g1.crosses();
	cout<<"\nAPPLYING MINSORT ALGORITHIM ON GRAPH";
	g1.MinSortAlgorithim();
	
	
	return 0;
 } 
