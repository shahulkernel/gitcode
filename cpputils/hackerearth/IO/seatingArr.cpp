

#include<iostream>


using namespace std;


int main()
{

	int num = 0;
	int seat = 0;
	//scanf("%d",&num);
	//scanf("%d",&seat);

	cin>>num;
	cin>>seat;


	for (int i = 0; i < num; i++)
	{
		switch	(seat)
		{
			case (seat > 0 && seat < 13)
			{
				find(1,12,seat);				
			break;	
			}
			case (seat > 12 && seat < 25)
			{
			
			break;	
			}
			case (seat > 24 && seat < 37)
			{
			
			break;	
			}
			case (seat > 36 && seat < 49)
			{
			
			break;	
			}
			case (seat > 48 && seat < 61)
			{
			
			break;	
			}
			case (seat > 60 && seat < 73)
			{
			
			break;	
			}
			case (seat > 72 && seat < 85)
			{
			
			break;	
			}
			case (seat > 84 && seat < 97)
			{
			
			break;	
			}
			case (seat > 96 && seat < 109)
			{
			
			break;	
			}
		}
	}

	
}

void find(int start, int end, int seat)
{
	int val = end - seat;

	if (val < 6 )
	{
		val = seat - 
	}
	else
	{
		
	}
		
	
	return;
}
