#include <iostream>



using namespace std;



int main(){
int num;
int sum = 0;
int digit = 0;

int i = 0;
cin>>num;

while(1)
{
	digit = num%10;
	if (num == 0)
		break;
	sum+=digit;

	num = num/10;
}


cout<<sum;

return 0;

}
