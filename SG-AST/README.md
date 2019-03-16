# matrix for SG-AST
example:
``` cpp
void Init()
{
    //��ʼ���������ú���ʵ��
    Function* add = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::add,2);
    Function* sub = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::sub,2);
    Function* mul = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::mul,2);
    Function* div = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::div,2);
    Function* pow = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::pow,2);
    Function* sin = new Function(BuiltinFunc::hasOneSonNode, BuiltinFunc::sin,1);
    Function* cos = new Function(BuiltinFunc::hasOneSonNode, BuiltinFunc::cos,1);
    Function* log = new Function(BuiltinFunc::hasTwoSonNodes, BuiltinFunc::log, 2);

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
    Function* setCVector = new Function(BuiltinFunc::matVecNum, BuiltinFunc::setCVector, 3);
    Function* setRVector = new Function(BuiltinFunc::matVecNum, BuiltinFunc::setRVector, 3);
    Function* det = new Function(BuiltinFunc::oneMat, BuiltinFunc::det, 1);
    Function* linerSolve = new Function(BuiltinFunc::twoMat, BuiltinFunc::linerSolve, 2);
    //����Щ�������뺯����
    record::globalScope.addFunction("+",add);
    record::globalScope.addFunction("-",sub);
    record::globalScope.addFunction("*",mul);
    record::globalScope.addFunction("/",div);
    record::globalScope.addFunction("^",pow);
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
    //Function* entity=runtime::globalScope.functionList["+"]; //��parse�׶Σ����������Ӻ��������ҵ���������Ӧ�ĺ���ʵ��
    //FunNode* testNode=new FunNode(entity); //Ȼ������ͨ������ʵ�崴����Ӧ�ĺ����ڵ�
    BinOpPriority["$"] =0;
    BinOpPriority["+"] =10;
    BinOpPriority["-"] =10;
    BinOpPriority["*"] =20;
    BinOpPriority["/"] =20;
    BinOpPriority["^"] =30;
}
```