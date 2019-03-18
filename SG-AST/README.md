# matrix for SG-AST
example:
``` cpp
void Init()
{
    //初始化所有内置函数实体
    Function* add = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::add,2);
    Function* sub = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::sub,2);
    Function* mul = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::mul,2);
    Function* div = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::div,2);
    Function* pow = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::pow,2);
    Function* sin = new Function(BuiltinFunc::hasOneSonNode, BuiltinFunc::sin,1);
    Function* cos = new Function(BuiltinFunc::hasOneSonNode, BuiltinFunc::cos,1);
    Function* log = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::log, 2);
    Function* ln = new Function(BuiltinFunc::hasOneSonNode, BuiltinFunc::ln, 1);

    Function* assignment = new Function(BuiltinFunc::assignmentCheck, BuiltinFunc::assignment, 2);

    Function* vecDot = new Function(BuiltinFunc::twoVec, BuiltinFunc::vecDot, 2);
    Function* matDot = new Function(BuiltinFunc::twoMat, BuiltinFunc::matDot, 2);
    Function* matAdd = new Function(BuiltinFunc::twoMat, BuiltinFunc::matAdd, 2);
    Function* vecAdd = new Function(BuiltinFunc::twoVec, BuiltinFunc::vecAdd, 2);
    Function* vecSub = new Function(BuiltinFunc::twoVec, BuiltinFunc::vecSub, 2);
    Function* matSub = new Function(BuiltinFunc::twoMat, BuiltinFunc::matSub, 2);
    Function* vecMul = new Function(BuiltinFunc::vecNum, BuiltinFunc::vecMul, 2);
    Function* matMul = new Function(BuiltinFunc::matNum, BuiltinFunc::matMul, 2);
    Function* getRVector = new Function(BuiltinFunc::matNum, BuiltinFunc::getRVector, 2);
    Function* getCVector = new Function(BuiltinFunc::matNum, BuiltinFunc::getCVector, 2);
    Function* setCVector = new Function(BuiltinFunc::pmatVecNum, BuiltinFunc::setCVector, 3);
    Function* setRVector = new Function(BuiltinFunc::pmatVecNum, BuiltinFunc::setRVector, 3);
    Function* det = new Function(BuiltinFunc::oneMat, BuiltinFunc::det, 1);
    Function* linerSolve = new Function(BuiltinFunc::twoMat, BuiltinFunc::linerSolve, 2);
    //将这些函数置入函数域
    record::globalScope.addFunction("+",add);
    record::globalScope.addFunction("-",sub);
    record::globalScope.addFunction("*",mul);
    record::globalScope.addFunction("/",div);
    record::globalScope.addFunction("^",pow);
    record::globalScope.addFunction("=",assignment);
    //fix:目前=是通过局部求值实现的，即在被赋值变量原先没有值的情况下，局部求值模式下eval结果仍然为
    //变量本身，这样传进=函数之后左边儿子就是变量本身，可以正确赋值。一旦变量已经被赋值，那进入=前
    //就会被eval为它的值，值不能赋值给值，这就错了。因此现在这个写法不好。正确的做法应该是在parse阶段
    //创建每个变量的指针（二级varnode），然后将这个指针作为=的左边儿子
    record::globalScope.addFunction("sin",sin);
    record::globalScope.addFunction("cos",cos);
    record::globalScope.addFunction("log", log);
    record::globalScope.addFunction("ln", ln);

    record::globalScope.addFunction("linerSolve", linerSolve);
    record::globalScope.addFunction("det", det);
    record::globalScope.addFunction("setRVector", setRVector);
    record::globalScope.addFunction("setCVector", setCVector);
    record::globalScope.addFunction("getCVector", getCVector);
    record::globalScope.addFunction("getRVector", getRVector);
    record::globalScope.addFunction("matMul", matMul);
    record::globalScope.addFunction("vecMul", vecMul);
    record::globalScope.addFunction("matSub", matSub);
    record::globalScope.addFunction("vecSub", vecSub);
    record::globalScope.addFunction("vecAdd", vecAdd);
    record::globalScope.addFunction("matAdd", matAdd);
    record::globalScope.addFunction("matDot", matDot);
    record::globalScope.addFunction("vecDot", vecDot);
    //Function* entity=runtime::globalScope.functionList["+"]; //在parse阶段，可以这样从函数域中找到函数名对应的函数实体
    //FunNode* testNode=new FunNode(entity); //然后这样通过函数实体创建相应的函数节点
    BinOpPriority["$"] =0;
    BinOpPriority["="] =1;
    BinOpPriority["+"] =10;
    BinOpPriority["-"] =10;
    BinOpPriority["*"] =20;
    BinOpPriority["/"] =20;
    BinOpPriority["^"] =30;
}
```