


/*
.岛屿
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

输入:
11110
11010
11000
00000

输出: 1	

输入:
11000
11000
00100
00011

输出: 3
*/


int ans = 0;


void getOneIsland(char** grid, int x, int y,int start_x,int start_y) {
	int i = 0;
	int j = 0;
	for (i = start_x; i < x; ) {
		for (j = start_y; j < y; ) {
			if (grid[i][j] == 1 && grid[i][j + 1] == 1) {
				j++;
			}
			else if (grid[i][j] == 1 && grid[i + 1][j] == 1) {
				i++;
			}
			else if (grid[i][j] == 1 && grid[i - 1][j] == 1) {
				i--;
			}
			else if (grid[i][j] == 1 && grid[i][j - 1] == 1) {
				j--;
			}
			grid[i][j] = -1;
		}
	}

}


int numIslands(char** grid, int x, int y){
	
	int i = 0; 
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (grid[i][j]==1) {
				getOneIsland(grid, x, y,i,j);
				ans++;
			}
		}
	}
	return ans;
}





