#include <iostream>
#include <thread>
using namespace std;
const int n=100;
void threadfunction1(int* ch, int **imager, int begin, int end)
{
	for (int i=begin; i<end; i++)
   	{
		for (int t=0; t<n; t++)
		{
			ch[imager[i][t]]++;
		}
	}
}
int main ()
{
	int counter[256]={0};
    int** image = new int* [n];
	for (int i = 0; i < n; i++)
	{
		image[i] = new int[n];
	}
	for (int i=0; i<100; i++)
   	{
		for (int t=0; t<100; t++)
		{
			image[i][t] = rand() % 256;
		}
	}
	thread thr1(threadfunction1, counter, image, 0, 5);
	thread thr2(threadfunction1, counter, image, 5, 10);
	thread thr3(threadfunction1, counter, image, 10, 15);
	thread thr4(threadfunction1, counter, image, 15, 20);
	thread thr5(threadfunction1, counter, image, 20, 25);
	thread thr6(threadfunction1, counter, image, 25, 30);
	thread thr7(threadfunction1, counter, image, 30, 35);
	thread thr8(threadfunction1, counter, image, 35, 40);
	thread thr9(threadfunction1, counter, image, 40, 45);
	thread thr10(threadfunction1, counter, image, 45, 50);
	thread thr11(threadfunction1, counter, image, 50, 55);
	thread thr12(threadfunction1, counter, image, 55, 60);
	thread thr13(threadfunction1, counter, image, 60, 65);
	thread thr14(threadfunction1, counter, image, 65, 70);
	thread thr15(threadfunction1, counter, image, 70, 75);
	thread thr16(threadfunction1, counter, image, 80, 85);
	thread thr17(threadfunction1, counter, image, 85, 90);
	thread thr18(threadfunction1, counter, image, 90, 95);
	thread thr19(threadfunction1, counter, image, 95, 100);
	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();
	thr5.join();
	thr6.join();
	thr7.join();
	thr8.join();
	thr9.join();
	thr10.join();
	thr11.join();
	thr12.join();
	thr13.join();
	thr14.join();
	thr15.join();
	thr16.join();
	thr17.join();
	thr18.join();
	thr19.join();
	for (int i=0; i<256; i++)
	{
		cout<<i<<" ";
		while(counter[i] > 0)
		{
		cout<<"*";
		counter[i]--;
		}
	cout<<endl;
	}
	for (int i = 0; i < 20; i++)
	{
		delete[] image[i];
	}
	delete[] image;
return 0;
}