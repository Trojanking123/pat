#include<iostream>
#include<queue>

using namespace std;

const int kMAX = 100;
const int X[] = {0, 0, 1, -1};
const int Y[] = {1, -1, 0, 0};

int m, n;
struct Node{
    int x,y;
}node;


int matric[kMAX][kMAX];
bool visited[kMAX][kMAX] = {false};

bool judge(int x, int y){
    if(x < 0 || x >=n || y <0 || y >= m) return false;
    if(visited[x][y] == true || matric[x][y] == 0) return false;
    return true;
}

void BFS(int x, int y){
    queue<Node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)){
                node.x = newX;
                node.y = newY;
                q.push(node);
                visited[newX][newY] = true;
            }
        }
    }

}


int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>matric[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matric[i][j] == 1 && visited[i][j] == false){
                ans++;
                BFS(i, j);
            }
        }
    }
    cout<<ans<<endl;



    return 0;
}

/*需求:对于一个只有0和1的二维矩阵,上下或者左右相邻元素都为1则为一块(斜着不算),求一共有多少取值为1的连续块.如下图:
 * 
0 1 0 1 1 0
1 1 0 0 1 1
0 0 1 0 0 0
1 1 0 0 0 0
 * 
 * 上图中有4块
 */
