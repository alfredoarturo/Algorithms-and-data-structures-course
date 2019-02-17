#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

void showstack(stack <int> gq)
{
    stack <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

char* InToPos(char *cad, int len){
	char *res = new char[len];
	int count = 0;
	stack <char>opr;
	for (int i = 0; i < len; ++i){
		if (cad[i] <= '9' && cad[i] >= '0'){
			res[count] = cad[i];
			++count;
		}
		if (cad[i] == ')'){
			res[count] = opr.top();
			opr.pop();
			++count;
		}
		if (cad[i] == '+' || cad[i] == '*' || cad[i] == '-')
			opr.push(cad[i]);
	}
	while (!opr.empty()){
		res[count] =  opr.top();
		opr.pop();
		++count;
	}
	res[count] = '\0';
	return res;
}

int calc(char *cad, int len){
	int prim, seg;
	stack <int>num;
	for (int i = 0; i < len; ++i){
		if (cad[i] == '+'){
			prim = num.top();
			num.pop();
			seg = num.top();
			num.pop();
			num.push(prim+seg);
			//showstack(num);
		}
		if (cad[i] == '-'){
			prim = num.top();
			num.pop();
			seg = num.top();
			num.pop();
			num.push(seg-prim);
			//showstack(num);
		}
		if (cad[i] == '*'){
			prim = num.top();
			num.pop();
			seg = num.top();
			num.pop();
			num.push(prim*seg);
			//showstack(num);
		}
		if (cad[i] <= '9' && cad[i] >= '0'){
			num.push((cad[i] - '0'));
			//showstack(num);
		}
	}
	//showstack(num);
	return num.top();
}

int main(int args, char *argv[]){
	//char *a = argv[1]; int N = strlen(a);
	char a[] = "((3+5)*(2*3))-3\0";
	cout << calc(InToPos(a, strlen(a)), strlen(InToPos(a, strlen(a))));
	return 0;
}
