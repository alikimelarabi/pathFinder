// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	//If the start location is equal to the ending location, then we've
	//	solved the maze, so return true.
	//	Mark the start location as visted.
	//	For each of the four directions,
	//	If the location one step in that direction(from the start
	//		location) is unvisited,
	//	then call pathExists starting from that location(and
	//		ending at the same ending location as in the
	//		current call).
	//	If that returned true,
	//	then return true.
	//	Return false.

	//  If the start location is equal to the ending location, then we've
	//	solved the maze, so return true.
	if (sr == er && sc == ec)
	{
		return true;
	}

	//	Mark the start location as visted.
	maze[sr][sc] = 'V';

	//	For each of the four directions,
	//	If the location one step in that direction(from the start
	//		location) is unvisited,
	//	then call pathExists starting from that location(and
	//		ending at the same ending location as in the
	//		current call).
	//	If that returned true,
	//	then return true.
	// Go down
	if (sr >= 0 && sc >= 0 && sr < nRows - 1 && sc < nCols)
	{
		if (maze[sr + 1][sc] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
			{
				return true;
			}
		}
	}
	// Go right
	if (sr >= 0 && sc >= 0 && sr < nRows && sc < nCols - 1)
	{
		if (maze[sr][sc + 1] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
			{
				return true;
			}
		}
	}
	// Go up
	if (sr >= 1 && sc >= 0 && sr < nRows && sc < nCols)
	{
		if (maze[sr - 1][sc] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
			{
				return true;
			}
		}
	}
	// Go left
	if (sr >= 0 && sc >= 1 && sr < nRows && sc < nCols)
	{
		if (maze[sr][sc - 1] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
			{
				return true;
			}
		}
	}

	return false;
}
