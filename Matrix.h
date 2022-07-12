#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0
class MatrixIterator;
class Matrix {

private:
	TElem* lines;
	TElem* cols;
	TElem* value;
	int capacity;
	int size;
	int nr_lines;
	int nr_cols;

	friend class MatrixIterator;
	
public:
	Matrix();
	//constructor
	Matrix(int nrLines, int nrCols);
	
	
	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	~Matrix();

private:
	void resize();

};
class MatrixIterator
{
	friend class Matrix;
private:
	const Matrix& matrix;
	int current;
	int line;
	int primul;
	int ultimul;

public:
	MatrixIterator(Matrix& m, int line);
	//MatrixIterator(Matrix m, int line);
///MatrixIterator iterator(int line)const;
	void next();
	void first();
	TElem getCurrent();
	void previous();
	bool valid();
	void last();

};