#include <iostream>
#include <string>
#include <map>

using namespace  std;

int main(){
	map <string, string> tipo, a1, a2;
	map <string, string>::iterator it, aux, uno, dos;
	int N;
	string a, b;

	cin >> N;

	for (int i = 0; i < N; ++i){
		cin >> a >> b;
		if (b == "dominant" || b == "recessive" || b == "non-existent")
			tipo[a] = b;
		else{
			it = a1.find(b);
			if (it == a1.end())
				a1[b] = a;
			else
				a2[b] = a;
		}
	}
	while (a1.size() != 0){

		for (it = a1.begin(); it != a1.end(); ++it){
			aux = a2.find(it->first);
			if (aux == a2.end())
				continue;
			uno = tipo.find(it->second);
			dos = tipo.find(aux->second);
			if (uno == tipo.end() || dos == tipo.end())
				continue;
			if (uno->second == "dominant" && dos->second == "dominant")
				tipo[it->first] = "dominant";
			if (uno->second == "dominant" && dos->second == "recessive")
				tipo[it->first] = "dominant"; 
			if (dos->second == "dominant" && uno->second == "recessive")
				tipo[it->first] = "dominant";
			if ((uno->second == "non-existent" && dos->second == "non-existent") || (uno->second == "recessive" && dos->second == "non-existent") || (dos->second == "recessive" && uno->second == "non-existent"))
				tipo[it->first] = "non-existent";
			if ((uno->second == "recessive" && dos->second == "recessive") || (uno->second == "dominant" && dos->second == "non-existent") || (uno->second == "non-existent" && dos->second == "dominant"))
				tipo[it->first] = "recessive";
			a1.erase(it->first);
			a2.erase(aux->first);
		}
	}

	cout << "tipo: " << endl;
	for (it = tipo.begin(); it != tipo.end(); ++it)
		cout << it->first << " " << it->second << endl;
}