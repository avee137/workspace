#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>

using namespace std ;

void mycopy(int (&src_arr)[9], int (&dst_arr)[9]) {
	copy (begin(src_arr), end(src_arr), dst_arr);
	cout << "printing copied values" << endl ;
	for ( auto i = 0; i < (sizeof(src_arr)/sizeof(src_arr[0])); i++ ) {
		cout <<dst_arr[i] << "  ";
	}
	cout << endl;
}

void myfill(vector <int> &ivecref, int val) {	
	fill (ivecref.begin(), ivecref.end(), 0);
	auto iter1=ivecref.cbegin();
	cout << "printing filled values" << endl ;
	while (iter1 != ivecref.cend()){
			cout << *iter1 << "  " ;
			iter1++;
	}
	cout << endl ;
	return;
}

void myfill_n(vector <int> &vintref, int count, int val){
	fill_n(vintref.begin(), count, val);
	auto iter = vintref.cbegin();
	cout << "received a vector of size - "<< count << endl ;
	cout << "printing n-filled values" << endl ;
	while (iter != vintref.cend()) {
		cout << (*iter) << "   " ;
		iter++;
	}
	cout << endl ;
	return;
}

void myfind(vector<int> &ivec, int to_be_found) {
	auto found = find(ivec.cbegin(),ivec.cend(), to_be_found);
	cout <<  (found == ivec.cend() ? "not found " : "found" )<<  endl;
}

void mycount(vector<int> &ivec , int to_be_counted) {
	auto cnt = count (ivec.cbegin(), ivec.cend(), 1);
	cout << "count of ip- " << cnt << endl;
}

void myacc (vector<int> &ivec, int acc) {
	int isum=0;
	double dsum = 0;
	isum = accumulate (ivec.cbegin(), ivec.cend(), 0);
	//dsum = accumulate (dvec.cbegin(), dvec.cend(), 0);
	cout << "accumulate isum - " << isum << endl ;
	//cout << "accumulate dsum - " << dsum << endl ;
}

void myequal (list <const char *> &l1, list<const char *> &l2) {
	cout << ((equal (l1.cbegin(), l1.cend(), l2.cbegin()) == true ) ? "equal" : "not equal" )<< endl ;
}

void mysort(vector<string> &svec) {
	sort (svec.begin(),svec.end());
	auto iter = svec.cbegin();
	while (iter != svec.cend()) {
		cout << (*iter) << "   " ;
		iter++;
	}
	cout << endl ;
	auto unique_end_iter = unique(svec.begin(), svec.end());

	iter = svec.cbegin();
	auto count =0 ;
	cout << "after unique() call" << endl;
	while (iter != svec.cend()) {
		cout << (*iter) << "   " ;
		iter++;
		count++;
	} 
	cout << endl << "total elements - " << count << endl;
	cout << endl ;

}

int main() {
	int a = 45;
	int arr1[] = {1,2,3,4,5,6,7,8,9};
	int arr2[sizeof(arr1)/sizeof(arr1[0])]={0};
	vector <int> ivec={1,1,1,1,2,3,4,5,6,42};
	vector <double> dvec={1,1,1,2,3,4,5,6,42};
	list <string> ls = {"hello", "hello", "this", "world", "this"};
	list <const char *> roster1 = {"devil", "diner", "mourner", "crane", "millet"};
	list <const char *> roster2= {"devil", "diner", "mourner", "crane", "tusker"};
	vector <string> roster3= {"devil", "diner", "mourner", "crane", "tusker","crane","crane"};

//	myfill_n(ivec, ivec.size(), 0);
	mycopy(arr1, arr2);
	myequal(roster1,roster2);
	myacc(ivec, 0);
	mycount(ivec,1);
	myfind(ivec, 42);
	mysort(roster3);
	return 0 ;
}
