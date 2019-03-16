#pragma once
#include <string>
using namespace std;

class vector
{
private:
	unsigned int l;

public:
	double *v;

	vector(unsigned int l)
	{
		this->l = l;
		this->v = new double[l];
		for (unsigned int i = 0; i < l; i++)
			this->v[i] = 0;
	}

	vector(const vector& m2)
	{
		this->l = m2.l;
		this->v = new double[l];
		for (unsigned int i = 0; i < l; i++)
			this->v[i] = m2.v[i];
	}

	double dot(vector &v2)
	{
		if (v2.l != this->l)
			throw "两个向量维度不对不能相乘";
		else
		{
			double result = 0;
			for (unsigned int i = 0; i < l; i++)
				result += this->v[i] * v2.v[i];
			return result;
		}
	}

    vectorNode mul(double n)
    {
        vectorNode result(this->l);
        for (unsigned int i = 0; i < l; i++)
            result.v[i]=this->v[i]*n;
        return result;
    }

    vectorNode add(vectorNode v2)
    {
        if(v2.l!=this->l)
            throw string("两个向量维度不对不能相加");
        else
        {
            vectorNode result(this->l);
            for (unsigned int i = 0; i < l; i++)
                result.v[i]=this->v[i]+v2.v[i];
            return result;
        }
    }

    void output()
    {
        for (unsigned int i = 0; i < l; i++)
        {
            printf("%g\t", v[i]);
        }
        printf("\n");
    }

	~vector() { delete[]v; }
	unsigned int getl() { return l; }
};


class matrix
{
private:
	unsigned int r;
	unsigned int c;

	void malloc()
	{
		this->m = new double*[r]; //给第一维分配空间
		for (unsigned int i = 0; i < r; i++)
			this->m[i] = new double[c]; //给第二维分配空间
	}

public:
	double **m;

	matrix(unsigned int r, unsigned int c)
	{
		this->r = r;
		this->c = c;
		this->malloc();
		//初始化为零矩阵
		for (unsigned int i = 0; i < r; i++)
		{
			for (unsigned int j = 0; j < c; j++)
				this->m[i][j] = 0;
		}
	}

	matrix(const matrix& m2)
	{
		this->r = m2.r;
		this->c = m2.c;
		this->malloc();
		for (unsigned int i = 0; i < r; i++)
		{
			for (unsigned int j = 0; j < c; j++)
				this->m[i][j] = m2.m[i][j];
		}
	}

	~matrix()
	{
		for (unsigned int i = 0; i < r; i++)
			delete[] m[i];
		delete[] m;
	}

	unsigned int getr() { return r; }
	unsigned int getc() { return c; }

	vector getRVector(unsigned int rn)
	{
		vector result = vector(this->c);
		for (unsigned int i = 0; i < this->c; i++)
			result.v[i] = this->m[rn][i];
		return result;
	}

	vector getCVector(unsigned int cn)
	{
		vector result = vector(this->r);
		for (unsigned int i = 0; i < this->r; i++)
			result.v[i] = this->m[i][cn];
		return result;
	}
	
	void setRVector(vectorNode v, unsigned int rn)
	{
		if(v.l!=this->c)
		    throw string("赋值的向量维度与矩阵行列长度不匹配");
		else
		{
		    for (unsigned int i = 0; i < this->c; i++)
			this->m[rn][i]=v.v[i];
		}
	}

	void setCVector(vectorNode v, unsigned int cn)
	{
		if(v.l!=this->r)
		    throw string("赋值的向量维度与矩阵行列长度不匹配");
		else
		{
		    for (unsigned int i = 0; i < this->r; i++)
			this->m[i][cn]=v.v[i];
		}
	}

	double det()
	{
		if (this->r != this->c)
			throw string("只有方阵才能求行列式");
		else if (this->r == 1)
			return this->m[0][0];
		else
		{
			double result = 0;
			//得到从当前矩阵中划去第0行和第j列的所有元素后得到的矩阵
			for (unsigned int j = 0; j < this->r; j++)
			{
				matrix mb = matrix(r - 1, r - 1);
				for (unsigned int r = 1; r < this->r; r++)
				{
					for (unsigned int c = 0; c < this->c; c++)
					{
						if (c > j)
							mb.m[r - 1][c - 1] = this->m[r][c];
						else if (c < j)
							mb.m[r - 1][c] = this->m[r][c];
					}
				}
				result += pow(-1, 0 - j) * this->m[0][j] * mb.det();
			}
			return result;
		}
	}

	matrix dot(matrix &m2)
	{
		if (this->c != m2.r) //如果矩阵A的列数不等于矩阵B的行数……
			throw string("两个矩阵的维度不能相乘");
		else
		{
			matrix result = matrix(this->r, m2.c);
			for (unsigned int i = 0; i < this->r; i++)
			{
				vector v1 = this->getRVector(i);
				for (unsigned int j = 0; j < m2.c; j++)
				{
					vector v2 = m2.getCVector(j);
					result.m[i][j] = v1.dot(v2);
				}
			}
			return result;
		}
	}
	
    matrixNode mul(double n)
    {
        matrixNode result(this->r,this->c);
        for (unsigned int i = 0; i < this->r; i++)
            for (unsigned int j = 0; j < this->c; j++)
                result.m[i][j]=this->m[i][j]*n;
        return result;
    }

    matrixNode add(matrixNode m2)
    {
        if(m2.c==this->c&&m2.r==this->r)
        {
            matrixNode result(this->r,this->c);
            for (unsigned int i = 0; i < this->r; i++)
                for (unsigned int j = 0; j < this->c; j++)
                    result.m[i][j]=this->m[i][j]+m2.m[i][j];
            return result;
        }
        else
            throw string("两个矩阵维度不对不能相加");
    }

    void output()
    {
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                printf("%g\t", m[i][j]);
            }
            printf("\n");
        }
    }
};
