int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    int i = 0, j = 0, maxRow = 0, maxCol = 0, limit = 0, sum = 0, gridColNum = gridColSizes[0];
    int* rowSkyline = (int*)malloc(gridColNum * sizeof(int));
    int* colSkyline = (int*)malloc(gridRowSize * sizeof(int)); 
        
    for(i = 0; i < gridRowSize; i++){
        maxRow = grid[i][0];
        for(j = 1; j < gridColNum;j++){
            if(grid[i][j] > maxRow){
                maxRow = grid[i][j];
            }
        }
        colSkyline[i] = maxRow;
    }
    
    for(j = 0; j < gridColNum; j++){
        maxCol = grid[0][j];
        for(i = 1; i < gridRowSize; i++){
            if(grid[i][j] > maxCol){
                maxCol = grid[i][j];
            }
        }
        rowSkyline[j] = maxCol;
    }
    
    for(i = 0; i < gridRowSize; i++){
        for(j = 0; j < gridColNum; j++){
            limit = rowSkyline[j];
            if(limit > colSkyline[i]){
                limit = colSkyline[i];
            }
            sum += limit - grid[i][j];   
        }
    }
    
    free(colSkyline);
    free(rowSkyline);
    return sum;
    
}