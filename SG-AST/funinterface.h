#pragma once
#include "nodetype.h"
#include <cmath>

#define TypeJudge(name) static bool name(vector<BasicNode*>&sonNode)
#define _TypeJudge(name) bool BuiltinFunc::name(vector<BasicNode*>&sonNode)
#define FunBody(name) static BasicNode* name(vector<BasicNode*>&sonNode)
#define _FunBody(name) BasicNode* BuiltinFunc::name(vector<BasicNode*>&sonNode)

class BuiltinFunc
{
private:
    static double getNum(BasicNode* node);
public:
    //判断函数参数个数是否合法
    TypeJudge(hasOneSonNode);
    TypeJudge(hasTwoSonNodes);

    TypeJudge(oneMat);
    TypeJudge(twoVec);
    TypeJudge(twoMat);
    TypeJudge(vecNum);
    TypeJudge(matNum);
    TypeJudge(matVec);
    TypeJudge(matVecNum);
    //内置函数
    FunBody(add);
    FunBody(sub);
    FunBody(mul);
    FunBody(div);
    FunBody(pow);

    FunBody(sin);
    FunBody(cos);

    FunBody(log);
    FunBody(ln);

    FunBody(vecDot);
    FunBody(matDot);
    FunBody(vecAdd);
    FunBody(matAdd);
    FunBody(vecSub);
    FunBody(matSub);
    FunBody(vecMul);
    FunBody(matMul);
    FunBody(getRVector);
    FunBody(getCVector);
    FunBody(setRVector);
    FunBody(setCVector);
    FunBody(det);
    FunBody(linerSolve);
};
