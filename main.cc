#include <iostream>
#include <cstdlib>
#include "priority_queue.h"

// Hello. This project was added to test GIT

using namespace std;

#define MIN_CUSTOMER_NUM (-500)
#define MAX_CUSTOMER_NUM (2000)
#define CUSTOMER_DATA_ERR (-1)

template <typename T>
void pushQueue(templatePriorityQueue<T>* Que, int data){
	cout << "[+] Integer "<< data <<" pushed in the Priority Queue." << endl;
	Que->push(data);
}

template<typename T>
void popQueue(templatePriorityQueue<T>* Que){
	cout << "[+] Integer "<< Que->top() << " will be poped from the Priority Queue." << endl;
	Que->pop();
}

int main(int argc, char* argv[]){
	templatePriorityQueue<int> priQueue;
	int customNumber = 0;

	//empty check
	if(priQueue.empty()){
		cout << "[!] Priority Queue is empty - initalized" << endl;
	}

	// push
	pushQueue(&priQueue,23);
	pushQueue(&priQueue,598);
	pushQueue(&priQueue,302);

    // If argument is bigger than 1, need to process customer data
	if( argc > 1 ){
		customNumber = atoi(argv[1]);
		if( customNumber > MIN_CUSTOMER_NUM && customNumber < MAX_CUSTOMER_NUM){
			pushQueue(&priQueue,customNumber);
		}
		else{
			pushQueue(&priQueue, CUSTOMER_DATA_ERR);
		}
	}
	else{
		pushQueue(&priQueue, CUSTOMER_DATA_ERR);
	}

	//empty & size
	if(priQueue.empty()){
		cout << "[-] Priority Queue is empty. - Push method did not work!" << endl;
		return -1;
	}
	else{
		cout << "[+] Priority Queue has data. - Queue Size : " << priQueue.size() <<endl;
	}

	// pop twice
	popQueue(&priQueue);
	popQueue(&priQueue);

	cout << "[+] Now, Top element of Priority Queue is " << priQueue.top() << endl;
	
	return 0;
}
