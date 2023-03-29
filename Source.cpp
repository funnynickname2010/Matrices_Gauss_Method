#include <iostream>
#include <cmath>

//Minus zeros have to go

#define FTYPE double

using namespace std;
void matrix_input(FTYPE** m, FTYPE** copy_m, int row, int col);
void matrix_print(FTYPE** m, int row, int col);
void gauss_method(FTYPE** m, int row, int col);
void row_swap(FTYPE*& row1, FTYPE*& row2);
void row_division(FTYPE*& row, FTYPE scalar, int row_length);
void row_substraction_row2_row1(FTYPE*& row1, FTYPE*& row2, int col);
void row_multiplication_true(FTYPE*& row, FTYPE scalar, int row_length);
FTYPE* row_multiplication_return(FTYPE* row, FTYPE scalar, int row_length);
void row_row1_plus_row2mult_by_scalar(FTYPE*& row1, FTYPE* row2, FTYPE scalar, int row_length);

int main()
{
	int row, col;
	FTYPE** m;
	FTYPE** copy_m;


	//input rows, columns

	cout << "Rows: \n";
	cin >> row;
	cout << "Columns: \n";
	cin >> col;
	cout << "\n";


	//memory allocation

	m = (new FTYPE * [row]());
	copy_m = (new FTYPE * [row]());

	for (int i = 0; i < row; i++)
	{
		m[i] = (new FTYPE[col]());
		copy_m[i] = (new FTYPE[col]());
	}

	//input matrix

	matrix_input(m, copy_m, row, col);
	cout << "\n";

	//doing whatever

	gauss_method(m, row, col);

	//printing matrix 

	matrix_print(m, row, col);

	return 0;
}

void gauss_method(FTYPE** m, int row, int col)
{
	int rows_done = 0; //Number of rows that don't need any procedures anymore(?)

	for (int j = 0; j < col; j++) //col = m
	{
		for (int i = rows_done; i < row; i++) //row = n
		{
			if (m[i][j] != 0)
			{
				row_division(m[i], m[i][j], col);
				cout << "after row division\n";
				matrix_print(m, row, col);
				cout << "\n";

				for (int k = i + 1; k < row; k++)
				{
					if (m[k][j] != 0)
					{
						row_row1_plus_row2mult_by_scalar(m[k], m[i], -m[k][j], col);
					}
				}

				row_swap(m[i], m[rows_done]);
				rows_done += 1;
				break;
			}
		}
	}
}

void matrix_input(FTYPE** m, FTYPE** copy_m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> m[i][j];
			**copy_m = m[i][j];
		}
	}
}

void matrix_print(FTYPE** m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void row_swap(FTYPE*& row1, FTYPE*& row2)
{
	FTYPE* buffer = row1;

	row1 = row2;
	row2 = buffer;
}

void row_division(FTYPE*& row, FTYPE scalar, int row_length)
{
	for (int i = 0; i < row_length; i++)
	{
		row[i] = row[i] / scalar;
	}
}

void row_multiplication_true(FTYPE*& row, FTYPE scalar, int row_length)
{
	for (int i = 0; i < row_length; i++)
	{
		row[i] = row[i] * scalar;
	}
}

FTYPE* row_multiplication_return(FTYPE* row, FTYPE scalar, int row_length)
{
	for (int i = 0; i < row_length; i++)
	{
		row[i] = row[i] * scalar;
	}
	return row;
}

void row_row1_plus_row2mult_by_scalar(FTYPE*& row1, FTYPE* row2, FTYPE scalar, int row_length)
{
	for (int i = 0; i < row_length; i++)
	{
		row1[i] += row2[i] * scalar;
	}
}

void row_substraction_row2_row1(FTYPE*& row1, FTYPE*& row2, int col)
{
	for (int i = 0; i < col; i++)
	{
		row2[i] = row2[i] - row1[i];
	}
}