#include <iostream>
#include <vector>

using namespace std;


int main()
{


	int arrlen = 0;
	int noquer = 0;
	vector <int> arr;

	cin>>arrlen>>noquer;

	for (int i = 0; i<arrlen;i++)
	{
		int temp =0;

		cin>>temp;
		cin.ignore();

		arr.push_back(temp);
	}
	//	for (int i = 0; i<arrlen;i++)
	{

		//		cout<<arr[i];
	}
	//	cout<<endl<<"start";


	for (int j = 0 ; j < noquer; j++)
	{
		int opr = 0;
		unsigned int opd1 = 0, opd2 = 0;
		cin>>opr>>opd1>>opd2;


		if (opr == 1)
		{
			if (opd1 < arrlen)
				arr[opd1] = opd2;
		}
		else if (opr == 2)
		{

			int sum = 0;
//			cout<<"\ndata"<<opd1<<" "<<opd2<<" len "<<arrlen;
			if (opd1 < arrlen && opd2 < arrlen)
			{
				for (int i = opd1; i <= opd2;i++)
				{
//					cout<<endl<<"d"<<i<<" :"<<arr[i];
					sum+= arr[i];
				}
				//cout<<endl<<"sum : "<<sum;
				cout<<sum;
			}
		}



	}

	return 0;
}

