#include "Matrix.h"
#include <exception>
#include <tuple>
//#include <iostream>
using namespace std;

MatrixIterator::MatrixIterator(Matrix& m, int line):matrix{m}
{
	this->primul = 0;
	this->current=0;
	this->ultimul = m.nrColumns()-1;
	this->line = line;
	
}
void MatrixIterator::first()
{
	this->current = this->primul;
}
void MatrixIterator::last()
{
	this->current = this->ultimul;
}
void MatrixIterator::next()
{
	if (this->current > this->ultimul)
		throw exception();
	else
	this->current += 1;
}
void MatrixIterator::previous()
{
	if (this->current < this->primul)
		throw exception();
	else
		this->current -= 1;
}
TElem MatrixIterator::getCurrent()
{
	//if (this->current >= this->primul && this->current <= this->ultimul)
	//	throw exception();
	return this->matrix.element(this->line, this->current);
}
bool MatrixIterator::valid()
{
	if (this->current >= this->primul && this->current <=this->ultimul)
	{
		return true;
	}
	else {
		return false;
	}
}
Matrix::Matrix(int nrLines, int nrCols) {
	
	
	if (nrLines<= 0 or nrCols<=0)
		throw exception();
	else
	{
		this->nr_lines = nrLines;
		this->nr_cols = nrCols;
		this->capacity = 2;
		this->size = 0;
		this->lines = new TElem[this->capacity];
		this->cols = new TElem[this->capacity];
		this->value = new TElem[this->capacity];

	}
	
}
//Tita (1)
Matrix::~Matrix() {
	delete[] this->lines;
	delete[] this->cols;
	delete[] this->value;
}
//Tita (1)

int Matrix::nrLines() const {
	
	return this->nr_lines;
}
//Tita (1)

int Matrix::nrColumns() const {
	
	return this->nr_cols;
}
//Tita (1)

TElem Matrix::element(int i, int j) const {
	if (i > this->nr_lines or i<0 or j>this->nr_cols or j < 0)
		throw exception();
	for (int k = 0; k < this->size; k++)
	{
		if (this->lines[k] == i && this->cols[k] == j)
			return this->value[k];
	}
	return 0;

}
//O(n)
void Matrix::resize()    
{
	

	this->capacity *= 2;
	
	
	TElem* new_lines = new TElem[this->capacity];
	TElem* new_cols = new TElem[this->capacity];
	TElem* new_value = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		new_lines[i] = this->lines[i];
		new_cols[i] = this->cols[i];
		new_value[i] = this->value[i];

	}
	
	delete[] this->lines;
	delete[] this->cols;
	delete[] this->value;


	this->lines = new_lines;
	this->cols = new_cols;
	this->value = new_value;

	/*delete[] new_cols;
	delete[] new_lines;
	delete[] new_value;;*/

}
//O(n)

TElem Matrix::modify(int i, int j, TElem e) {


	

	int index = 0,old_1=0,old_2=7;
	if (i > this->nr_lines or i<0 or j>this->nr_cols or j < 0)
		throw exception();
	if (this->size == 0 && e!=0)
	{
		this->lines[0] = i;
		this->cols[0] = j;
		this->value[0] = e;
		this->size++;
		return 0;
	}

	for (int k = 0; k < this->size; k++)
	{
		if (i == this->lines[k] && j == this->cols[k] && e!=0)
		{
			old_1 = this->value[k];
			this->value[k] = e;
			return old_1;
		}
		else if (i == this->lines[k] && j == this->cols[k] && e == 0)
		{
			 old_2 = this->value[k];
			for (int r = k; r < this->size; r++)
			{
				//old_2 = this->value[r];
				this->lines[r] = this->lines[r + 1];
				this->cols[r] = this->cols[r + 1];
				this->value[r] = this->value[r + 1];

			}
			this->lines[this->size] = 0;
			this->cols[this->size] = 0;
			this->value[this->size] = 0;
			this->size--;
			return old_2;
		}
	}

	for (int k = 0; k < this->size; k++)
	{
		if (this->lines[k] < i)
			index++;
	}
	
	for (int k = index; k < this->size; k++)
	{
		if (this->cols[k] < j)
			index++;

	}
	if (e == 0)
		return 0;   // 
	else
	{
		if (this->size + 1 > this->capacity)
			resize();
		if (index == this->size)
		{
			this->lines[this->size] = i;
			this->cols[this->size] = j;
			this->value[this->size] = e;
			this->size++;
		}
		else
		{
			for (int k = this->size; k > index; k--)  
			{
				this->cols[k] = this->cols[k - 1];
				this->value[k] = this->value[k - 1];
				this->lines[k] = this->lines[k - 1];

			}
			this->lines[index ] = i;
			this->cols[index ] = j;
			this->value[index ] = e;
			this->size++;
			return 0;
		}
	}
	

}
//O(n)

