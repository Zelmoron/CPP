
#include <iostream>
#include <chrono>
#include"LineList.h"
#include"LineListItem.h"

int IOSIF(int Step,int People)
{
	LineList<int> list;
	for (int i = People; i > 0; i--)
	{
		list.insertFirst(i);
	}
	list.makeAnswer();
	//
	LineListElem<int>* it = list.getStart();
	while (list.getStart() != list.getStart()->getNext())
	{
		list.deleteAfter(it);
		for (int i = 0; i < Step - 1; i++)
		{
			it = it->getNext();
		}
	}
	cout<<"N = " <<People<< " " << "K = " << Step << " Answer: " << list << " ";
	return 0;
}


int main(void)
{
	int K = 2, arr[7] = { 1000,5000,10000,50000,100000,500000,1000000 };
	for (int i = 0; i < 7; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		IOSIF(K, arr[i]);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "Time " << diff.count() << endl;
	}
	return 0;
}
