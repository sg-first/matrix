#pragma once
#include "matrix.h"

class matrixCalu
{
public:
	static vector solve(matrix m, vector v) //克拉默法则求解
	{
		double D = m.det();
		vector result = vector(v.getl());
		for (unsigned int i = 0; i < v.getl(); i++) //逐行替换并计算行列式，目前替换第i列
		{
			matrix mb = matrix(m);
			for (unsigned int j = 0; j < v.getl(); j++) //替换第i列的第j个元素
				mb.m[j][i] = v.v[j];
			result.v[i] = mb.det() / D;
		}
		return result;
	}
};
