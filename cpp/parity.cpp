#include <iostream>
using namespace std;

#define MAX_SIXTEEN_BIT_NUMBER 65536
unsigned long input_number = 2;

char parity_arr[MAX_SIXTEEN_BIT_NUMBER]={0};

char parity_calculator(unsigned short num){
	//num ^= num>>32;
	//num ^= num>>16;
	num ^= num>>8;
	num ^= num>>4;
	num ^= num>>2;
	num &= num>>1;

	return num;
}


unsigned short parity (unsigned long num) {
	unsigned short res = 0;
	while (num) {
		res ^= (num & 1);
		num >>= 1;
	}
	return res;
}

unsigned short parity1 (unsigned long num) {
	unsigned short res = 0;
	while (num) {
		num &= (num -1);//removes lsb or sets lsb to zero
		res ^= 1;
	}
	return res;
}

int main(){

	unsigned short i,parity_op,counter=0;
	cout << "enter the number" << endl;
	cin >> input_number ;
//	cout << sizeof(unsigned short) << "\t" << sizeof(unsigned long) <<endl;
	cout << "parity of the number - " << parity(input_number) << endl;
	//prepare the parity cache 
#if 0
	for (i=0; i<MAX_SIXTEEN_BIT_NUMBER-1; i++){
		parity_arr[i] = parity_calculator(i);
		counter++;
	}
	cout << "counter - " << counter <<endl ;
	//parity is xor of the 4 sets of 16 bits
	//parity_op = (parity_arr[input_number >>48]) ^ (parity_arr[input_number >>32 & 0xffff]) ^ (parity_arr[input_number >>16 & 0xffff]) ^ (parity_arr[input_number & 0xffff]); 
	//parity_op =  (parity_arr[input_number >>16 & 0xffff]) ^ (parity_arr[input_number & 0xffff]); 
        //cout << "parity of " << input_number << "\t" <<  parity_op << endl;	
#endif
	return 0;
}
