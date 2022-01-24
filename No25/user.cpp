#define MAX_SIZE 1000

int maze[12][12];
int dist[10][10];
int dx[4] = {0 ,-1,0,1};
int dy[4] = { 1 ,0,-1,0 };
typedef struct exp {
    int x;
    int y;
}EXP;



void bfs_init(int map_size, int map[10][10]) {
    for (int i = 1; i <= map_size; i++) {
        for (int j = 1; j <= map_size; j++) {
            maze[i][j] = map[i-1][j-1];
            dist[i][j] = 0;
        }
    }
    for (int i = 0; i <= map_size+1; i++) {
        maze[i][0] = 1;
        maze[0][i] = 1;
        maze[map_size+1][i] = 1;
        maze[i][map_size+1] = 1;
    }
    
}
int bfs(int x1, int y1, int x2, int y2) {
    EXP queue[MAX_SIZE];
    int front = -1, rear = -1;
    queue[++rear].x = x1;
    queue[rear].y = y1;
    for (int i = 0; i <= 11; i++) {
        for (int j = 0; j <= 11; j++) {
            dist[i][j] = 0;
        }
    }

    while (front != rear) {
        front++;
        int curX = queue[front].x, curY = queue[front].y;
        
        for (int i = 0; i < 4; i++) {

            if (!dist[curY + dy[i]][curX + dx[i]] && !maze[curY + dy[i]][curX + dx[i]] ) {
                dist[curY + dy[i]][curX + dx[i]] = dist[curY][curX] + 1;
                
                if (curX + dx[i] == x2 && curY + dy[i] == y2) {
                    return dist[curY + dy[i]][curX + dx[i]];
                }
                queue[++rear].x = curX + dx[i];
                queue[rear].y = curY + dy[i];
                
            }
            
        }
    }

    return -1;
}
