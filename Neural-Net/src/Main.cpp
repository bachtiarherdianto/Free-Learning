#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<float> X 
{
    5.1, 3.5, 1.4, 0.2,
    4.9, 3.0, 1.4, 0.2,
    6.2, 3.4, 5.4, 2.3,
    5.9, 3.0, 5.1, 1.8
};

vector<float> y 
{
    0,
    0,
    1,
    1
};

vector<float> W 
{
    0.5,
    0.5,
    0.5,
    0.5
};

vector<float> sigmoid_d(const vector<float>&m1);
vector<float> sigmoid(const vector<float>&m1);
vector<float> operator+(const vector<float>&m1, const vector<float>&m2);
vector<float> operator-(const vector<float>&m1, const vector<float>&m2);
vector<float> operator*(const vector<float>&m1, const vector<float>&m2);
vector<float> transpose(float *m, const int C, const int R);
vector<float> dot(const vector<float>&m1, const vector<float>&m2, const int m1_rows, const int m1_columns, const int m2_columns);
void print(const vector <float>&m, int n_rows, int n_columns);

int main()
{
    for (unsigned i = 0; i != 50; i++)
    {
        vector<float> pred = sigmoid(dot(X, W, 4, 4, 1));
        vector<float> pred_error = y - pred;
        vector<float> pred_delta = pred_error * sigmoid_d(pred);
        vector<float> W_delta = dot(transpose(&X[0], 4, 4), pred_delta, 4, 4, 1);
        W = W + W_delta;
        if (i == 49)
        {
            print(pred, 4, 1);
        }
    }
    return 0;
}


vector<float> sigmoid_d(const vector<float>&m1)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> output(VECTOR_SIZE);
    for (unsigned i = 0; i != VECTOR_SIZE; i++)
    {
        output[i] = m1[i] * (1 - m1[i]);
    }
    return output;    
}

vector<float> sigmoid(const vector<float>&m1)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> output(VECTOR_SIZE);
    for (unsigned i = 0; i != VECTOR_SIZE; i++)
    {
        output[i] = 1/(1 + exp(-m1[i]));
    }
    return output;    
}

vector<float> operator+(const vector<float>&m1, const vector<float>&m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> sum(VECTOR_SIZE);
    for (unsigned i = 0; i != VECTOR_SIZE; i++)
    {
        sum[i] = m1[i] + m2[i];
    }
    return sum;    
}

vector<float> operator-(const vector<float>&m1, const vector<float>&m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> difference(VECTOR_SIZE);
    for (unsigned i = 0; i != VECTOR_SIZE; i++)
    {
        difference[i] = m1[i] - m2[i];
    }
    return difference;    
}

vector<float> operator*(const vector<float>&m1, const vector<float>&m2)
{
    const unsigned long VECTOR_SIZE = m1.size();
    vector<float> multy(VECTOR_SIZE);
    for (unsigned i = 0; i != VECTOR_SIZE; i++)
    {
        multy[i] = m1[i] * m2[i];
    }
    return multy;    
}

vector<float> transpose(float *m, const int C, const int R)
{
    vector <float> mT (C*R);
    for (unsigned i = 0; i != C*R; i++)
    {
        unsigned alpha = i/C;
        unsigned beta = i%C;
        mT[i] = m[R*beta + alpha];
    }
    return mT;
}

vector<float> dot(const vector<float>&m1, const vector<float>&m2, const int m1_rows, const int m1_columns, const int m2_columns)
{
    vector<float> result(m1_rows * m2_columns);
    for (int row = 0; row != m1_rows; row++)
    {
        for (int col = 0; col != m2_columns; col++)
        {
            result[row * m2_columns + col] = 0.f;
            for (int i = 0; i != m1_columns; i++)
            {
                result[row * m2_columns + col] += m1[row * m1_columns + i] * m2[i * m2_columns + col];
            }
        }
    }
    return result;
}

void print(const vector <float>&m, int n_rows, int n_columns)
{
    for (int i = 0; i != n_rows; i++)
    {
        for (int j = 0; j != n_columns; j++)
        {
            cout << m[i * n_columns + j] << endl;
        }
    }
    cout << endl;
}