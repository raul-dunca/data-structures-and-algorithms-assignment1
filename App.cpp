
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <crtdbg.h>
#include <assert.h>
#include <cassert>
using namespace std;


int main() {

	
	testAll();
	testAllExtended();
	Matrix m(4, 4);
	m.modify(0, 0, 1);
	m.modify(0, 1, 5);
	m.modify(3, 3, 2);
	m.modify(3, 0, 5);
	m.modify(2, 0, 8);
	m.modify(2, 1, 4);
	m.modify(2, 2, 7);
	m.modify(2, 3, 3);

	MatrixIterator it{ m,0 };
	TElem el = it.getCurrent();

	for (it.first(); it.valid(); it.next())
		cout << it.getCurrent()<<" ";

	cout << endl;
	cout << "/////////////////////////////"<<endl;

	MatrixIterator it_2{ m,3 };
	TElem el_2 = it_2.getCurrent();

	for (it_2.last(); it_2.valid(); it_2.previous())
		cout << it_2.getCurrent() << " ";
	

	cout << endl;
	cout << "/////////////////////////////" << endl;


	MatrixIterator it_3{ m,2 };
	TElem el_3 = it_3.getCurrent();

	for (it_3.last(); it_3.valid(); it_3.previous())
		cout << it_3.getCurrent() << " ";


	cout << endl;
	cout << "/////////////////////////////" << endl;

	MatrixIterator it_4{ m,2 };
	TElem el_4 = it_4.getCurrent();

	for (it_4.first(); it_4.valid(); it_4.next())
		cout << it_4.getCurrent() << " ";


	cout << endl;
	cout << "/////////////////////////////" << endl;

	for (int i = 0; i < m.nrLines(); i++)
	{
		for (int j = 0; j < m.nrColumns(); j++)
			cout << m.element(i, j) << " ";
		cout << endl;
	}
	cout << "Test End" << endl;
	//MatrixIterator iterator {m,3};
	//cout << iterator.getCurrent();

	_CrtDumpMemoryLeaks();
	system("pause");
}