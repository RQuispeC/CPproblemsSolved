#include <bits/stdc++.h>
using namespace std;


vector<int> camino(vector<vector<int> > &lista,int inicial){
	int n = lista.size(), t;
	queue<int> cola;
	vector<int> distancia(n,n);
	cola.push(inicial);
	distancia[inicial] = 0;
	while(!cola.empty()){
		t = cola.front();
		cola.pop();
		for (int i = 0; i < lista.size(); ++i){
			if (distancia[lista[t][i]]!=n){
				distancia[lista[t][i]] = distancia[t]+1;
				cola.push(lista[t][i]);
			}
		}
	}
	return distancia;
}

int mayor(vector<int> tamanos){
	int may = 0;
	for (int i = 0; i < tamanos.size(); ++i){
		cout << tamanos[i] << " ";
		if (may<tamanos[i]) may=tamanos[i];
	}
	cout << endl;
	return may;
}

int main(){
	int casos, a ,b, tamano;
	cin >> tamano >> casos;
	vector<vector<int> > lista(tamano);
	for (int i = 0; i < casos; ++i){
		cin >> a >> b;
		lista[a-1].push_back(b-1);
		lista[b-1].push_back(a-1);
	}
	/*
	for (int i = 0; i < lista.size(); ++i){
		cout << i << ": ";
		for (int j = 0; j < lista[i].size(); ++j){
			cout << lista[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int may = 0;
	for (int i = 0; i < casos; ++i){
		if (may<mayor(camino(lista,i))){
			may=mayor(camino(lista,i));
		}
	}
	cout << pow(2,may) << endl;

	return 0;
}