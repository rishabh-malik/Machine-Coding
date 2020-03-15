class Snake{
	
	public:
		
		int start,end;
		
		Snake(int start,int end){
			
			this->start=start;
			this->end=end;
			
		}
		
		int getStart(){
			return this->start;
		}
		
		int getEnd(){
			return this->end;
		}
	
};
