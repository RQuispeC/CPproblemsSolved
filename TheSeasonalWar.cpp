#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool visited[25][25];
vector<string> V;
int R;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

bool validate(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < R;
}

int dfs(int r, int c){
	visited[r][c] = 1;
	int cont  = 1;
	for(int i = 0; i < 8; i++){
		int nr = r + dy[i];
		int nc = c + dx[i];
		
		if(validate(nr,nc) &&  V[r][c] == V[nr][nc] && !visited[nr][nc])//verifica si es valido, si el que le sigue el igual y si ya todavia no ha sido visitado
		{
			cont += dfs(nr,nc);
		}
	}
	
	return cont;
}

int main(){
	int cases = 0;
	while(cin>>R){
	
		string s;
		cases++;
		memset(visited,0,sizeof(visited));
		V.clear();
		
		for(int i = 0; i < R; i++){
			string aux; 
			cin>>aux;
			V.push_back(aux);
		}
		vector< pair<char,int> > Ans;
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < R; j++){
				if(V[i][j] == '1'&& !visited[i][j]){
					Ans.push_back(make_pair(V[i][j],dfs(i,j)));
				}
			}
		}
		
		cout<<"Image number "<<cases<<" contains "<<Ans.size()<<" war eagles."<<endl;
	}
}
